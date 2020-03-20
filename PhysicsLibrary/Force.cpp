#include "pch.h"

#include "Force.h"
#include "Stiffness.h"
#include "Length.h"
#include "Area.h"
#include "Pressure.h"
#include "PhysicsMath.h"

namespace physics {
  // Negation operator
  Force operator-(const Force& lh) {
    return Force(-lh.newtons);
  }
  Force  operator+ (const Force& lh, const Force& rh) {
    return Force(lh.newtons + rh.newtons);
  }

  Force  operator- (const Force& lh, const Force& rh) {
    return Force(lh.newtons - rh.newtons);
  }

  Force  operator* (const Force& lh, const double& n) {
    return Force(lh.newtons * n);
  }
  Force  operator* (const double& n, const Force& rh) {
    return rh * n;
  }
  Force operator*(const Stiffness& lh, const Length& rh) {
    return Force(lh.newtons_per_meter * rh.meters);
  }
  Force operator*(const Length& lh, const Stiffness& rh) {
    return rh * lh;
  }
  Force  operator*(const Pressure& lh, const Area& rh) {
    return Force(lh.pascals * rh.meters2);
  }
  Force  operator*(const Area& lh, const Pressure& rh) {
    return rh * lh;
  }
    
  double  operator/ (const Force& lh, const Force& rh) {
    return lh.newtons / rh.newtons;
  } 
  Force  operator/ (const Force& lh, const double& n) {
    return Force(lh.newtons / n);
  }
     
  bool  operator== (const Force& lh, const Force& rh) {
    return fuzzy_equals(lh.newtons, rh.newtons);
  }
  bool  operator> (const Force& lh, const Force& rh) {
    return fuzzy_greater(lh.newtons, rh.newtons);
  }
  bool  operator!= (const Force& lh, const Force& rh) {
    return !(lh == rh);
  }
  bool  operator< (const Force& lh, const Force& rh) {
    return rh > lh;
  }
  bool  operator>= (const Force& lh, const Force& rh) {
    return lh > rh || lh == rh;
  }
  bool  operator<= (const Force& lh, const Force& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
   * The following units are supported:
   * N, kN
   * lbf, kips
   */

  Force  operator"" _N(long double val) {
    return Force(val);
  }
  Force  operator"" _N(unsigned long long val) {
    return Force(val);
  }

  Force  operator"" _kN(long double val) {
    return Force(val * 1000);
  }
  Force  operator"" _kN(unsigned long long val) {
    return Force(val * 1000);
  }

  Force  operator"" _lbf(long double val) {
    return Force(val * 4.4482216152605);
  }
  Force  operator"" _lbf(unsigned long long val) {
    return Force(val * 4.4482216152605);
  }

  Force  operator"" _kips(long double val) {
    return Force(val * 4448.2216152605);
  }
  Force  operator"" _kips(unsigned long long val) {
    return Force(val * 4448.2216152605);
  }

}; // namespace physics
