import QtQuick 2.0
import QtQuick.Scene2D 2.9
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Rectangle {
    id: root
    focus: true


    RowLayout {
        id: collayout
        anchors.right: parent.right
        anchors.left: parent.left

        Slider {
            id: roundDurationSlider
            orientation: Qt.Horizontal
            Layout.fillWidth: true
            Layout.alignment: right
            minimumValue: 0
            maximumValue: 100
            stepSize: 1
            value: 50
        }
   }
}
