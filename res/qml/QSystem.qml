import Qt3D.Core 2.0
import QtQuick 2.12

Entity {
  property var modelParticles
  property var modelEdges

  signal inspectionText(string text)

  // NodeInstantiator passes each piece of the model to each particle delegate.
  NodeInstantiator {
    id: nodes
    model: modelListing
    delegate: QParticle {
      Component.onCompleted: { inspected.connect(inspectionText) }
    }
  }

  // edges passes each edge to be rendered to each QEdge delegate.
  NodeInstantiator {
    id: edges
    model: modelEdges
    delegate: QEdge {edges: model.modelData}
  }
}
