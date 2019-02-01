import QtQuick 2.11
import QtQuick.Scene3D 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4

Item {
// Renders a 3D GUI scene for the particle system.
    Scene3D {
      anchors.fill: parent
      focus: true
      aspects: ["input", "logic"]
      cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

      // Creates an entity that holds the particle system.
      QSimulator {id: simulator}
    }

    //Row Layout to contain UI elements
    RowLayout {
          //Layout Properties
          width: parent.width
          anchors.fill: parent
          anchors.margins: 10

          Button {
              id: cameraResetButton
              text: "Reset Camera"
              anchors.top: parent.top
              anchors.left: parent.left
              onClicked: simulator.resetCameraPosition()
          }
    }
}
