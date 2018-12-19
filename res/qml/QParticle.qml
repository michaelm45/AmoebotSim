import Qt3D.Core 2.0
import QtQuick 2.6

Entity {
  id: particle
  property bool expand: model.modelData[0] !== model.modelData[1]

  Component.onCompleted: {
    var component = expand ? Qt.createComponent("QExpParticle.qml")
                           : Qt.createComponent("QConParticle.qml")
    if (component.status === Component.Ready){
      component.createObject(particle, {"properties": model.modelData})
    }
  }
}
