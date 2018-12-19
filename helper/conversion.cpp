#include "helper/conversion.h"
#include <QDebug>

unsigned int Conversion::signed_to_unsignedInt(int sign){
  if (sign < 0){
    qDebug("Trying to convert negative signed int to unsigned int");
    return 0;
  }
  else {
    return static_cast<unsigned int>(sign);
  }
}
