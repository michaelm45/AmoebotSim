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
  property real dX: (headLocation.x - tailLocation.x)
  property real dY: (headLocation.y - tailLocation.y)
  property real dZ: (headLocation.z - tailLocation.z)
  property real magnitude: Math.sqrt(dX*dX + dY*dY + dZ*dZ)

  Entity {
    CylinderMesh {
      id: mesh
      radius: .3
      length: magnitude
      rings: 2
      slices: 20
    }

    Transform {
      id: transform
      translation: Qt.vector3d((headLocation.x + tailLocation.x) / 2.0,
                               (headLocation.y + tailLocation.y) / 2.0,
                               (headLocation.z + tailLocation.z) / 2.0)

      property real xRot: Math.acos(dY / magnitude) * 180 / Math.PI
      property real yRot: Math.atan2(dX, dZ) * 180 / Math.PI
      rotation: fromAxesAndAngles(Qt.vector3d(1, 0, 0), xRot,
                                  Qt.vector3d(0, 1, 0), yRot)
    }

    PhongMaterial {
      id: material
    }

    components: [mesh, material, transform]
  }
}
