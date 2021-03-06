#ifndef Angle_h_INCLUDED
#define Angle_h_INCLUDED

/* Angle.h
 * A representation of an angular measurement
 */

#include "PhysicsBase.h"

#include <Eigen/Core>

namespace physics {

  /**
   * \class Angle The geometry formed by two non-colinear, coplanar lines. 
   */
  class PHYSICSLIBRARY_API Angle : public PhysicsBase{
  public:
    /**
     * \brief Construct an Angle
     * 
     * \param _radians The measure of the angle in radians
     */
    explicit Angle(const double& _radians = 0) : PhysicsBase(_radians) { }  //? Becuase radians are "imaginary" units, maybe this should be implicit?
    Angle(const Angle&) = default;
    ~Angle() = default;

    double rad() const;
    double deg() const;

    explicit operator double();         //? Becuase radians are "imaginary" units, maybe this should be implicit?
  };

  Angle PHYSICSLIBRARY_API operator"" _deg(long double val);
  Angle PHYSICSLIBRARY_API operator"" _deg(unsigned long long val);

  Angle PHYSICSLIBRARY_API operator"" _rad(long double val);
  Angle PHYSICSLIBRARY_API operator"" _rad(unsigned long long val);
  
  Angle PHYSICSLIBRARY_API operator- (const Angle& rh);

  Angle PHYSICSLIBRARY_API operator+ (const Angle& lh, const Angle& rh);

  Angle PHYSICSLIBRARY_API operator- (const Angle& lh, const Angle& rh);

  Angle PHYSICSLIBRARY_API operator* (const Angle& lh, const double& n);
  Angle PHYSICSLIBRARY_API operator* (const double& n, const Angle& rh);

  Angle PHYSICSLIBRARY_API operator/ (const Angle& lh, const double& n);

  double PHYSICSLIBRARY_API sin(const Angle& a);
  double PHYSICSLIBRARY_API cos(const Angle& a);
  double PHYSICSLIBRARY_API tan(const Angle& a);

  Angle PHYSICSLIBRARY_API asin(const double& x);
  Angle PHYSICSLIBRARY_API acos(const double& x);
  Angle PHYSICSLIBRARY_API atan(const double& x);
  Angle PHYSICSLIBRARY_API atan2(const double& x, const double& y);

  inline Angle PHYSICSLIBRARY_API conj(const Angle& x) { return x; }
  inline Angle PHYSICSLIBRARY_API real(const Angle& x) { return x; }
  inline Angle PHYSICSLIBRARY_API imag(const Angle&) { return 0_rad; }

}; // namespace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Angle> : NumTraits<double> {
    typedef physics::Angle Real;
    typedef physics::Angle NonInteger;
    typedef physics::Angle Nested;

    enum {
      IsComplex = 0,
      IsInteger = 0,
      IsSigned = 1,
      RequireInitialization = 1,
      ReadCost = 1,
      AddCost = 3,
      MulCost = 3
    };
  };

};  // namespace Eigen

using physics::operator"" _rad;        using physics::operator"" _deg;

#endif
