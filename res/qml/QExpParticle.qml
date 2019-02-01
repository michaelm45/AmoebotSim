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

  // Calculating x,y,z rotation of cylinders
  property real zRot: (dY == 0) ? 0 : Math.atan(dX,dY) * 180 / Math.PI
  property real xRot: (dZ == 0) ? 0 : Math.atan(dY,dZ) * 180 / Math.PI
  property real yRot: (dX == 0) ? 0 : Math.atan(dZ,dX) * 180 / Math.PI

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

      rotationX: xRot
      rotationZ: zRot
      rotationY: yRot
    }

    PhongMaterial {
      id: material
    }

    components: [mesh, material, transform]
  }
}
