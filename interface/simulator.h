// Defines a simulator used as an interface between C++ and QML objects.

#ifndef AMOEBOTSIM_INTERFACE_SIMULATOR_H_
#define AMOEBOTSIM_INTERFACE_SIMULATOR_H_

#include <memory>

#include <QList>
#include <QObject>
#include <QString>
#include <QVector3D>

#include "core/system.h"

using namespace std;

class Simulator : public QObject {
  Q_OBJECT
  Q_PROPERTY(QList<QVariant> model READ getModel NOTIFY modelSignal)

 signals:
  void modelSignal();

 public:
  Simulator();

  // Function to return the vector of all particle locations in a system to QML
  // in face-centered cubic lattice coordinates.
  QList<QVariant> getModel() const;

 private:
  // Maintains a shared pointer to the system
  std::shared_ptr<System> _system;
};


#endif  // AMOEBOTSIM_INTERFACE_SIMULATOR_H_
