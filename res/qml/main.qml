import QtQuick.Scene3D 2.0

// Renders a 3D GUI scene for the particle system
// Creates entity that will hold particle system

Scene3D {
  anchors.fill: parent
  focus: true
  aspects: ["input", "logic"]
  cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

  QSimulator {}
}
