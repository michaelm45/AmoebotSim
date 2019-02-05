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
  int i =  latticePos[0];
  int j =  latticePos[1];
  int k =  latticePos[2];
  int layer = k % 2;

  double x = i + (j+layer)/2.0;
  double y = (3*j + layer)/sqrt(12);
  double z = k*sqrt(2.0/3);

  return {x, y, z};
}
