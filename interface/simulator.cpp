#include <QVector3D>

#include "helper/conversion.h"
#include "interface/simulator.h"

Simulator::Simulator() {
  _system = std::make_shared<System>();
}

QList<QVariant> Simulator::getModel() const {
  QList<QVariant> model;
  std::vector<Particle> particles = _system->getParticles();
  float expansionFactor = 2;

  // For each particle, its head and tail positions are pushed back onto list of
  // all particles' head and tail positions.
  for (Particle p : particles) {
    Node head = p.head;
    Node tail = p.tail();
    std::vector<double> headMarker = markerCalculation(p.globalHeadMarkDir(),
                                                       head);
    std::vector<double> tailMarker = markerCalculation(p.globalTailMarkDir(),
                                                       tail);

    std::vector<double> headPos = Conversion::cartesianPos({head.x, head.y,
                                                            head.z});
    std::vector<double> tailPos = Conversion::cartesianPos({tail.x, tail.y,
                                                            tail.z});

    QVector3D headCoor(float(headPos.at(0)), float(headPos.at(1)),
                       float(headPos.at(2)));

    QVector3D tailCoor(float(tailPos.at(0)), float(tailPos.at(1)),
                       float(tailPos.at(2)));

    QVector3D markHCoor(float(headMarker.at(0)), float(headMarker.at(1)),
                        float(headMarker.at(2)));

    QVector3D markTCoor(float(tailMarker.at(0)), float(tailMarker.at(1)),
                        float(tailMarker.at(2)));

    model.push_back(QVariant({expansionFactor * headCoor,
                              expansionFactor * tailCoor,
                              expansionFactor * markHCoor,
                              expansionFactor * markTCoor}));
  }

  return model;
}
std::vector<double> Simulator::markerCalculation(int dir, Node marked) const{
  if(dir != -1){
    Node target = marked.nodeInDir(Conversion::intToUInt(dir));
    static double separationFactor = 0.25;
    std::vector<double> cartPos = Conversion::cartesianPos({target.x,
                                                            target.y,
                                                            target.z});

    std::vector<double> nodePos = Conversion::cartesianPos({marked.x,
                                                            marked.y,
                                                            marked.z});

    std::vector<double> delta = {cartPos.at(0) - nodePos.at(0),
                                 cartPos.at(1) - nodePos.at(1),
                                 cartPos.at(2) - nodePos.at(2)};

    return {separationFactor * delta.at(0),
            separationFactor * delta.at(1),
            separationFactor * delta.at(2)};
  }
  else{
    return {0,0,0};
  }
}

