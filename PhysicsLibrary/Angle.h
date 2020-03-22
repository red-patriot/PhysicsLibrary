#ifndef Angle_h_INCLUDED
#define Angle_h_INCLUDED

/* Angle.h
 * A representation of an angular measurement
 */

#include "PhysicsExport.h"

namespace physics {

  class Angle;

  Angle PHYSICSLIBRARY_API operator"" _deg(long double val);
  Angle PHYSICSLIBRARY_API operator"" _deg(unsigned long long val);

  Angle PHYSICSLIBRARY_API operator"" _rad(long double val);
  Angle PHYSICSLIBRARY_API operator"" _rad(unsigned long long val);

  class PHYSICSLIBRARY_API Angle {
  public:
    explicit Angle(const double& rad);  //? Becuase radians are "imaginary" units, maybe this should be implicit?
    Angle(const Angle&) = default;
    ~Angle() = default;

    double rad() const;
    double deg() const;

    operator double();

  private:
    double radians;

    // Friends
    friend Angle PHYSICSLIBRARY_API operator- (const Angle& rh);

    friend Angle PHYSICSLIBRARY_API operator+ (const Angle& lh, const Angle& rh);

    friend Angle PHYSICSLIBRARY_API operator- (const Angle& lh, const Angle& rh);
    
    friend Angle PHYSICSLIBRARY_API operator* (const Angle& lh, const double& n);
    friend Angle PHYSICSLIBRARY_API operator* (const double& n, const Angle& rh);

    friend Angle PHYSICSLIBRARY_API operator/ (const Angle& lh, const double& n);

    friend Angle PHYSICSLIBRARY_API operator"" _deg(long double val);
    friend Angle PHYSICSLIBRARY_API operator"" _deg(unsigned long long val);

    friend Angle PHYSICSLIBRARY_API operator"" _rad(long double val);
    friend Angle PHYSICSLIBRARY_API operator"" _rad(unsigned long long val);

    friend double PHYSICSLIBRARY_API sin(const Angle& a);
    friend double PHYSICSLIBRARY_API cos(const Angle& a);
    friend double PHYSICSLIBRARY_API tan(const Angle& a);

    friend Angle PHYSICSLIBRARY_API asin(const double& x);
    friend Angle PHYSICSLIBRARY_API acos(const double& x);
    friend Angle PHYSICSLIBRARY_API atan(const double& x);
    friend Angle PHYSICSLIBRARY_API atan2(const double& x, const double& y);
  };

};  // namespace physics

using physics::operator"" _rad;        using physics::operator"" _deg;

#endif
