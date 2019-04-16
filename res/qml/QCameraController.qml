import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0

Entity {
  id: controller
  property Camera camera
  property real deltaLook: 0.005
  property real deltaLinear: 0.001
  property real deltaZoom: 0.001
  property real linearSpeed: 100
  property real lookSpeed: 100
  property real zoomLimit: 4

  KeyboardDevice {
    id: keyboardinput
  }

  // Defines the movement controlled by the keyboard. Up/Down/Left/Right Arrows
  // translate the camera in the respective direction. Up (or) Down + Shift
  // tilts about the view center. Left (or) Right + Shift pans the camera
  // about the view center.
  KeyboardHandler {
    sourceDevice: keyboardinput
    focus: true
    onPressed: {
      if ((event.key === Qt.Key_Up) &&
              (event.modifiers & Qt.ShiftModifier)) {
        camera.tiltAboutViewCenter(deltaLook * lookSpeed * 10)
      }
      else if ((event.key === Qt.Key_Down) &&
               (event.modifiers & Qt.ShiftModifier)) {
        camera.tiltAboutViewCenter(-deltaLook * lookSpeed * 10)
      }
      else if ((event.key === Qt.Key_Right) &&
               (event.modifiers & Qt.ShiftModifier)) {
        camera.panAboutViewCenter(- deltaLook * lookSpeed * 10)
      }
      else if ((event.key === Qt.Key_Left) &&
               (event.modifiers & Qt.ShiftModifier)) {
        camera.panAboutViewCenter(deltaLook * lookSpeed * 10)
      }
      else if (event.key === Qt.Key_Up) {
        camera.translate(Qt.vector3d(0, 5 * deltaLinear * linearSpeed, 0))
      }
      else if (event.key === Qt.Key_Down) {
        camera.translate(Qt.vector3d(0, -5 * deltaLinear * linearSpeed, 0))
      }
      else if (event.key === Qt.Key_Right) {
        camera.translate(Qt.vector3d(5 * deltaLinear * linearSpeed, 0, 0))
      }
      else if (event.key === Qt.Key_Left) {
        camera.translate(Qt.vector3d(-5 * deltaLinear * linearSpeed, 0, 0))
      }
    }
  }

  MouseDevice {
    id: mouseDevice
    sensitivity: 0.001
  }

  // Defines the movement controlled by the mouse. Left click + drag translates
  // the camera. Right click + drag pans & tilts the camera about the view
  // center. Left & Right click + drag [or mouse wheel] zooms in/out
  MouseHandler {
    id: mouseHandle
    property point lastPosition;
    property real pan;
    property real tilt;
    sourceDevice: mouseDevice

    onPanChanged: camera.panAboutViewCenter(pan);
    onTiltChanged: camera.tiltAboutViewCenter(tilt);
    onPressed: { lastPosition = Qt.point(mouse.x, mouse.y); }
    onWheel: { zoom(wheel.angleDelta.y * deltaZoom * linearSpeed); }

    onPositionChanged: {
      if (mouse.buttons === 1) {
        var rx = -(mouse.x - lastPosition.x) * deltaLinear * linearSpeed;
        var ry = (mouse.y - lastPosition.y) * deltaLinear * linearSpeed;
        camera.translate(Qt.vector3d(rx, ry, 0))
      } else if (mouse.buttons === 2) {
        pan = -(mouse.x - lastPosition.x) * deltaLook * lookSpeed;
        tilt = (mouse.y - lastPosition.y) * deltaLook * lookSpeed;
      } else if (mouse.buttons === 3) {
        var zoomVal = (mouse.y - lastPosition.y) * deltaZoom * linearSpeed
        zoom(zoomVal)
      }

      lastPosition = Qt.point(mouse.x, mouse.y)
    }

    function zoom (zoomVal) {
      if (zoomVal > 0 &&
              zoomDistance(camera.position, camera.viewCenter) < zoomLimit) {
        return
      }

      camera.translate(Qt.vector3d(0, 0, zoomVal),
                       Camera.DontTranslateViewCenter)
    }

    function zoomDistance (cameraPos, viewCenterPos) {
      return viewCenterPos.minus(cameraPos).length()
    }
  }
}
