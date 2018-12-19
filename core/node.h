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
  // the second constructs a node (x, y), and the third copies the input node.
  Node();
  Node(int x, int y, int z);
  Node(const Node& other);

  // Equality operators; == returns true if the two nodes are equal and != does
  // the opposite.
  bool operator==(const Node& other) const;
  bool operator!=(const Node& other) const;
  Node nodeInDir(int dir) const;


  int x, y, z;
};

inline Node::Node()
  : x(0), y(0), z(0) {}

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
  // if particles is contracted, the head and tail are at the same position.
  if(dir == -1){ return Node(x, y, z); }

  static constexpr std::array<int, 12> xOffset = {{1,  1,  0,  -1,  -1,  0,  1,  0,  -1, -1,    0,   0}};
  static constexpr std::array<int, 12> yOffset = {{0, -1,  -1,  0,   1,  1,  0,  -1,  1,  0,   -1,   1}};
  static constexpr std::array<int, 12> zOffset = {{0,  0,  0,   0,   0,  0,  1,  1,   1,  -1,  -1,  -1}};

  return Node(x + xOffset[dir], y + yOffset[dir], z + zOffset[dir]);
}



#endif  // AMOEBOTSIM_SIM_NODE_H
