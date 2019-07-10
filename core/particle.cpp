#include <stdlib.h>

#include "core/particle.h"
#include "helper/conversion.h"

Particle::Particle(const Node& head, int globalTailDir)
  : head(head),
    globalTailDir(globalTailDir) {
  Q_ASSERT(-1 <= globalTailDir && globalTailDir < 12);
}

Particle::~Particle() {}

bool Particle::isContracted() const {
  return globalTailDir == -1;
}

bool Particle::isExpanded() const {
  return !isContracted();
}

Node Particle::tail() const {
  Q_ASSERT(-1 <= globalTailDir && globalTailDir < 12);
  if (isContracted()) {
    return head;
  } else {
    return head.nodeInDir(Conversion::intToUInt(globalTailDir));
  }
}

int Particle::headMarkColor() const {
  int colors[]{0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF, 0xFFFFFF};
  return colors[rand() % 7];
}

int Particle::tailMarkColor() const {
  int colors[]{0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF, 0xFFFFFF};
  return colors[rand() % 7];
}

int Particle::globalHeadMarkDir() const {
  return -1;
}

int Particle::globalTailMarkDir() const {
  return -1;
}
