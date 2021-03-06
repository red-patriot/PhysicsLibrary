#ifndef Moment_Of_Inertia_h_INCLUDED
#define Moment_Of_Inertia_h_INCLUDED

#include "PhysicsBase.h"

#include <Eigen/Core>

namespace physics {

  class Volume;
  class Area;
  class Length;

  // First moment of Area and Volume have the same units, so define them as "equal" here
  using FirstMomentOfArea = Volume;

  /**
   * \class SecondMomentOfArea A 4D measure of the Area Moment of Inertia of a geometry
   */
  class PHYSICSLIBRARY_API SecondMomentOfArea : public PhysicsBase {
  public:
    /**
     * \brief Construct a SecondMomentOfArea
     * 
     * \param _meters4 the measure of the area moment of inertia in meters^4
     */
    explicit SecondMomentOfArea(const double& _meters4 = 0) : PhysicsBase(_meters4) { }
    SecondMomentOfArea(const SecondMomentOfArea&) = default;
    ~SecondMomentOfArea() = default;

    double mm4() const { return _value * 1'000'000'000'000; }
    double m4() const { return _value; }

    double in4() const { return _value * 100'000'000 / 41.623'142'56; }
    double ft4() const { return _value * 100'000'000 / 863'097.481'241'6; }

    SecondMomentOfArea& operator+= (const SecondMomentOfArea& rh) { _value += rh._value; return *this; }
    SecondMomentOfArea& operator-= (const SecondMomentOfArea& rh) { _value -= rh._value; return *this; }
    SecondMomentOfArea& operator*= (const double& rh) { _value *= rh; return *this; }
    SecondMomentOfArea& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  // Literal operators
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _mm4(long double val);
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _mm4(unsigned long long val);

  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _m4(long double val);
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _m4(unsigned long long val);

  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _in4(long double val);
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _in4(unsigned long long val);

  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _ft4(long double val);
  SecondMomentOfArea PHYSICSLIBRARY_API operator"" _ft4(unsigned long long val);

  SecondMomentOfArea PHYSICSLIBRARY_API operator- (const SecondMomentOfArea& lh);
  
  SecondMomentOfArea PHYSICSLIBRARY_API operator+ (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);

  SecondMomentOfArea PHYSICSLIBRARY_API operator- (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);


  SecondMomentOfArea PHYSICSLIBRARY_API operator* (const SecondMomentOfArea& lh, const double& n);
  SecondMomentOfArea PHYSICSLIBRARY_API operator* (const double& n, const SecondMomentOfArea& rh);
  SecondMomentOfArea PHYSICSLIBRARY_API operator* (const Volume& lh, const Length& rh);
  SecondMomentOfArea PHYSICSLIBRARY_API operator* (const Length& lh, const Volume& rh);
  SecondMomentOfArea PHYSICSLIBRARY_API operator* (const Area& lh, const Area& rh);

  SecondMomentOfArea PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, const double& n);
  double PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);

  bool PHYSICSLIBRARY_API operator== (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
  bool PHYSICSLIBRARY_API operator> (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
  bool PHYSICSLIBRARY_API operator!= (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
  bool PHYSICSLIBRARY_API operator< (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
  bool PHYSICSLIBRARY_API operator>= (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);
  bool PHYSICSLIBRARY_API operator<= (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh);

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
