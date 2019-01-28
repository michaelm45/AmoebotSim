#include <QVector3D>
#include <iostream>

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
    std::vector<double> headMarker = markerCalculation(p.globalHeadMarkDir(), head);
    std::vector<double> tailMarker = markerCalculation(p.globalTailMarkDir(), tail);

    renderingVec.push_back(QVariant({QVector3D(head.x, head.y, head.z),
                                     QVector3D(tail.x, tail.y, tail.z),
                                     QVector3D(headMarker[0], headMarker[1], headMarker[2]),
                                     QVector3D(tailMarker[0], tailMarker[1], tailMarker[2])
                                     }));

  }

  return renderingVec;
}
std::vector<double> Simulator::markerCalculation(int dir, Node marked) const{
  if(dir != -1){
    Node target = marked.nodeInDir(dir);
    return {.25 * (marked.x - target.x),
            .25 * (marked.y - target.y),
           .25 * (marked.z - target.z)};
  }
  else{
    return {0,0,0};
  }
}

