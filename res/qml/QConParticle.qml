import Qt3D.Core 2.0
import Qt3D.Extras 2.0

Entity {
  property var properties
  property vector3d location: properties[0]

  Transform {
    id: sphereTransformer
    translation: location
  }

  SphereMesh {
    id: sphereMesh
    slices: 60
    rings: 60
    radius: 0.65
  }

  PhongMaterial {
    id: material
  }

  components: [sphereTransformer, sphereMesh, material]
}
