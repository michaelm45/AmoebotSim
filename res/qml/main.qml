import QtQuick 2.11
import QtQuick.Scene3D 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import Qt3D.Render 2.12

Item {
  // Renders a 3D GUI scene for the particle system.
  Scene3D {
    anchors.fill: parent
    focus: true
    aspects: ["input", "logic"]
    cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

    // Creates an entity that holds the particle system.
    QSimulator {
      id: simulator
      on_CameraPan: compass.subCam.panAboutViewCenter(_pan)
      on_CameraTilt: compass.subCam.tiltAboutViewCenter(_tilt)
    }
  }

  ColumnLayout {
    anchors.right: parent.right
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    anchors.margins: 10

    Button {
      id: cameraResetButton
      text: "Reset Camera"
      Layout.alignment: Qt.AlignRight | Qt.AlignBottom
      onClicked: simulator.resetCameraPosition()
    }
  }

  Scene3D {
    width: 200
    height: 200
    id: compassScene
    anchors.bottom: parent.bottom
    anchors.left: parent.left
    cameraAspectRatioMode: Scene3D.AutomaticAspectRatio
    aspects: ["input", "logic"]

    QCompass {
      id: compass
    }
  }
}
