#ifndef Force_h_INCLUDED
#define Force_h_INCLUDED

#include "PhysicsExport.h"

namespace physics {
  class Force;

  // Literal operators
  Force PHYSICSLIBRARY_API operator"" _N(long double val);
  Force PHYSICSLIBRARY_API operator"" _N(unsigned long long val);

  Force PHYSICSLIBRARY_API operator"" _kN(long double val);
  Force PHYSICSLIBRARY_API operator"" _kN(unsigned long long val);

  Force PHYSICSLIBRARY_API operator"" _lbf(long double val);
  Force PHYSICSLIBRARY_API operator"" _lbf(unsigned long long val);

  Force PHYSICSLIBRARY_API operator"" _kips(long double val);
  Force PHYSICSLIBRARY_API operator"" _kips(unsigned long long val);

  class PHYSICSLIBRARY_API Force {
  public:
    explicit Force(double _newtons=0) : newtons(_newtons) { }
    Force(const Force&) = default;
    ~Force() = default;

    double N() const { return newtons; }
    double kN() const { return newtons * 0.001; }

    double lbf() const { return newtons * 0.224808943099711; }
    double kips() const { return newtons * 0.000224808943099711;  }

    Force& operator+= (const Force& rh) { newtons += rh.newtons; return *this; }
    Force& operator-= (const Force& rh) { newtons -= rh.newtons; return *this; }

  private:
    double newtons;

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

    // Literal operators
    friend Force PHYSICSLIBRARY_API operator"" _N(long double val);
    friend Force PHYSICSLIBRARY_API operator"" _N(unsigned long long val);

    friend Force PHYSICSLIBRARY_API operator"" _kN(long double val);
    friend Force PHYSICSLIBRARY_API operator"" _kN(unsigned long long val);

    friend Force PHYSICSLIBRARY_API operator"" _lbf(long double val);
    friend Force PHYSICSLIBRARY_API operator"" _lbf(unsigned long long val);

    friend Force PHYSICSLIBRARY_API operator"" _kips(long double val);
    friend Force PHYSICSLIBRARY_API operator"" _kips(unsigned long long val);
  };

};  // namespace physics

using physics::operator""_N;        using physics::operator""_kN;
using physics::operator""_lbf;      using physics::operator""_kips;

#endif

