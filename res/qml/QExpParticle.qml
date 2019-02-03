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

  property double dX: (headLocation.x - tailLocation.x)
  property double dY: (headLocation.y - tailLocation.y)
  property double dZ: (headLocation.z - tailLocation.z)

  property double length: Math.sqrt(dX*dX + dY*dY + dZ*dZ)
  property double length_xy: Math.sqrt(dX*dX + dZ*dZ)

  property real yRot: Math.acos(dZ/length_xy) * 180 / Math.PI
  property real xRot: Math.acos(dY/length) * 180 / Math.PI

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

      rotation: fromAxesAndAngles(Qt.vector3d(1,0,0), xRot,
                                        Qt.vector3d(0, (dX<0)?-1:1, 0), yRot)

    }

    PhongMaterial {
      id: material
    }

    components: [mesh, material, transform]
  }
}
