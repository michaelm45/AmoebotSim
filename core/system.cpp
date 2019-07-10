#include "core/system.h"

System::System() {
  refreshSystem();
}

std::vector<Particle> System::getParticles() {
  return _particles;
}

void System::refreshSystem() {
  _particles.clear();
  srand (time(0));
  int n = 100;
  for (int i = 0; i< n; ++i) {
    int contract = (rand() % 2) - 1;
    int dir = (rand() % 12);
    dir = contract != -1 ? dir : -1;
    int x = (rand() % 30) - 15;
    int y = (rand() % 30) - 15;
    int z = (rand() % 30) - 15;
    _particles.push_back(Particle(Node(x, y, z), dir));
  }
}
