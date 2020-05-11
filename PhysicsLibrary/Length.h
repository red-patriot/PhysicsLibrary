#ifndef Length_h_INCLUDED
#define Length_h_INCLUDED

#include "PhysicsBase.h"

#include <Eigen/Core>

namespace physics {

  class SecondMomentOfArea;
  class Volume;
  class Area;

  /**
   * \class Length A 1D geometry
   */
  class PHYSICSLIBRARY_API Length : public PhysicsBase {
  public:
    /**
     * \brief Construct a Length
     * 
     * \param _meters the measure of the length in meters
     */
    explicit Length(double _meters = 0) : PhysicsBase(_meters) { }
    Length(const Length&) = default;
    ~Length() = default;

    double mm() const { return _value * 1000; }
    double cm() const { return _value * 100; }
    double m() const { return _value; }
    double km() const { return _value * 0.001; }

    double in() const { return _value * (100/2.54); }
    double ft() const { return _value * (100/(30.48)); }
    double mi() const { return _value * (100/(160'934.4)); }

    Length& operator+= (const Length& rh) { _value += rh._value; return *this; }
    Length& operator-= (const Length& rh) { _value -= rh._value; return *this; }
    Length& operator*= (const double& rh) { _value *= rh; return *this; }
    Length& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  // Literal operators
  Length PHYSICSLIBRARY_API  operator"" _mm (long double val);
  Length PHYSICSLIBRARY_API  operator"" _mm (unsigned long long val);

  Length PHYSICSLIBRARY_API  operator"" _cm (long double val);
  Length PHYSICSLIBRARY_API  operator"" _cm (unsigned long long val);

  Length PHYSICSLIBRARY_API  operator"" _m (long double val);
  Length PHYSICSLIBRARY_API  operator"" _m (unsigned long long val);

  Length PHYSICSLIBRARY_API  operator"" _km (long double val);
  Length PHYSICSLIBRARY_API  operator"" _km (unsigned long long val);

  Length PHYSICSLIBRARY_API  operator"" _in (long double val);
  Length PHYSICSLIBRARY_API  operator"" _in (unsigned long long val);

  Length PHYSICSLIBRARY_API  operator"" _ft (long double val);
  Length PHYSICSLIBRARY_API  operator"" _ft (unsigned long long val);

  Length PHYSICSLIBRARY_API  operator"" _mi (long double val);
  Length PHYSICSLIBRARY_API  operator"" _mi (unsigned long long val);

  Length PHYSICSLIBRARY_API operator- (const Length& lh);

  Length PHYSICSLIBRARY_API  operator+ (const Length& lh, const Length& rh);

  Length PHYSICSLIBRARY_API  operator- (const Length& lh, const Length& rh);

  Length PHYSICSLIBRARY_API  operator* (const Length& lh, const double& n);
  Length PHYSICSLIBRARY_API  operator* (const double& n, const Length& rh);
  Area PHYSICSLIBRARY_API  operator* (const Length& lh, const Length& rh);    // defined in Area.cpp
  Volume PHYSICSLIBRARY_API  operator* (const Area& lh, const Length& rh);    // defined in Volume.cpp
  Volume PHYSICSLIBRARY_API  operator* (const Length& lh, const Area& rh);    // defined in Volume.cpp
  SecondMomentOfArea PHYSICSLIBRARY_API  operator* (const Volume& lh,
                                                    const Length& rh);         // defined in SecondMomentOfArea.cpp
  SecondMomentOfArea PHYSICSLIBRARY_API  operator* (const Length& lh,
                                                    const Volume& rh);         // defined in SecondMomentOfArea.cpp
  class Force PHYSICSLIBRARY_API operator* (const class Stiffness& lh, const Length& rh);    // defined in Force.cpp
  class Force PHYSICSLIBRARY_API operator* (const Length& lh, const class Stiffness& rh);
  Stiffness PHYSICSLIBRARY_API operator* (const class Pressure& lh, const class Length& rh); // defined in Stiffness.cpp
  Stiffness PHYSICSLIBRARY_API operator* (const class Length& lh, const class Pressure& rh); // defined in Stiffness.cpp// defined in Force.cpp

  Length PHYSICSLIBRARY_API  operator/ (const Area& lh, const Length& rh);
  Length PHYSICSLIBRARY_API  operator/ (const Volume& lh, const Area& rh);
  Length PHYSICSLIBRARY_API  operator/ (const SecondMomentOfArea& lh, const Volume& rh);
  Volume PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh,
                                       const Length& rh);                     // defined in Volume.cpp
  Area PHYSICSLIBRARY_API  operator/ (const Volume& lh, const Length& rh);    // defined in Area.cpp
  double PHYSICSLIBRARY_API  operator/ (const Length& lh, const Length& rh);
  Length PHYSICSLIBRARY_API  operator/ (const Length& lh, const double& n);
  class Stiffness PHYSICSLIBRARY_API operator/ (const class Force& lh, const Length& rh);    // defined in Stiffness.cpp
  class Pressure PHYSICSLIBRARY_API operator/ (const class Stiffness& lh, const Length& rh); // defined in Pressure.cpp
  
  bool PHYSICSLIBRARY_API  operator== (const Length& lh, const Length& rh);
  bool PHYSICSLIBRARY_API  operator> (const Length& lh, const Length& rh);
  bool PHYSICSLIBRARY_API  operator!= (const Length& lh, const Length& rh);
  bool PHYSICSLIBRARY_API  operator< (const Length& lh, const Length& rh);
  bool PHYSICSLIBRARY_API  operator>= (const Length& lh, const Length& rh);
  bool PHYSICSLIBRARY_API  operator<= (const Length& lh, const Length& rh);

  inline Length PHYSICSLIBRARY_API conj(const Length& x) { return x; }
  inline Length PHYSICSLIBRARY_API real(const Length& x) { return x; }
  inline Length PHYSICSLIBRARY_API imag(const Length&) { return 0_m; }


}; // namespace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Length> : NumTraits<double> {
    typedef physics::Length Real;
    typedef physics::Length NonInteger;
    typedef physics::Length Nested;

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

//? This feels hacky, is there some other way to do this?
using physics::operator"" _mm;      using physics::operator"" _cm;
using physics::operator"" _m;       using physics::operator"" _km;
using physics::operator"" _in;      using physics::operator"" _ft;
using physics::operator"" _mi;

#endif

