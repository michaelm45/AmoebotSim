import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Logic 2.0
import Qt3D.Extras 2.0
import Qt3D.Animation 2.9
import QtQuick.Scene2D 2.9
import QtQuick.Scene3D 2.0


Entity {

    property var modelListing: [Qt.vector3d(0,0,0), Qt.vector3d(1,1,1)]
    NodeInstantiator {
        id: nodes
        model : modelListing
        Particle {}
    }
}
