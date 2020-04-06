#ifndef Length_h_INCLUDED
#define Length_h_INCLUDED

#include "PhysicsExport.h"

#include <Eigen/Core>

namespace physics {

  class SecondMomentOfArea;
  class Volume;
  class Area;
  class Length;

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


  class PHYSICSLIBRARY_API Length {
  public:
    explicit Length(double _meters = 0) : meters(_meters) { }

    Length(const Length&) = default;
    ~Length() = default;

    double mm() const { return meters * 1000; }
    double cm() const { return meters * 100; }
    double m() const { return meters; }
    double km() const { return meters * 0.001; }

    double in() const { return meters * (100/2.54); }
    double ft() const { return meters * (100/(30.48)); }
    double mi() const { return meters * (100/(160'934.4)); }

    Length& operator+= (const Length& rh) { meters += rh.meters; return *this; }
    Length& operator-= (const Length& rh) { meters -= rh.meters; return *this; }

  private:
    double meters;

    // Friends
    friend Length PHYSICSLIBRARY_API operator- (const Length& lh);

    friend Length PHYSICSLIBRARY_API  operator+ (const Length& lh, const Length& rh);

    friend Length PHYSICSLIBRARY_API  operator- (const Length& lh, const Length& rh);

    friend Length PHYSICSLIBRARY_API  operator* (const Length& lh, const double& n);
    friend Length PHYSICSLIBRARY_API  operator* (const double& n, const Length& rh);
    friend Area PHYSICSLIBRARY_API  operator* (const Length& lh, const Length& rh);    // defined in Area.cpp
    friend Volume PHYSICSLIBRARY_API  operator* (const Area& lh, const Length& rh);    // defined in Volume.cpp
    friend Volume PHYSICSLIBRARY_API  operator* (const Length& lh, const Area& rh);    // defined in Volume.cpp
    friend SecondMomentOfArea PHYSICSLIBRARY_API  operator* (const Volume& lh, 
                                                            const Length& rh);         // defined in SecondMomentOfArea.cpp
    friend SecondMomentOfArea PHYSICSLIBRARY_API  operator* (const Length& lh, 
                                                            const Volume& rh);         // defined in SecondMomentOfArea.cpp
    friend class Force PHYSICSLIBRARY_API operator* (const class Stiffness& lh, const Length& rh);    // defined in Force.cpp
    friend class Force PHYSICSLIBRARY_API operator* (const Length& lh, const class Stiffness& rh); 
    friend Stiffness PHYSICSLIBRARY_API operator* (const class Pressure& lh, const class Length& rh); // defined in Stiffness.cpp
    friend Stiffness PHYSICSLIBRARY_API operator* (const class Length& lh, const class Pressure& rh); // defined in Stiffness.cpp// defined in Force.cpp

    friend Length PHYSICSLIBRARY_API  operator/ (const Area& lh, const Length& rh);
    friend Length PHYSICSLIBRARY_API  operator/ (const Volume& lh, const Area& rh);
    friend Length PHYSICSLIBRARY_API  operator/ (const SecondMomentOfArea& lh, const Volume& rh);
    friend Volume PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, 
                                                const Length& rh);                     // defined in Volume.cpp
    friend Area PHYSICSLIBRARY_API  operator/ (const Volume& lh, const Length& rh);    // defined in Area.cpp
    friend double PHYSICSLIBRARY_API  operator/ (const Length& lh, const Length& rh);
    friend Length PHYSICSLIBRARY_API  operator/ (const Length& lh, const double& n);
    friend class Stiffness PHYSICSLIBRARY_API operator/ (const class Force& lh, const Length& rh);    // defined in Stiffness.cpp
    friend class Pressure PHYSICSLIBRARY_API operator/ (const class Stiffness& lh, const Length& rh); // defined in Pressure.cpp

    friend bool PHYSICSLIBRARY_API  operator== (const Length& lh, const Length& rh);
    friend bool PHYSICSLIBRARY_API  operator> (const Length& lh, const Length& rh);
    friend bool PHYSICSLIBRARY_API  operator!= (const Length& lh, const Length& rh);
    friend bool PHYSICSLIBRARY_API  operator< (const Length& lh, const Length& rh);
    friend bool PHYSICSLIBRARY_API  operator>= (const Length& lh, const Length& rh);
    friend bool PHYSICSLIBRARY_API  operator<= (const Length& lh, const Length& rh);

    // Literal operators
    friend Length PHYSICSLIBRARY_API  operator"" _mm (long double val);
    friend Length PHYSICSLIBRARY_API  operator"" _mm (unsigned long long val);

    friend Length PHYSICSLIBRARY_API  operator"" _cm (long double val);
    friend Length PHYSICSLIBRARY_API  operator"" _cm (unsigned long long val);

    friend Length PHYSICSLIBRARY_API  operator"" _m (long double val);
    friend Length PHYSICSLIBRARY_API  operator"" _m (unsigned long long val);

    friend Length PHYSICSLIBRARY_API  operator"" _km (long double val);
    friend Length PHYSICSLIBRARY_API  operator"" _km (unsigned long long val);

    friend Length PHYSICSLIBRARY_API  operator"" _in (long double val);
    friend Length PHYSICSLIBRARY_API  operator"" _in (unsigned long long val);

    friend Length PHYSICSLIBRARY_API  operator"" _ft (long double val);
    friend Length PHYSICSLIBRARY_API  operator"" _ft (unsigned long long val);

    friend Length PHYSICSLIBRARY_API  operator"" _mi (long double val);
    friend Length PHYSICSLIBRARY_API  operator"" _mi (unsigned long long val);
  };

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

