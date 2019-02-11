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
    Component.onCompleted: resetCameraPosition()
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
    camera.position = findCameraPosition()
    camera.upVector = Qt.vector3d(0.0, 1.0, 0.0)
    camera.viewCenter = centerOfMass(sim.model)
  }

  function centerOfMass(model) {
    var sumX = 0;
    var sumY = 0;
    var sumZ = 0;

    for (var i = 0; i < model.length; i++) {
      if(model[i][0] === model[i][1]) {
        sumX = model[i][0].
        sumY = model[i][0].y
        sumZ = model[i][0].z
      } else {
        // Calculates the sum of head and tail locations of all particles
        sumX = model[i][0].x + model[i][1].x
        sumY = model[i][0].y + model[i][1].y
        sumZ = model[i][0].z + model[i][1].z
      }

  }

     // Returns the center of mass of all particles by taking average of sums.
     return Qt.vector3d(sumX / (2 * model.length), sumY / (2 * model.length),
                        sumZ / (2 * model.length))
  }

  function findCameraPosition()  {
    var cameraLevel = camera.viewCenter
    var closestNodeZ = 0

    //Searches for the particle closest to the camera
    for (var i = 0; i < sim.model.length; i++) {

      if (sim.model[i][1].z < closestNodeZ) {
        closestNodeZ = sim.model[i][1].z
      }

    }

    //returns a camera position which is 50 units away from the closest particle
    cameraLevel.z = closestNodeZ - 40
    return cameraLevel
  }
}

