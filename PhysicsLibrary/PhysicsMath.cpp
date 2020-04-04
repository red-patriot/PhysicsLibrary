#include "pch.h"

#include <cmath>

#include "PhysicsMath.h"
#include "Physics.h"


namespace physics {

  // Fussy comparison operators
  bool fuzzy_equals(const double& lh, const double& rh) {
    /* Tests that the numbers differ by less than 100,000 times smaller than either of them. */
    return fabs(lh - rh) <= fabs((lh < rh ? lh : rh) * 0.000001);
  }
  bool fuzzy_greater(const double& lh, const double& rh) {
    /* Tests that lh is greater than rh by an accaptable margin of error. */
    return lh - rh > ((lh < rh ? lh : rh) * 0.000001);
  }

  bool approx(const double& lh, const double& rh) {
    /* This is a less-stringent version of fuzzy_equals, when the equality must be tested on an order of 1000. */
    return fabs(lh - rh) <= fabs((lh < rh ? lh : rh) * 0.0001);
  }

  double sin(const Angle& a) {
    return std::sin(a.rad());
  }

  double cos(const Angle& a) {
    return std::cos(a.rad());
  }

  double tan(const Angle& a) {
    return std::tan(a.rad());
  }

  Angle asin(const double& x) {
    return Angle(std::asin(x));
  }

  Angle acos(const double& x) {
    return Angle(std::acos(x));
  }

  Angle atan(const double& x) {
    return Angle(std::atan(x));
  }

  Angle atan2(const double& x, const double& y) {
    return Angle(std::atan2(x, y));
  }

  Length sqrt(const Area& r) {
    return Length(std::sqrt(r.meters2));
  }

  Area sqrt(const SecondMomentOfArea& r) {
    return Area(std::sqrt(r.meters4));
  }

  Pressure sqrt(const Pressure2& r) {
    return Pressure(std::sqrt(r.pascals2));
  }

};
