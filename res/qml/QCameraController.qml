import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Logic 2.0
import QtQml 2.2
import QtQuick 2.0

Entity {
  id: controller
  property Camera camera
  property real delta: 0.001
  property real linearSpeed: 1
  property real lookSpeed: 500
  property real zoomLimit: 4

  MouseDevice {
    id: mouseDevice
    sensitivity: 0.001
  }

  MouseHandler {
    id: mouseHandle
    property vector3d upVect: Qt.vector3d(0.0, 0.0, 1.0)
    property point lastPosition;
    property real pan;
    property real tilt;
    sourceDevice: mouseDevice

    onPanChanged: controller.camera.panAboutViewCenter(pan, upVect);
    onTiltChanged: controller.camera.tiltAboutViewCenter(tilt);
    onPressed: { lastPosition = Qt.point(mouse.x, mouse.y); }
    onWheel: { zoom(wheel.angleDelta.y * delta * linearSpeed); }

    onPositionChanged: {
      if (mouse.buttons === 1) { // Left click for rotation
        pan = -(mouse.x - lastPosition.x) * delta * lookSpeed;
        tilt = (mouse.y - lastPosition.y) * delta * lookSpeed;
      } else if (mouse.buttons === 2) { // Right click for translate
        var rx = -(mouse.x - lastPosition.x) * delta * linearSpeed;
        var ry = (mouse.y - lastPosition.y) * delta * linearSpeed;
        camera.translate(Qt.vector3d(rx, ry, 0))
      } else if (mouse.buttons === 3) { // Left & Right click for zoom
        var zoomVal = (mouse.y - lastPosition.y) * delta * linearSpeed
        zoom(zoomVal)
      }

    lastPosition = Qt.point(mouse.x, mouse.y)
    }

    function zoom(zoomVal) {
      if (zoomVal > 0 &&
              zoomDistance(camera.position, camera.viewCenter) < zoomLimit) {
        return
      }

      camera.translate(Qt.vector3d(0, 0, zoomVal),
                       Camera.DontTranslateViewCenter)
    }

    function zoomDistance(cameraPos, viewCenterPos) {
      return viewCenterPos.minus(cameraPos).length()
    }
  }
}
