// Helper library of type conversion functions.

#ifndef AMOEBOTSIM_HELPER_CONVERSION_H_
#define AMOEBOTSIM_HELPER_CONVERSION_H_

#include <vector>

#include <QtGlobal>

class Conversion {
 public:
  static uint intToUInt(int i);
  static std::vector<double> cartesianPos(std::vector<int> latticePos);
};

#endif  // AMOEBOTSIM_HELPER_CONVERSION_H_
