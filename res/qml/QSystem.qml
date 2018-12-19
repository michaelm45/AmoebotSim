import Qt3D.Core 2.0

Entity {
  property var modelListing

  // NodeInstantiator passes each piece of the model to each particle delegate
  NodeInstantiator {
    id: nodes
    model : modelListing
    delegate: QParticle {}
  }
}
