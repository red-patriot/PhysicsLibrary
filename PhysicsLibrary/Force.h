#ifndef Force_h_INCLUDED
#define Force_h_INCLUDED

#include "PhysicsBase.h"

#include <Eigen/Core>

namespace physics {

  // Literal operators
  class Force PHYSICSLIBRARY_API operator"" _N(long double val);
  class Force PHYSICSLIBRARY_API operator"" _N(unsigned long long val);

  class Force PHYSICSLIBRARY_API operator"" _kN(long double val);
  class Force PHYSICSLIBRARY_API operator"" _kN(unsigned long long val);

  class Force PHYSICSLIBRARY_API operator"" _lbf(long double val);
  class Force PHYSICSLIBRARY_API operator"" _lbf(unsigned long long val);

  class Force PHYSICSLIBRARY_API operator"" _kips(long double val);
  class Force PHYSICSLIBRARY_API operator"" _kips(unsigned long long val);

  class PHYSICSLIBRARY_API Force : public PhysicsBase {
  public:
    explicit Force(double _newtons=0) : PhysicsBase(_newtons) { }
    Force(const Force&) = default;
    ~Force() = default;

    double N() const { return _value; }
    double kN() const { return _value * 0.001; }

    double lbf() const { return _value * 0.224808943099711; }
    double kips() const { return _value * 0.000224808943099711;  }

    Force& operator+= (const Force& rh) { _value += rh._value; return *this; }
    Force& operator-= (const Force& rh) { _value -= rh._value; return *this; }
    Force& operator*= (const double& rh) { _value *= rh; return *this; }
    Force& operator/= (const double& rh) {_value /= rh; return *this; }

  private:
    // Friends
    friend Force PHYSICSLIBRARY_API operator- (const Force& lh);

    friend Force PHYSICSLIBRARY_API operator+ (const Force& lh, const Force& rh);

    friend Force PHYSICSLIBRARY_API operator- (const Force& lh, const Force& rh);
    
    friend Force PHYSICSLIBRARY_API operator*(const class Pressure& lh, const class Area& rh);
    friend Force PHYSICSLIBRARY_API operator*(const class Area& lh, const class Pressure& rh);
    friend Force PHYSICSLIBRARY_API operator* (const Force& lh, const double& n);
    friend Force PHYSICSLIBRARY_API operator* (const double& n, const Force& rh);
    friend Force PHYSICSLIBRARY_API operator* (const class Stiffness& lh, const class Length& rh);
    friend Force PHYSICSLIBRARY_API operator* (const class Length& lh, const class Stiffness& rh);

    friend double PHYSICSLIBRARY_API operator/ (const Force& lh, const Force& rh);
    friend class Pressure PHYSICSLIBRARY_API operator/ (const Force& lh, const class Area& rh);   // defined in Pressure.cpp
    friend Force PHYSICSLIBRARY_API operator/ (const Force& lh, const double& n);
    friend class Stiffness PHYSICSLIBRARY_API operator/ (const Force& lh, const class Length& rh);

    friend bool PHYSICSLIBRARY_API operator== (const Force& lh, const Force& rh);
    friend bool PHYSICSLIBRARY_API operator> (const Force& lh, const Force& rh);
    friend bool PHYSICSLIBRARY_API operator!= (const Force& lh, const Force& rh);
    friend bool PHYSICSLIBRARY_API operator< (const Force& lh, const Force& rh);
    friend bool PHYSICSLIBRARY_API operator>= (const Force& lh, const Force& rh);
    friend bool PHYSICSLIBRARY_API operator<= (const Force& lh, const Force& rh);
  };

  inline Force PHYSICSLIBRARY_API conj(const Force& x) { return x; }
  inline Force PHYSICSLIBRARY_API real(const Force& x) { return x; }
  inline Force PHYSICSLIBRARY_API imag(const Force&) { return 0_N; }
  

}; // namespace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Force> : NumTraits<double> {
    typedef physics::Force Real;
    typedef physics::Force NonInteger;
    typedef physics::Force Nested;

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

using physics::operator""_N;        using physics::operator""_kN;
using physics::operator""_lbf;      using physics::operator""_kips;

#endif

