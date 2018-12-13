import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick.Layouts 1.11
import QtQuick.Window 2.2
import QtQuick.Scene3D 2.0
import QtQuick.Controls 2.0
import QtQuick 2.6

Entity {
    property var properties
    property vector3d location: properties[0]

    // defines the position of particle rendering
    Transform {
        id: sphereTransformer
        translation: location
    }

    // defines the metalic material
    PhongMaterial {
        id: material
    }

    // defines how the particle is rendered
    SphereMesh {
        id: sphereMesh
        slices: 60
        rings: 60
        radius: 0.65
    }
    // defines all the components of a particle
    components: [ sphereTransformer, sphereMesh, material ]


}
