#include "core/particle.h"
#include "helper/conversion.h"

Particle::Particle(const Node& head, int globalTailDir)
  : head(head),
    globalTailDir(globalTailDir) {
  Q_ASSERT(-1 <= globalTailDir && globalTailDir < 12);
}

Particle::~Particle(){}

bool Particle::isContracted() const {
  return (globalTailDir == -1);
}

bool Particle::isExpanded() const {
  return !isContracted();
}

Node Particle::tail() const {
  Q_ASSERT(-1 <= globalTailDir && globalTailDir < 12);
  if(isContracted()){
    return head;
  }
  else {
    unsigned direction = Conversion::signed_to_unsignedInt(globalTailDir);
    return head.nodeInDir(direction);
  }
}

int Particle::headMarkColor() const {
  return -1;
}

int Particle::headMarkGlobalDir() const {
  return -1;
}

int Particle::tailMarkColor() const {
  return -1;
}

int Particle::tailMarkGlobalDir() const {
  return -1;
}

QString Particle::inspectionText() const {
  return "Overwrite Particle::inspectionText() to specify an inspection text.";
}
