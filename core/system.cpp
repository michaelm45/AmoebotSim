#include "core/system.h"

System::System() {
  _particles = {Particle(Node(0, 0, 0), -1), Particle(Node(0, 2, 0), 0),
                Particle(Node(1, 0, 1), 6), Particle(Node(0, -3, 0), -1),
                Particle(Node(3, -1, 0), 8)};
}

std::vector<Particle> System::getParticles() {
  return _particles;
}
