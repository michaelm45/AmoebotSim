#include <QColor>
#include <QVector3D>

#include "helper/conversion.h"
#include "helper/utility.h"
#include "interface/simulator.h"

Simulator::Simulator() {
  _system = std::make_shared<System>();

  // TODO: Remove after systemChanged() is integrated.
  std::function<void(void)> f(std::bind(&Simulator::callSystemChanged, this));
  doPeriodically(f, 3000);
}

// TODO: Remove after systemChanged() is integrated.
void Simulator::doPeriodically(std::function<void(void)> f, uint period) {
  std::thread([f, period]() {
    while (true) {
      f();
      std::this_thread::sleep_for(std::chrono::milliseconds(period));
    }
  }).detach();
}

// TODO: Remove after systemChanged() is integrated.
void Simulator::callSystemChanged() {
  systemChanged();
  qDebug() << "system changed!";
}

QList<QVariant> Simulator::getParticleSys() const {
  QList<QVariant> model;
  std::vector<Particle> particles = _system->getParticles();

  // For each particle, its head and tail positions are pushed back onto list of
  // all particles' head and tail positions.
  for (Particle p : particles) {
    Node head = p.head;
    Node tail = p.tail();

    std::vector<double> headPos
        = Conversion::cartesianPos({head.x, head.y, head.z});
    std::vector<double> tailPos
        = Conversion::cartesianPos({tail.x, tail.y, tail.z});

    QColor headColor =
        QColor::fromRgb(Conversion::intToUInt(p.headMarkColor()));
    QColor tailColor =
        QColor::fromRgb(Conversion::intToUInt(p.tailMarkColor()));

    std::vector<double> headMarkerPos =
        markerPosInDir(head, p.globalHeadMarkDir());
    std::vector<double> tailMarkerPos =
        markerPosInDir(tail, p.globalTailMarkDir());

    QVariant particle
        = QVariant({separation * Conversion::vectToQVect(headPos),
                    separation * Conversion::vectToQVect(tailPos),
                    headColor, tailColor,
                    separation * Conversion::vectToQVect(headMarkerPos),
                    separation * Conversion::vectToQVect(tailMarkerPos),
                    p.inspectionText()});

    model.push_back(QVariant(particle));
  }

  return model;
}

std::vector<double> Simulator::markerPosInDir(Node marked, int dir) const {
  if (dir != -1) {
    Node target = marked.nodeInDir(Conversion::intToUInt(dir));
    std::vector<double> targetPos
        = Conversion::cartesianPos({target.x, target.y, target.z});
    std::vector<double> nodePos
        = Conversion::cartesianPos({marked.x, marked.y, marked.z});

    double offset = 0.25;
    return {offset * (targetPos[0] - nodePos[0]),
            offset * (targetPos[1] - nodePos[1]),
            offset * (targetPos[2] - nodePos[2])};
  } else {
    return {0,0,0};
  }
}

QList<QVariant> Simulator::getEdges() const {
  QList<QVariant> edges;
  std::vector<Particle> particles = _system->getParticles();
  for (Particle p: particles) {
    std::vector<double> head =
        Conversion::cartesianPos({p.head.x, p.head.y, p.head.z});
    std::vector<double> tail =
        Conversion::cartesianPos({p.tail().x, p.tail().y, p.tail().z});

/* Some of following functions have not been implemented yet but will be
 * once AmoebotParticle is finished. I provide the more efficient code in
 * comments in order to ensure the program compiles.
 *
 * for (int dir = 0; dir < 12; ++dir) {
 *   if (p.hasNbrAtLabel(dir)) {
 *     Particle q = p.nbrAtLabel(dir);
 *     ...
 *   }
 * }
*/
    for (Particle q: particles) {
      std::vector<double> qHead =
          Conversion::cartesianPos({q.head.x, q.head.y, q.head.z});
      std::vector<double> qTail =
          Conversion::cartesianPos({q.tail().x, q.tail().y, q.tail().z});

      if (Utility::distance3D(head, qHead) <= 1) {
        edges.push_back(
              QVariant({separation * Conversion::vectToQVect3D(head),
                        separation * Conversion::vectToQVect3D(qHead)}));
      }
      if (Utility::distance3D(head, qTail) <= 1) {
        edges.push_back(
              QVariant({separation * Conversion::vectToQVect3D(head),
                        separation * Conversion::vectToQVect3D(qTail)}));
      }
      if (Utility::distance3D(tail, qHead) <= 1) {
        edges.push_back(
              QVariant({separation * Conversion::vectToQVect3D(tail),
                        separation * Conversion::vectToQVect3D(qHead)}));
      }
      if (Utility::distance3D(tail, qTail) <= 1) {
        edges.push_back(
              QVariant({separation * Conversion::vectToQVect3D(tail),
                        separation * Conversion::vectToQVect3D(qTail)}));
      }
    }
  }

  return edges;
}


