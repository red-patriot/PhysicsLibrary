#ifndef Area_h_INCLUDED
#define Area_h_INCLUDED

#include "PhysicsBase.h"

#include <Eigen/Core>

namespace physics {

  class SecondMomentOfArea;
  class Volume;
  class Area;
  class Length;

  // Literal operators
  Area PHYSICSLIBRARY_API operator"" _mm2(long double val);
  Area PHYSICSLIBRARY_API operator"" _mm2(unsigned long long val);

  Area PHYSICSLIBRARY_API operator"" _cm2(long double val);
  Area PHYSICSLIBRARY_API operator"" _cm2(unsigned long long val);

  Area PHYSICSLIBRARY_API operator"" _m2(long double val);
  Area PHYSICSLIBRARY_API operator"" _m2(unsigned long long val);

  Area PHYSICSLIBRARY_API operator"" _in2(long double val);
  Area PHYSICSLIBRARY_API operator"" _in2(unsigned long long val);

  Area PHYSICSLIBRARY_API operator"" _ft2(long double val);
  Area PHYSICSLIBRARY_API operator"" _ft2(unsigned long long val);

  class PHYSICSLIBRARY_API Area : public PhysicsBase {
  public:
    explicit Area(const double _meters2 = 0) : PhysicsBase(_meters2) { }
    Area(const Area&) = default;
    ~Area() = default;

    double mm2() const { return _value * 1'000'000; }
    double cm2() const { return _value * 10'000; }
    double m2() const { return _value; }

    double in2() const { return _value * 10'000/(6.4516); }
    double ft2() const { return _value * 10'000/(929.0304); }

    Area& operator+= (const Area& rh) { _value += rh._value; return *this; }
    Area& operator-= (const Area& rh) { _value -= rh._value; return *this; }
    Area& operator*= (const double& rh) { _value *= rh; return *this; }
    Area& operator/= (const double& rh) { _value /= rh; return *this; }

  private:
    // Friends
    friend Area PHYSICSLIBRARY_API operator- (const Area& lh);

    friend Area PHYSICSLIBRARY_API operator+ (const Area& lh, const Area& rh);

    friend Area PHYSICSLIBRARY_API operator- (const Area& lh, const Area& rh);

    friend Area PHYSICSLIBRARY_API operator* (const Length& lh, const Length& rh);
    friend Area PHYSICSLIBRARY_API operator* (const Area& lh, const double& n);
    friend Area PHYSICSLIBRARY_API operator* (const double& n, const Area& rh);
    friend Volume PHYSICSLIBRARY_API operator* (const Area& lh, const Length& rh);            // defined in Volume.cpp
    friend Volume PHYSICSLIBRARY_API operator* (const Length& lh, const Area& rh);            // defined in Volume.cpp
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator* (const Area& lh, const Area& rh);  // defined in MomentOfArea.cpp
    friend class Force PHYSICSLIBRARY_API operator*(const class Pressure& lh, const Area& rh);// defined in Force.cpp
    friend class Force PHYSICSLIBRARY_API operator*(const Area& lh, const class Pressure& rh);// defined in Force.cpp

    friend Area PHYSICSLIBRARY_API operator/ (const Volume& lh, const Length& rh);
    friend Area PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, const Area& rh);
    friend Length PHYSICSLIBRARY_API operator/ (const Volume& lh, const Area& rh);            // defined in Length.cpp
    friend Length PHYSICSLIBRARY_API operator/ (const Area& lh, const Length& rh);            // defined in Length.cpp
    friend double PHYSICSLIBRARY_API operator/ (const Area& lh, const Area& rh);
    friend Area PHYSICSLIBRARY_API operator/ (const Area& lh, const double& n);
    friend class Pressure PHYSICSLIBRARY_API operator/ (const class Force& lh, 
                                                        const Area& rh);                      // defined in Pressure.cpp

    friend bool PHYSICSLIBRARY_API operator== (const Area& lh, const Area& rh);
    friend bool PHYSICSLIBRARY_API operator> (const Area& lh, const Area& rh);
    friend bool PHYSICSLIBRARY_API operator!= (const Area& lh, const Area& rh);
    friend bool PHYSICSLIBRARY_API operator< (const Area& lh, const Area& rh);
    friend bool PHYSICSLIBRARY_API operator>= (const Area& lh, const Area& rh);
    friend bool PHYSICSLIBRARY_API operator<= (const Area& lh, const Area& rh);
  };

  inline Area PHYSICSLIBRARY_API conj(const Area& x) { return x; }
  inline Area PHYSICSLIBRARY_API real(const Area& x) { return x; }
  inline Area PHYSICSLIBRARY_API imag(const Area&) { return 0_m2; }

}; // namespace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Area> : NumTraits<double> {
    typedef physics::Area Real;
    typedef physics::Area NonInteger;
    typedef physics::Area Nested;

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

using physics::operator"" _mm2;       using physics::operator"" _cm2;
using physics::operator"" _m2;
using physics::operator"" _in2;       using physics::operator"" _ft2;

#endif

