import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0
import Qt3D.Input 2.0
import QtQuick 2.6

Entity {
  signal cameraPan(var pan)
  signal cameraTilt(var tilt)

  property Camera subCam: Camera {
    id: compassCam
    projectionType: CameraLens.PerspectiveProjection
    fieldOfView: 20
    aspectRatio: 16/9
    nearPlane: 0.1
    farPlane: 500.0
    upVector: Qt.vector3d(0.0, 0.0, 1.0)
    viewCenter: Qt.vector3d(0,0,0)
    position: Qt.vector3d(0,-2,0)
  }

  onCameraPan: compassCam.panAboutViewCenter(pan)
  onCameraTilt: compassCam.tiltAboutViewCenter(tilt)

  OrbitCameraController {
    camera: camera
  }

  CylinderMesh {
    id: mesh
    radius: .015
    length: .25
    rings: 2
    slices: 10
  }

  Entity {
    id: xArm

    PhongMaterial {
      id: xmaterial
      ambient: 'blue'
    }

    Transform {
      id: xtransform
      translation: Qt.vector3d(.125,0,0)

      property real xRot: Math.acos(0 / mesh.length) * 180 / Math.PI
      property real yRot: Math.atan2(-1, 0) * 180 / Math.PI
      rotation: fromAxesAndAngles(Qt.vector3d(1, 0, 0), xRot,
                                  Qt.vector3d(0, 1, 0), yRot)
    }

    components: [mesh, xmaterial, xtransform]
  }

  Entity {
    id: yArm

    PhongMaterial {
      id: ymaterial
      ambient: 'green'
    }

    Transform {
      id: ytransform
      translation: Qt.vector3d(0,.125,0)

      property real xRot: Math.acos(-1) * 180 / Math.PI
      property real yRot: Math.atan2(0, 0) * 180 / Math.PI
      rotation: fromAxesAndAngles(Qt.vector3d(1, 0, 0), xRot,
                                  Qt.vector3d(0, 1, 0), yRot)
    }

    components: [mesh, ymaterial, ytransform]
  }

  Entity {
    id: zArm

  CylinderMesh {
    id: zmesh
    radius: .020
    length: .25
    rings: 2
    slices: 10
  }


  PhongMaterial {
    id: zmaterial
    ambient: 'red'
  }

  Transform {
    id: ztransform
    translation: Qt.vector3d(0,0,.125)

    property real xRot:  Math.acos(0 / mesh.length) * 180 / Math.PI
    property real yRot: Math.atan2(0, -1) * 180 / Math.PI
    rotation: fromAxesAndAngles(Qt.vector3d(1, 0, 0), xRot,
                                Qt.vector3d(0, 1, 0), yRot)
   }

   components: [mesh, zmaterial, ztransform]
  }

  components: [
    RenderSettings {
      activeFrameGraph: ForwardRenderer {
        camera: compassCam
        clearColor: Qt.rgba(0, 0.5, 1, 1)
      }
    },
    InputSettings {}
  ]
}
