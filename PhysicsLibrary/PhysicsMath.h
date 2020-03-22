#ifndef Physics_Math_h_INCLUDED
#define Physics_Math_h_INCLUDED

/* PhysicsMath.h
 * This file contains a number of mathematical functions to use in calculations for the
 *   physics library.
 */

#include "PhysicsExport.h"

 // Define some important mathematical constants
static const long double pi = 3.141592653589793238462643383279;

namespace physics {

  /*
   * Comparison functions
   * Because unit conversions can cause some small error in units, especially those that
   *   do not have exact conversions, and because of error in the binary representations
   *   of those that are exact, this library uses slightly fuzzy comparisons for its types.
   */

  bool PHYSICSLIBRARY_API fuzzy_equals(const double& lh, const double& rh);
  bool PHYSICSLIBRARY_API fuzzy_greater(const double& lh, const double& rh);
  bool PHYSICSLIBRARY_API approx(const double& lh, const double& rh);
 
  /*
   * Trigonometric functions
   * The trig and inverse trig functions for a physics::Angle
   */

  double PHYSICSLIBRARY_API sin(const class Angle& a);
  double PHYSICSLIBRARY_API cos(const class Angle& a);
  double PHYSICSLIBRARY_API tan(const class Angle& a);

  Angle PHYSICSLIBRARY_API asin(const double& x);
  Angle PHYSICSLIBRARY_API acos(const double& x);
  Angle PHYSICSLIBRARY_API atan(const double& x);
  Angle PHYSICSLIBRARY_API atan2(const double& x, const double& y);

  /* 
   * Misc functions
   * Miscellaneous math functions such as sqrt
   */

  class Length PHYSICSLIBRARY_API sqrt(const class Area& r);
  class Area PHYSICSLIBRARY_API sqrt(const class SecondMomentOfArea& r);
  class Pressure PHYSICSLIBRARY_API sqrt(const class Pressure2& r);

}; // namespace physics

#endif
