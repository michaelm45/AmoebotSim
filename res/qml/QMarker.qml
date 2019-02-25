import Qt3D.Core 2.0
import Qt3D.Extras 2.0

Entity {
  property vector3d markDir
  property var color

  Transform {
    id: sphereTransformer
    translation: markDir
  }

  SphereMesh {
    id: sphereMesh
    slices: 60
    rings: 60
    radius: 0.35
  }

  PhongMaterial {
    ambient: color
    id: material
  }

  components: [sphereTransformer, sphereMesh, material]

}
