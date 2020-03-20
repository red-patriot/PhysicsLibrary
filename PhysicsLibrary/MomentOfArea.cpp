#include "pch.h"
#include "MomentOfArea.h"
#include "Volume.h"
#include "Area.h"
#include "Length.h"
#include "PhysicsMath.h"

namespace physics {
  // Negation operator
  SecondMomentOfArea operator-(const SecondMomentOfArea& lh) {
    return SecondMomentOfArea(-lh.meters4);
  }
  // Mathematical Operators
    SecondMomentOfArea operator+ (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh) {
    return SecondMomentOfArea(lh.meters4 + rh.meters4);
  }

  SecondMomentOfArea operator- (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh) {
    return SecondMomentOfArea(lh.meters4 - rh.meters4);
  }
  double operator/ (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh) {
    return lh.meters4 / rh.meters4;
  }

  SecondMomentOfArea operator* (const SecondMomentOfArea& lh, const double& n) {
    return SecondMomentOfArea(lh.meters4 * n);
  }
  SecondMomentOfArea operator* (const double& n, const SecondMomentOfArea& rh) {
    return rh * n;
  }
  SecondMomentOfArea operator* (const Volume& lh, const Length& rh) {
    return SecondMomentOfArea(lh.meters3 * rh.meters);
  }
  SecondMomentOfArea operator* (const Length& lh, const Volume& rh) {
    return rh * lh;
  }
  SecondMomentOfArea operator* (const Area& lh, const Area& rh) {
    return SecondMomentOfArea(lh.meters2 * rh.meters2);
  }

  SecondMomentOfArea operator/ (const SecondMomentOfArea& lh, const double& n) {
    return SecondMomentOfArea(lh.meters4 / n);
  }

  // Comparison Operators
  bool operator== (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh) {
    return fuzzy_equals(lh.meters4, rh.meters4);
  }
  bool operator> (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh) {
    return fuzzy_greater(lh.meters4, rh.meters4);
  }
  bool operator!= (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh) {
    return !(lh == rh);
  }
  bool operator< (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh) {
    return rh > lh;
  }
  bool operator>= (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const SecondMomentOfArea& lh, const SecondMomentOfArea& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
   * The following units are supported:
   * mm^4, m^4
   * in^4, ft^4
   */
  SecondMomentOfArea operator"" _mm4(long double val) {
    return SecondMomentOfArea(val * 0.000'000'000'001);
  }
  SecondMomentOfArea operator"" _mm4(unsigned long long val) {
    return SecondMomentOfArea(val * 0.000'000'000'001);
  }

  SecondMomentOfArea operator"" _m4(long double val) {
    return SecondMomentOfArea(val);
  }
  SecondMomentOfArea operator"" _m4(unsigned long long val) {
    return SecondMomentOfArea(val);
  }

  SecondMomentOfArea operator"" _in4(long double val) {
    return SecondMomentOfArea(val * 41.623'142'56 / 100'000'000);
  }
  SecondMomentOfArea operator"" _in4(unsigned long long val) {
    return SecondMomentOfArea(val * 41.623'142'56 / 100'000'000);
  }

  SecondMomentOfArea operator"" _ft4(long double val) {
    return SecondMomentOfArea(val * 863'097.481'241'6 / 100'000'000);
  }
  SecondMomentOfArea operator"" _ft4(unsigned long long val) {
    return SecondMomentOfArea(val * 863'097.481'241'6 / 100'000'000);
  }

}; // namespace physics
