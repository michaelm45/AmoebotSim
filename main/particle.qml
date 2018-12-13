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
    id: particle
    property bool expand: model.modelData[0] != model.modelData[1]

    Component.onCompleted: {
        var component = expand ? Qt.createComponent("Expanded.qml") : Qt.createComponent("Contracted.qml")
        if (component.status == Component.Ready){
            component.createObject(particle, {"properties": model.modelData})
        }
    }
}
