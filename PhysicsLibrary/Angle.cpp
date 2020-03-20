#include "pch.h"

#include "Angle.h"
#include "PhysicsMath.h"

namespace physics {
  
  Angle::Angle(const double& rads) :
    radians(rads) { }

  double Angle::rad() const {
    return radians;
  }

  double Angle::deg() const {
    return radians * 180 / pi;
  }

  Angle::operator double() { 
    return radians;
  }

  /* Literals operators
   * The following units are supported: 
   * radians, degrees
   */
  Angle operator""_deg(long double val) {
    return Angle(val * pi / 180);
  }

  Angle operator""_deg(unsigned long long val) {
    return Angle(val * pi / 180);
  }

  Angle operator""_rad(long double val) {
    return Angle(val);
  }

  Angle operator""_rad(unsigned long long val) {
    return Angle(val);
  }

};  // namespace physics
