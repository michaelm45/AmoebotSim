#ifndef AMOEBOTSIM_CORE_LOCALPARTICLE_H
#define AMOEBOTSIM_CORE_LOCALPARTICLE_H

#include "core/node.h"
#include "core/particle.h"

class LocalParticle : public Particle {
 public:
  // Constructs a new particle with a node position for its head, a global
  // compass direction from its head to its tail (-1 if contracted), and an
  // offset for its local compass.
  LocalParticle(const Node& head, int globalTailDir, const int orientation);

  // Returns the local direction of the tail relative to the head, (-1 if
  // contracted)
  int tailDir() const;

  // Functions for converting port (edge) labels to local directions. labelToDir
  // returns the local direction the edge with the given label points to.
  // labelToDirAfterExpansion returns the local direction the edge with the
  // given label would point to after an expansion in the given local direction.
  int labelToDir(int label) const;
  int labelToDirAfterExpansion(int label, int expansionDir) const;

  // Functions for accessing labels specifically indicent to the head or tail.
  // headLabels (respectively, tailLabels) returns a vector of labels of edges
  // incident to the particle's head (respectively, tail). isHeadLabel (resp.,
  // isTailLabel) checks whether the given label is a head (resp., tail) label.
  // dirToHeadLabel (resp., dirToTailLabel) returns the head (resp., tail) label
  // of the edge pointing in the given local direction. These conversions will
  // fail on an expanded particle if dirToHeadLabel (resp., dirToTailLabel) is
  // called with the local direction from head to tail (resp., tail to head), as
  // the edge connecting the head and tail is not labelled. headContractionLabel
  // (resp., tailContractionLabel) returns the label needed to perform a head
  // (resp., tail) contraction.
  std::vector<int> headLabels() const;
  std::vector<int> tailLabels() const;
  bool isHeadLabel(int label) const;
  bool isTailLabel(int label) const;
  int dirToHeadLabel(int dir) const;
  int dirToTailLabel(int dir) const;

  // Functions analogous to their non -AfterExpansion versions above, but return
  // values as if the particle first expanded in the given local direction
  std::vector<int> headLabelsAfterExpansion(int expansionDir) const;
  std::vector<int> tailLabelsAfterExpansion(int expansionDir) const;
  bool isHeadLabelAfterExpansion(int label, int expansionDir) const;
  bool isTailLabelAfterExpansion(int label, int expansionDir) const;
  int dirToHeadLabelAfterExpansion(int dir, int expansionDir) const;
  int dirToTailLabelAfterExpansion(int dir, int expansionDir) const;

  // labelToGlobalDir returns the global direction the edge with the given label
  // points to. labelOfNbrNodeInGlobalDir returns the label of the edge that
  // connects the particle to given node (fails if the specified node is not in
  // the particle's neighborhood).
  int labelToGlobalDir(int label) const;
  int labelOfNbrNodeInGlobalDir(const Node& node, int globalDir) const;

  // occupiedNodeIncidentToLabel returns the head node if the given label is a
  // head label and the tail node otherwise. nbrNodeReachedViaLabel returns the
  // node reached from the particle by the edge with the given label.
  Node occupiedNodeIncidentToLabel(int label) const;
  Node nbrNodeReachedViaLabel(int label) const;

  // Functions for converting between local and global compass directions.
  int localToGlobalDir(int localDir) const;
  int globalToLocalDir(int globalDir) const;

  // Functions for converting between neighboring particles' local compasses.
  // nbrDirToDir returns the local direction from this particle's compass which
  // points in the same global direction as the given local direction from the
  // neighbor's compass. dirToNbrDir returns the local direction from the
  // neighbor's compass which points in the same global direction as the given
  // local direction from this particle's compass.
  int nbrDirToDir(const LocalParticle& nbr, int nbrDir) const;
  int dirToNbrDir(const LocalParticle& nbr, int myDir) const;

  // Functions for determining if a neighbor's label refers to an edge incident
  // to this particle. pointsAtMe checks if the labelled edge is incident
  // anywhere on this particle, whereas pointsAtMyHead (resp., pointsAtMyTail)
  // checks if the labelled edge is incident specifically to this particle's
  // head (resp., tail).
  bool pointsAtMe(const LocalParticle& nbr, int nbrLabel) const;
  bool pointsAtMyHead(const LocalParticle& nbr, int nbrLabel) const;
  bool pointsAtMyTail(const LocalParticle& nbr, int nbrLabel) const;

  const int orientation; // Offset from global direction for local compass.

  // Function to return local labeling scheme based on orientation.
  std::vector<int> labelMapping(std::vector<int> basisVector) const;

  // Function to calculate opposite labels in contracted and expanded particles,
  int oppositeLabel(int label) const;

  // Function to calculate opposite directions.
  int oppositeDir(int dir) const;

  // Function to map local expansionDirections in different lattices to the correct
  // local label.
  int mappedExpansion(int expandDir) const;

  // Function to map a local label to global labeling scheme.
  int mappedLabel(int label) const;

  // Function
  int mappedDir(int dir) const;

  std::vector<int> sharedLabels(std::vector<int> adjacentLabels) const;
  std::vector<int> adjacentLabels(std::vector<int> basisVector) const;

  // Only works with the head
  std::vector<int> surroundLabels(std::vector<int> adjacentLabels) const;

 private:
  static const std::vector<int> twelveLabels;
  static const std::array<const std::vector<int>, 12> labels;
  static const std::array<int, 12> contractLabels;
  static const std::array<std::array<int, 18>, 10> labelDir;
  static const std::vector<std::vector<int>> latticeDir;
  static const std::vector<std::vector<std::vector<int>>> latticeMappings;
  static const std::vector<std::vector<int>> expandLabel;
  static const std::vector<std::vector<int>> expandDir;
  static const std::vector<std::vector<int>> adjacentLabels;

};
#endif // AMOEBOTSIM_CORE_LOCALPARTICLE_H
