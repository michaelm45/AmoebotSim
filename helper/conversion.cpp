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

  double x = i + 1/2.0 * j + 1/2.0 * k;
  double y = sqrt(3.0)/2.0 * j - sqrt(3.0)/4 * k;
  double z = sqrt(6.0)/3 * k;

  return {x, y, z};
}
