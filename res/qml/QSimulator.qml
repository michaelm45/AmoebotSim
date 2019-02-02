import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick 2.6

Entity {
  Camera {
    id: camera
    projectionType: CameraLens.PerspectiveProjection
    fieldOfView: 45
    aspectRatio: 16/9
    nearPlane : 0.1
    farPlane : 1000.0
    position: Qt.vector3d(0.0, 0.0, -40.0)
    upVector: Qt.vector3d(0.0, 1.0, 0.0)
    viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
  }

  OrbitCameraController {
    camera: camera
  }

  components: [
    RenderSettings {
      activeFrameGraph: ForwardRenderer {
        camera: camera
        clearColor: Qt.rgba(0, 0.5, 1, 1)
      }
    },
    InputSettings {}
  ]

  QSystem {
    id: systemLink
    modelListing: sim.model
  }

  function resetCameraPosition() {
    camera.position = Qt.vector3d(0.0, 0.0, -40.0)
    camera.viewCenter = Qt.vector3d(0.0, 0.0, 0.0)
    camera.upVector = Qt.vector3d(0.0, 1.0, 0.0)
  }
}

