#include <stdlib.h>
#include "core/system.h"

System::System() {
  _particles = randomizedInit();
}
std::vector<Particle> System::getParticles() {
  return _particles;
}
std::vector<Particle> System::randomizedInit() {
  srand (0);
  std::vector<Particle> sys;
  int size = rand() % 10 + 1;
  for(int i = 0; i < size; ++i) {
    int x = rand() % 5 - 2;
    int y = rand() % 5 - 2;
    int z = rand() % 5 - 2;
    int dir = rand() % 12;
    sys.push_back(Particle(Node(x, y, z), dir));
  }
  return sys;
}
