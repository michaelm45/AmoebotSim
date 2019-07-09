#include <cmath>

#include <QDebug>

#include "helper/conversion.h"

uint Conversion::intToUInt(int i) {
  if (i < 0) {
    qDebug() << "Trying to convert negative signed int to unsigned int";
    return 0;
  } else {
    return static_cast<uint>(i);
  }
}

std::vector<double> Conversion::cartesianPos(std::vector<int> latticePos) {
  int i = latticePos[0];
  int j = latticePos[1];
  int k = latticePos[2];

  double x = i + j/2.0 + k/2.0;
  double y = sqrt(3.0)/2 * j - sqrt(3.0)/4 * k;
  double z = 3/4.0 * k;

  return {x, y, z};
}

QVector3D Conversion::vecToQVec3D(std::vector<double> vec) {
  Q_ASSERT(vec.size() == 3);
  return {static_cast<float>(vec[0]), static_cast<float>(vec[1]),
          static_cast<float>(vec[2])};
}
