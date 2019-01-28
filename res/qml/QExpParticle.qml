import Qt3D.Core 2.0
import Qt3D.Extras 2.0
import QtQuick 2.6

Entity {
  property var properties
  property vector3d headLocation: properties[0]
  property vector3d tailLocation: properties[1]
  property vector3d headMark: properties[2]
  property vector3d tailMark: properties[3]


  // Render the head node.
  QConParticle {
    location: headLocation
    mark: headMark
  }

  // Render the tail node.
  QConParticle {
    location: tailLocation
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
    }

    PhongMaterial {
      id: material
    }

    components: [mesh, material, transform]
  }
}
