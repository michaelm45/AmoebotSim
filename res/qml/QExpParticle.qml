import Qt3D.Core 2.0
import Qt3D.Extras 2.0
import QtQuick 2.6

Entity {
  property var properties
  property vector3d head_location: properties[0]
  property vector3d tail_location: properties[1]

  QConParticle {
    id: head
    location: head_location
  }

  Entity {
    id: link

    CylinderMesh {
      id: mesh
      radius: .5
      length: 1
      rings: 100
      slices: 20
    }

    Transform {
      id: transform
      translation: Qt.vector3d((head_location.x + tail_location.x) / 2.0,
                               (head_location.y + tail_location.y) / 2.0,
                               (head_location.z + tail_location.z) / 2.0)
    }

    PhongMaterial {
      id: material
    }

    components: [ mesh, material, transform ]
  }

  QConParticle {
    id: tail
    location: tail_location
  }

}
