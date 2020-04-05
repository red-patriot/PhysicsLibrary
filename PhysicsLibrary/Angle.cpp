#include "pch.h"

#include "Angle.h"
#include "PhysicsMath.h"

namespace physics {

  double Angle::rad() const {
    return radians;
  }

  double Angle::deg() const {
    return radians * 180 / pi;
  }

  Angle::operator double() { 
    return radians;
  }

  Angle operator-(const Angle& rh) {
    return Angle(-rh.radians);
  }

  Angle operator+(const Angle& lh, const Angle& rh) {
    return Angle(lh.radians + rh.radians);
  }

  Angle operator-(const Angle& lh, const Angle& rh) {
    return Angle(lh.radians - rh.radians);
  }

  Angle operator*(const Angle& lh, const double& n) {
    return Angle(lh.radians * n);
  }

  Angle operator*(const double& n, const Angle& rh) {
    return rh * n;
  }

  Angle operator/(const Angle& lh, const double& n) {
    return Angle(lh.radians / n);
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
