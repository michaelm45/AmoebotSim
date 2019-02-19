#include <QVector3D>
#include <QColor>

#include "helper/conversion.h"
#include "interface/simulator.h"

Simulator::Simulator() {
  _system = std::make_shared<System>();
}

QList<QVariant> Simulator::getModel() const {
  QList<QVariant> renderingVec;
  std::vector<Particle> particles = _system->getParticles();

  // For each particle, its head and tail positions are pushed back onto list of
  // all particles' head and tail positions.
  for (Particle p : particles) {
    Node head = p.head;
    Node tail = p.tail();

    QVariant particle = QVariant({QVector3D(head.x, head.y, head.z),
                                  QVector3D(tail.x, tail.y, tail.z),
                                  QColor::fromRgb(Conversion::intToUInt(p.headMarkColor())),
                                  QColor::fromRgb(Conversion::intToUInt(p.tailMarkColor()))});

    renderingVec.push_back(particle);
  }

  return renderingVec;
}
