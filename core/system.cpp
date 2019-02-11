#include "core/system.h"

System::System() {
  _particles = {Particle(Node(0, -1, 1), 0), Particle(Node(0, -1, 1), 1),
                Particle(Node(0, -1, 1), 2), Particle(Node(0, -1, 1), 3),
                Particle(Node(0, -1, 1), 4), Particle(Node(0, -1, 1), 5),
                Particle(Node(0, -1, 1), 6), Particle(Node(0, -1, 1), 7),
                Particle(Node(0, -1, 1), 8), Particle(Node(0, -1, 1), 9),
                Particle(Node(0, -1, 1), 10), Particle(Node(0, -1, 1), 11),


               };
  /*
                Particle(Node(0, 0, 0), 6), Particle(Node(0, 0, 0), 7),
                Particle(Node(0, 0, 0), 8), Particle(Node(0, 0, 0), 9),
                Particle(Node(0, 0, 0), 10), Particle(Node(0, 0, 0), 11),
  */

}
std::vector<Particle> System::getParticles() {
  return _particles;
}
