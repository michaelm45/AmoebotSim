import Qt3D.Core 2.0
import Qt3D.Extras 2.0
import QtQuick 2.6

Entity {
  property var properties
  property vector3d headLocation: properties[0]
  property vector3d tailLocation: properties[1]
  property var headColor: properties[2]
  property var tailColor: properties[3]
  property vector3d headMark: properties[4]
  property vector3d tailMark: properties[5]

  property int dX: (headLocation.x - tailLocation.x)
  property int dY: (headLocation.y - tailLocation.y)
  property int dZ: (headLocation.z - tailLocation.z)

  property real yaw: Math.atan(dX/2,dY/2) * 180 / Math.PI
  property real pitch: Math.atan(dY/2,dZ/2) * 180 / Math.PI

  // Render the head node.
  QConParticle {
    location: headLocation
    color: headColor
    mark: headMark
  }

  // Render the tail node.
  QConParticle {
    location: tailLocation
    color: tailColor
    mark: tailMark
  }

  // Render the cylinder connecting the head and tail nodes.
  Entity {
    CylinderMesh {
      id: mesh
      radius: .5
      length: 1
      rings: 100
      slices: 20
    }

    Transform {
      id: transform
      translation: Qt.vector3d((headLocation.x + tailLocation.x) / 2.0,
                               (headLocation.y + tailLocation.y) / 2.0,
                               (headLocation.z + tailLocation.z) / 2.0)

      Component.onCompleted:  {
          console.log("pitch " + pitch)
          console.log("yaw " + yaw)
      }
      rotationZ: yaw
      rotationX: pitch
    }

    PhongMaterial {
      id: material
    }

    components: [mesh, material, transform]
  }
}
