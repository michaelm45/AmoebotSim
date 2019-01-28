import Qt3D.Core 2.0
import Qt3D.Extras 2.0

Entity {
  property vector3d markDir

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
    ambient: 'red'
    id: material
  }

  components: [sphereTransformer, sphereMesh, material]

}
