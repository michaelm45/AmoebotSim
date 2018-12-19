// TODO: class comment.

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
  //pass the model as QVariant(QList<QList<QVariant(QList = {vec3d head, vec3d tail, color, etc.}) >>)

 signals:
  void modelSignal();

 public:
  // TODO: constructor documentation.
  Simulator();

  // TODO: documentation.
  QList<QVariant> getModel() const;

 private:
  std::shared_ptr<System> _system;
};

#endif  // AMOEBOTSIM_INTERFACE_SIMULATOR_H_
