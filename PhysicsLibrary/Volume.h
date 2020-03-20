#ifndef Volume_h_INCLUDED
#define Volume_h_INCLUDED

#include "PhysicsExport.h"

namespace physics {

  class SecondMomentOfArea;
  class Volume;
  class Area;
  class Length;

  // Literal operators
  Volume PHYSICSLIBRARY_API operator"" _mm3(long double val);
  Volume PHYSICSLIBRARY_API operator"" _mm3(unsigned long long val);

  Volume PHYSICSLIBRARY_API operator"" _cm3(long double val);
  Volume PHYSICSLIBRARY_API operator"" _cm3(unsigned long long val);

  Volume PHYSICSLIBRARY_API operator"" _m3(long double val);
  Volume PHYSICSLIBRARY_API operator"" _m3(unsigned long long val);

  Volume PHYSICSLIBRARY_API operator"" _in3(long double val);
  Volume PHYSICSLIBRARY_API operator"" _in3(unsigned long long val);

  Volume PHYSICSLIBRARY_API operator"" _ft3(long double val);
  Volume PHYSICSLIBRARY_API operator"" _ft3(unsigned long long val);

  class PHYSICSLIBRARY_API Volume {
  public:
    Volume() = default;
    Volume(const Volume&) = default;
    ~Volume() = default;

    double mm3() const { return meters3 * 1'000'000'000; }
    double cm3() const { return meters3 * 1'000'000; }
    double m3() const { return meters3; }

    double in3() const { return meters3 * (1'000'000/16.387'064); }
    double ft3() const { return meters3 * (1'000'000/28'316.846'592); }

    Volume& operator+= (const Volume& rh) { meters3 += rh.meters3; return *this; }
    Volume& operator-= (const Volume& rh) { meters3 -= rh.meters3; return *this; }

  private:
    double meters3;

    Volume(const double& m3) : meters3(m3) { }

    // Friends
    friend Volume PHYSICSLIBRARY_API operator- (const Volume& lh);

    friend Volume PHYSICSLIBRARY_API operator+ (const Volume& lh, const Volume& rh);

    friend Volume PHYSICSLIBRARY_API operator- (const Volume& lh, const Volume& rh);

    friend Volume PHYSICSLIBRARY_API operator* (const Area& lh, const Length& rh);
    friend Volume PHYSICSLIBRARY_API operator* (const Length& lh, const Area& rh);
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator* (const Volume& lh,
                                                            const Length& rh);        // defined in MomentofArea.cpp
    friend SecondMomentOfArea PHYSICSLIBRARY_API operator* (const Length& lh,
                                                            const Volume& rh);        // defined in MomentofArea.cpp
    friend Volume PHYSICSLIBRARY_API operator* (const Volume& lh, const double& n);
    friend Volume PHYSICSLIBRARY_API operator* (const double& n, const Volume& rh);

    friend Volume PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, const Length& rh);
    friend Area PHYSICSLIBRARY_API operator/ (const Volume& lh, const Length& rh);    // defined in Area.cpp
    friend Length PHYSICSLIBRARY_API operator/ (const SecondMomentOfArea& lh, 
                                                const Volume& rh);                    // defined in Length.cpp
    friend Length PHYSICSLIBRARY_API operator/ (const Volume& lh, const Area& rh);    // defined in Length.cpp
    friend double PHYSICSLIBRARY_API operator/ (const Volume& lh, const Volume& rh);
    friend Volume PHYSICSLIBRARY_API operator/ (const Volume& lh, const double& n);

    friend bool PHYSICSLIBRARY_API operator== (const Volume& lh, const Volume& rh);
    friend bool PHYSICSLIBRARY_API operator> (const Volume& lh, const Volume& rh);
    friend bool PHYSICSLIBRARY_API operator!= (const Volume& lh, const Volume& rh);
    friend bool PHYSICSLIBRARY_API operator< (const Volume& lh, const Volume& rh);
    friend bool PHYSICSLIBRARY_API operator>= (const Volume& lh, const Volume& rh);
    friend bool PHYSICSLIBRARY_API operator<= (const Volume& lh, const Volume& rh);


    // Literal operators
    friend Volume PHYSICSLIBRARY_API operator"" _mm3(long double val);
    friend Volume PHYSICSLIBRARY_API operator"" _mm3(unsigned long long val);

    friend Volume PHYSICSLIBRARY_API operator"" _cm3(long double val);
    friend Volume PHYSICSLIBRARY_API operator"" _cm3(unsigned long long val);

    friend Volume PHYSICSLIBRARY_API operator"" _m3(long double val);
    friend Volume PHYSICSLIBRARY_API operator"" _m3(unsigned long long val);

    friend Volume PHYSICSLIBRARY_API operator"" _in3(long double val);
    friend Volume PHYSICSLIBRARY_API operator"" _in3(unsigned long long val);

    friend Volume PHYSICSLIBRARY_API operator"" _ft3(long double val);
    friend Volume PHYSICSLIBRARY_API operator"" _ft3(unsigned long long val);
  };

}; // namespace physics

//? This feels hacky, is there some other way to do this?
using physics::operator"" _mm3;         using physics::operator"" _cm3;
using physics::operator"" _m3;
using physics::operator"" _in3;         using physics::operator"" _ft3;

#endif

