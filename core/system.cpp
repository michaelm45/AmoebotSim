#include "core/system.h"

System::System() {
  _particles = {Particle(Node(0, 0, 0), -1),
                Particle(Node(1, 1, 1), 10),
                Particle(Node(2, 2, 2), 4),
                Particle(Node(3, 3, 3), 2),
                Particle(Node(4, 4, 4), -1)};
}

std::vector<Particle> System::getParticles() {
  return _particles;
}
