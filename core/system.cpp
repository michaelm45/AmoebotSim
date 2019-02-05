#include "core/system.h"

System::System() {
  _particles = {Particle(Node(0, 0, 0), 0), Particle(Node(0, 0, 0), 1),
                Particle(Node(0, 0, 0), 2), Particle(Node(0, 0, 0), 3),
                Particle(Node(0, 0, 0), 4), Particle(Node(0, 0, 0), 5),
                Particle(Node(0, 0, 0), 6), Particle(Node(0, 0, 0), 7),
                Particle(Node(0, 0, 0), 8), Particle(Node(0, 0, 0), 9),
                Particle(Node(0, 0, 0), 10), Particle(Node(0, 0, 0), 11)


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
