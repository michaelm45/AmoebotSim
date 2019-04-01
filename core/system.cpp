#include "core/system.h"

System::System() {
  for (int i = 0; i< 12; ++i) {
    _particles.push_back(Particle(Node(0, 0, 0), i));
  }
}

std::vector<Particle> System::getParticles() {
  return _particles;
}
