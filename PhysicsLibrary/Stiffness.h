#ifndef Stiffness_h_INCLUDED
#define Stiffness_h_INCLUDED

/* Stiffness.h
 * Simulation of a linear stiffness in force per unit length
 */

#include "PhysicsExport.h"

namespace physics {

  class Stiffness;

  Stiffness PHYSICSLIBRARY_API operator"" _Npm(long double val);
  Stiffness PHYSICSLIBRARY_API operator"" _Npm(unsigned long long val);

  Stiffness PHYSICSLIBRARY_API operator"" _Npmm(long double val);
  Stiffness PHYSICSLIBRARY_API operator"" _Npmm(unsigned long long val);

  Stiffness PHYSICSLIBRARY_API operator"" _lbpin(long double val);
  Stiffness PHYSICSLIBRARY_API operator"" _lbpin(unsigned long long val);

  Stiffness PHYSICSLIBRARY_API operator"" _lbpft(long double val);
  Stiffness PHYSICSLIBRARY_API operator"" _lbpft(unsigned long long val);

  class PHYSICSLIBRARY_API Stiffness {
  public:
    explicit Stiffness(double _newtons_per_meter = 0) : newtons_per_meter(_newtons_per_meter) { }
    Stiffness(const Stiffness&) = default;
    ~Stiffness() = default;

    double Npm() const { return newtons_per_meter; }
    double Npmm() const { return newtons_per_meter * 0.001; }
    
    double lbpin() const { return newtons_per_meter * 0.00571014715473264626; }
    double lbpft() const { return newtons_per_meter * 0.06852176585679175519; }

    Stiffness& operator+= (const Stiffness& rh) { newtons_per_meter += rh.newtons_per_meter; return *this; }
    Stiffness& operator-= (const Stiffness& rh) { newtons_per_meter -= rh.newtons_per_meter; return *this; }

  private:
    double newtons_per_meter;

    // Friends
    friend Stiffness PHYSICSLIBRARY_API operator- (const Stiffness& lh);

    friend Stiffness PHYSICSLIBRARY_API operator+ (const Stiffness& lh, const Stiffness& rh);

    friend Stiffness PHYSICSLIBRARY_API operator- (const Stiffness& lh, const Stiffness& rh);

    friend Stiffness PHYSICSLIBRARY_API operator* (const Stiffness& lh, const double & n);
    friend Stiffness PHYSICSLIBRARY_API operator* (const double& n, const Stiffness& rh);
    friend Stiffness PHYSICSLIBRARY_API operator* (const class Pressure& lh, const class Length& rh);
    friend Stiffness PHYSICSLIBRARY_API operator* (const class Length& lh, const class Pressure& rh);
    friend class Force PHYSICSLIBRARY_API operator* (const Stiffness& lh, const class Length& rh);    // defined in Force.cpp
    friend class Force PHYSICSLIBRARY_API operator* (const class Length& lh, const Stiffness& rh);    // defined in Force.cpp
    
    friend Stiffness PHYSICSLIBRARY_API operator/ (const Stiffness& lh, const double& n);
    friend Stiffness PHYSICSLIBRARY_API operator/ (const class Force& lh, const class Length& rh);
    friend class Pressure PHYSICSLIBRARY_API operator/ (const Stiffness& lh, const class Length& rh);// defined in Pressure.cpp
  
    // Comparison operators
    friend bool PHYSICSLIBRARY_API  operator== (const Stiffness& lh, const Stiffness& rh);
    friend bool PHYSICSLIBRARY_API  operator> (const Stiffness& lh, const Stiffness& rh);
    friend bool PHYSICSLIBRARY_API  operator!= (const Stiffness& lh, const Stiffness& rh);
    friend bool PHYSICSLIBRARY_API  operator< (const Stiffness& lh, const Stiffness& rh);
    friend bool PHYSICSLIBRARY_API  operator>= (const Stiffness& lh, const Stiffness& rh);
    friend bool PHYSICSLIBRARY_API  operator<= (const Stiffness& lh, const Stiffness& rh);

    // Literal operators
    friend Stiffness PHYSICSLIBRARY_API operator"" _Npm(long double val);
    friend Stiffness PHYSICSLIBRARY_API operator"" _Npm(unsigned long long val);

    friend Stiffness PHYSICSLIBRARY_API operator"" _Npmm(long double val);
    friend Stiffness PHYSICSLIBRARY_API operator"" _Npmm(unsigned long long val);

    friend Stiffness PHYSICSLIBRARY_API operator"" _lbpin(long double val);
    friend Stiffness PHYSICSLIBRARY_API operator"" _lbpin(unsigned long long val);

    friend Stiffness PHYSICSLIBRARY_API operator"" _lbpft(long double val);
    friend Stiffness PHYSICSLIBRARY_API operator"" _lbpft(unsigned long long val);
  };

};  // namespace physics

using physics::operator"" _Npm;       using physics::operator"" _Npmm;
using physics::operator"" _lbpin;     using physics::operator"" _lbpft;

#endif

