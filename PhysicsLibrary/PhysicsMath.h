#ifndef Physics_Math_h_INCLUDED
#define Physics_Math_h_INCLUDED

/* PhysicsMath.h
 * This file contains a number of mathematical functions to use in calculations for the
 *   physics library.
 */

#include "PhysicsBase.h"

 // Define some important mathematical constants
static const long double pi = 3.141592653589793238462643383279;

namespace physics {

  /*
   * Comparison functions
   * Because unit conversions can cause some small error in units, especially those that
   *   do not have exact conversions, and because of error in the binary representations
   *   of those that are exact, this library uses slightly fuzzy comparisons for its types.
   */

  inline bool PHYSICSLIBRARY_API fuzzy_equals(const double& lh, const double& rh);
  inline bool PHYSICSLIBRARY_API fuzzy_greater(const double& lh, const double& rh);
  inline bool PHYSICSLIBRARY_API approx(const double& lh, const double& rh);

  /*
   * Trigonometric functions
   * The trig and inverse trig functions for a physics::Angle
   */

  inline double PHYSICSLIBRARY_API sin(const class Angle& a);
  inline double PHYSICSLIBRARY_API cos(const class Angle& a);
  inline double PHYSICSLIBRARY_API tan(const class Angle& a);

  inline Angle PHYSICSLIBRARY_API asin(const double& x);
  inline Angle PHYSICSLIBRARY_API acos(const double& x);
  inline Angle PHYSICSLIBRARY_API atan(const double& x);
  inline Angle PHYSICSLIBRARY_API atan2(const double& x, const double& y);

  /*
   * Misc functions
   * Miscellaneous math functions such as sqrt
   */

  inline class Length PHYSICSLIBRARY_API sqrt(const class Area& r);
  inline class Area PHYSICSLIBRARY_API sqrt(const class SecondMomentOfArea& r);
  inline class Pressure PHYSICSLIBRARY_API sqrt(const class Pressure2& r);

  // TODO: This could probably be a single template
  inline class Time PHYSICSLIBRARY_API abs(const class Time& x);
  inline class Frequency PHYSICSLIBRARY_API abs(const class Frequency& x);
  inline class Mass PHYSICSLIBRARY_API abs(const class Mass& x);
  inline class Angle abs(const class Angle& x);
  inline class Length abs(const class Length& x);
  inline class Area abs(const class Area& x);
  inline class Volume PHYSICSLIBRARY_API abs(const class Volume& x);
  inline class SecondMomentOfArea PHYSICSLIBRARY_API abs(const class SecondMomentOfArea& x);
  inline class Force abs(const class Force& x);
  inline class Stiffness PHYSICSLIBRARY_API abs(const class Stiffness& x);
  inline class Damping PHYSICSLIBRARY_API abs(const class Damping& x);
  inline class Pressure PHYSICSLIBRARY_API abs(const class Pressure& x);
  inline class Velocity PHYSICSLIBRARY_API abs(const class Velocity& x);
  inline class Acceleration PHYSICSLIBRARY_API abs(const class Acceleration& x);

  inline class Area PHYSICSLIBRARY_API abs2(const class Length& x);
  inline class SecondMomentOfArea PHYSICSLIBRARY_API abs2(const class Area& x);
  inline class Pressure2 PHYSICSLIBRARY_API abs2(const class Pressure& x);

}; // namespace physics

#endif
