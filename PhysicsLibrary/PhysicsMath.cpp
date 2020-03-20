#include "pch.h"

#include <math.h>

#include "PhysicsMath.h"
#include "Angle.h"
#include "Length.h"
#include "Area.h"
#include "MomentOfArea.h"

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
    return ::sin(a.rad());
  }

  double cos(const Angle& a) {
    return ::cos(a.rad());
  }

  double tan(const Angle& a) {
    return ::tan(a.rad());
  }

  Angle asin(const double& x) {
    return Angle(::asin(x));
  }

  Angle acos(const double& x) {
    return Angle(::acos(x));
  }

  Angle atan(const double& x) {
    return Angle(::atan(x));
  }

  Angle atan2(const double& x, const double& y) {
    return Angle(::atan2(x, y));
  }

  Length sqrt(const Area& a) {
    return Length(::sqrt(a.meters2));
  }

  Area sqrt(const SecondMomentOfArea& a) {
    return Area(::sqrt(a.meters4));
  }

};
