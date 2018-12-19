import QtQuick.Scene3D 2.0

// Renders a 3D GUI scene for the particle system.
Scene3D {
  anchors.fill: parent
  focus: true
  aspects: ["input", "logic"]
  cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

  // Creates an entity that holds the particle system.
  QSimulator {}
}
