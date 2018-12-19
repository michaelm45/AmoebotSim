// TODO: copyright notice.

#include "interface/simulator.h"

Simulator::Simulator() {
  _system = std::make_shared<System>();
}

QList<QVariant> Simulator::getModel() const {
  return {QVariant({QVector3D(0,0,0), QVector3D(1,0,0)})};
}
