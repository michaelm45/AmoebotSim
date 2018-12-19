// TODO: copyright notice.

#include "interface/simulator.h"

Simulator::Simulator() {
  _system = std::make_shared<System>();
}

QList<QVariant> Simulator::getModel() const {
  QList<QVariant> rendering_vec;
  std::vector<Particle> sys = _system->getParticles();

  // For each particle, its head and tail positions are pushed back onto list of all particles'
  // head and tail positions.
  for (Particle p: sys){
      Node head = p.head;
      Node tail = p.tail();

      // TODO: write function to convert from Cartesian to lattice coordinates
      rendering_vec.push_back(QVariant({QVariant(QVector3D(head.x, head.y, head.z)),
                                       QVariant(QVector3D(tail.x, tail.y, tail.z))}));
  }
  return rendering_vec;

}
