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
    position : Qt.vector3d(centerOfMass().x, minYPosition() - deltaY(),
                           centerOfMass().z)
    upVector : Qt.vector3d(0.0, 0.0, 1.0)
    viewCenter : centerOfMass()
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
    camera.position = Qt.vector3d(centerOfMass().x, minYPosition() - deltaY(),
                                  centerOfMass().z)
    camera.upVector = Qt.vector3d(0.0, 0.0, 1.0)
    camera.viewCenter = centerOfMass()
  }

  function centerOfMass() {
    var sumX = 0;
    var sumY = 0;
    var sumZ = 0;

    for (var i = 0; i < sim.model.length; i++) {
      // Calculates the sum of head and tail locations of all particles
      sumX = sim.model[i][0].x + sim.model[i][1].x
      sumY = sim.model[i][0].y + sim.model[i][1].y
      sumZ = sim.model[i][0].z + sim.model[i][1].z
    }

     // Returns the center of mass of all particles by taking average of sums.
     return Qt.vector3d(sumX / (2 * sim.model.length),
                        sumY / (2 * sim.model.length),
                        sumZ / (2 * sim.model.length))
  }

  function minYPosition() {
    var minYPos = Number.MAX_SAFE_INTEGER

    //Searches for the particle closest to the camera
    for (var i = 0; i < sim.model.length; i++) {
     if (Math.min(sim.model[i][0].y, sim.model[i][1].y)  < minYPos) {
        minYPos = Math.min(sim.model[i][0].y, sim.model[i][1].y)
      }
    }
    return minYPos
  }

  function deltaY() {
    return 40
  }
}

