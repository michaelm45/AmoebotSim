#include "core/system.h"

System::System() {
  _particles = {Particle(Node(0,0,0), 0)};
}

std::vector<Particle> System::getParticles() {
  return _particles;
}
