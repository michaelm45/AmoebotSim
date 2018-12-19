// Defines a simulator used as an interface between C++ and QML objects.

#ifndef AMOEBOTSIM_INTERFACE_SIMULATOR_H_
#define AMOEBOTSIM_INTERFACE_SIMULATOR_H_

#include <memory>

#include <QList>
#include <QObject>

#include "core/system.h"

class Simulator : public QObject {
  Q_OBJECT
  Q_PROPERTY(QList<QVariant> model READ getModel NOTIFY modelSignal)

 signals:
  void modelSignal();

 public:
  // Default constructor (currently creates a System shared pointer).
  Simulator();

  // Returns the list of all particle locations in the system in Cartesian
  // coordinates. Primarily used by QML rendering.
  QList<QVariant> getModel() const;

 private:
  std::shared_ptr<System> _system;
};

#endif  // AMOEBOTSIM_INTERFACE_SIMULATOR_H_
