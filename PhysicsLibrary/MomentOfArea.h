#ifndef Moment_Of_Inertia_h_INCLUDED
#define Moment_Of_Inertia_h_INCLUDED

#include "PhysicsExport.h"

#include <Eigen/Core>

namespace physics {

  class SecondMomentOfArea;
  class Volume;
  class Area;
  class Length;

  // First moment of Area and Volume have the same units, so define them as "equal" here
  using FirstMomentOfArea = Volume;

  // Literal operators
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _mm4(long double val);
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _mm4(unsigned long long val);

  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _m4(long double val);
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _m4(unsigned long long val);

  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _in4(long double val);
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _in4(unsigned long long val);

  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _ft4(long double val);
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _ft4(unsigned long long val);

  class PHYSICSLIBRARY_API SecondMomentOfArea {
  public:
    explicit SecondMomentOfArea(const double& _meters4=0) : meters4(_meters4) { }
    SecondMomentOfArea(const SecondMomentOfArea&) = default;
    ~SecondMomentOfArea() = default;

    double mm4() const { return meters4 * 1'000'000'000'000;  }
    double m4() const { return meters4; }

    double in4() const { return meters4 * 100'000'000 / 41.623'142'56; }
    double ft4() const { return meters4 * 100'000'000 / 863'097.481'241'6; }

    SecondMomentOfArea& operator+= (const SecondMomentOfArea& rh) { meters4 += rh.meters4; return *this; }
    SecondMomentOfArea& operator-= (const SecondMomentOfArea& rh) { meters4 -= rh.meters4; return *this; }
    SecondMomentOfArea& operator*= (const double& rh) { meters4 *= rh; return *this; }
    SecondMomentOfArea& operator/= (const double& rh) { meters4 /= rh; return *this; }

  private:
    double meters4;

    // Friends
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator- (const SecondMomentOfArea& lh);

    friend SecondMomentOfArea PHYSICSLIBRARY_API operator+ (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);

    friend SecondMomentOfArea PHYSICSLIBRARY_API operator- (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);


    friend SecondMomentOfArea PHYSICSLIBRARY_API operator* (const SecondMomentOfArea& lh, const double& n);
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator* (const double& n, const SecondMomentOfArea& rh);
    friend PHYSICSLIBRARY_API SecondMomentOfArea operator* (const Volume& lh, const Length& rh);
    friend PHYSICSLIBRARY_API SecondMomentOfArea operator* (const Length& lh, const Volume& rh);
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator* (const Area& lh, const Area& rh);

    friend Volume PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, const Length& rh);  // defined in Volume.cpp
    friend Area PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, const Area& rh);      // defined in Area.cpp
    friend Length PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh,
                                                const Volume& rh);                                // defined in Length.cpp
    friend double PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, 
                                                const SecondMomentOfArea& rh);
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, const double& n);

    friend bool PHYSICSLIBRARY_API operator== (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
    friend bool PHYSICSLIBRARY_API operator> (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
    friend bool PHYSICSLIBRARY_API operator!= (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
    friend bool PHYSICSLIBRARY_API operator< (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
    friend bool PHYSICSLIBRARY_API operator>= (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
    friend bool PHYSICSLIBRARY_API operator<= (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
  
    // Literal operators
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator"" _mm4(long double val);
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator"" _mm4(unsigned long long val);

    friend SecondMomentOfArea PHYSICSLIBRARY_API operator"" _m4(long double val);
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator"" _m4(unsigned long long val);

    friend SecondMomentOfArea PHYSICSLIBRARY_API operator"" _in4(long double val);
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator"" _in4(unsigned long long val);

    friend SecondMomentOfArea PHYSICSLIBRARY_API operator"" _ft4(long double val);
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator"" _ft4(unsigned long long val);
  };

  inline SecondMomentOfArea PHYSICSLIBRARY_API conj(const SecondMomentOfArea& x) { return x; }
  inline SecondMomentOfArea PHYSICSLIBRARY_API real(const SecondMomentOfArea& x) { return x; }
  inline SecondMomentOfArea PHYSICSLIBRARY_API imag(const SecondMomentOfArea&) { return 0_m4; }


}; // namespace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::SecondMomentOfArea> : NumTraits<double> {
    typedef physics::SecondMomentOfArea Real;
    typedef physics::SecondMomentOfArea NonInteger;
    typedef physics::SecondMomentOfArea Nested;

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

using physics::operator"" _mm4;         using physics::operator"" _m4;
using physics::operator"" _in4;         using physics::operator"" _ft4;

#endif
