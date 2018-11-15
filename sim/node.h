// Defines a class representing nodes on the triangular lattice. The x-axis runs
// left-right and the y-axis runs northeast-southwest.
// The neighbors of a node are numbered ascendingy in clockwise order: 0=E, 1=NE, 2=NW, 3=W, 4=SW, 5=SE

#ifndef AMOEBOTSIM_SIM_NODE_H
#define AMOEBOTSIM_SIM_NODE_H

#include <QtGlobal>

#include <array>

class Node {
 public:
  // Node constructors. The default constructor makes the origin node (0, 0),
  // the second constructs a node (x, y, z), and the third copies the input node.
  Node();
  Node(int x, int y, int z);
  Node(const Node& other);

  // Equality operators; == returns true if the two nodes are equal and != does
  // the opposite.
  bool operator==(const Node& other) const;
  bool operator!=(const Node& other) const;

  // Returns the node adjacent to this one in the given global direction. For
  // more information on global directions, see localparticle.h.
  Node nodeInDir(int dir) const;

  int x, y, z;
};

// Comparator between two nodes. First compares the nodes' x-coordinates and, in
// case of a tie, compares their y-coordinates.
bool operator<(const Node& v1, const Node& v2);


inline Node::Node()
  : x(0), y(0), z(0){}

inline Node::Node(int x, int y, int z)
  : x(x), y(y), z(z) {}

inline Node::Node(const Node& other)
  : x(other.x), y(other.y), z(other.z) {}

inline bool Node::operator==(const Node& other) const {
  return (x == other.x) && (y == other.y) && (z == other.z);
}

inline bool Node::operator!=(const Node& other) const {
  return !operator==(other);
}

inline Node Node::nodeInDir(int dir) const {
  Q_ASSERT(0 <= dir && dir <= 5);

  static constexpr std::array<int, 6> xOffset = {{1, 0, -1, -1,  0,  1}};
  static constexpr std::array<int, 6> yOffset = {{0, 1,  1,  0, -1, -1}};

  return Node(x + xOffset[dir], y + yOffset[dir]);
}

inline bool operator<(const Node& v1, const Node& v2) {
  return (v1.x < v2.x) || (v1.x == v2.x && v1.y < v2.y);
}

#endif  // AMOEBOTSIM_SIM_NODE_H
