// Helper library of type conversion functions.

#ifndef AMOEBOTSIM_HELPER_CONVERSION_H_
#define AMOEBOTSIM_HELPER_CONVERSION_H_

#include <vector>

#include <QtGlobal>
#include <QVector3D>

class Conversion {
 public:
  // Function takes in an int. Warns if int is less than zero. Returns uint.
  static uint intToUInt(int i);

  // Function takes in lattice coordinates and maps to Cartesian space.
  static std::vector<double> cartesianPos(std::vector<int> latticePos);

  // Function takes in vector of doubles. Forces vector to have size of 3.
  // Returns QVector3D with float positions.
  static QVector3D vectToQVect(std::vector<double> vect);

  // Function takes in two vectors of ints. Forces vector to have size of 3.
  // Returns distance between two 3D points.
  static double distance(std::vector<double> p1, std::vector<double> p2);
};

#endif  // AMOEBOTSIM_HELPER_CONVERSION_H_
