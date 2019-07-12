#include <QVector3D>
#include <QColor>

#include "helper/conversion.h"
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

QList<QVariant> Simulator::getModel() const {
  QList<QVariant> model;
  std::vector<Particle> particles = _system->getParticles();
  float separation = 2;

  // For each particle, its head and tail positions are pushed back onto list of
  // all particles' head and tail positions.
  for (Particle p : particles) {
    Node head = p.head;
    Node tail = p.tail();

    std::vector<double> headPos
        = Conversion::cartesianPos({head.x, head.y, head.z});
    std::vector<double> tailPos
        = Conversion::cartesianPos({tail.x, tail.y, tail.z});

    QColor headColor
        = QColor::fromRgb(Conversion::intToUInt(p.headMarkColor()));
    QColor tailColor
        = QColor::fromRgb(Conversion::intToUInt(p.tailMarkColor()));

    std::vector<double> headMarkerPos
        = markerPosInDir(head, p.globalHeadMarkDir());
    std::vector<double> tailMarkerPos
        = markerPosInDir(tail, p.globalTailMarkDir());

    QVariant particle
        = QVariant({separation * Conversion::vectToQVect(headPos),
                    separation * Conversion::vectToQVect(tailPos),
                    headColor, tailColor,
                    separation * Conversion::vectToQVect(headMarkerPos),
                    separation * Conversion::vectToQVect(tailMarkerPos)});

    model.push_back(particle);
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

