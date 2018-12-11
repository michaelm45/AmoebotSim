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

    Transform {
        id: sphereTransformer
        translation: Qt.vector3d(0, 0, 0)
    }

    PhongMaterial {
        id: material
    }

    SphereMesh {
        id: sphereMesh
        slices: 60
        rings: 60
        radius: 0.65
    }
    components: [ sphereTransformer, sphereMesh, material ]

}
