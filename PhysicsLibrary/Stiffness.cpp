#include "pch.h"
#include "PhysicsMath.h"
#include "Stiffness.h"
#include "Force.h"
#include "Pressure.h"
#include "Length.h"

namespace physics {
  Stiffness PHYSICSLIBRARY_API operator- (const Stiffness& lh);

  Stiffness operator-(const Stiffness& lh) {
    return Stiffness(-lh.newtons_per_meter);
  }

  Stiffness operator+(const Stiffness& lh, const Stiffness& rh) {
    return Stiffness(lh.newtons_per_meter + rh.newtons_per_meter);
  }

  Stiffness operator-(const Stiffness& lh, const Stiffness& rh) {
    return Stiffness(lh.newtons_per_meter - rh.newtons_per_meter);
  }

  Stiffness operator*(const Stiffness& lh, const double& n) {
    return Stiffness(lh.newtons_per_meter * n);
  }

  Stiffness operator*(const double& n, const Stiffness& rh) {
    return rh * n;
  }

  Stiffness operator*(const Pressure& lh, const Length& rh) {
    return Stiffness(lh.pascals * rh.meters);
  }

  Stiffness operator*(const Length& lh, const Pressure& rh) {
    return rh * lh;
  }

  Stiffness operator/(const Stiffness& lh, const double& n) {
    return Stiffness(lh.newtons_per_meter / n);
  }

  Stiffness operator/(const Force& lh, const Length& rh) {
    return Stiffness(lh.newtons / rh.meters);
  }

  bool operator==(const Stiffness& lh, const Stiffness& rh) {
    return fuzzy_equals(lh.newtons_per_meter, rh.newtons_per_meter);
  }

  bool operator>(const Stiffness& lh, const Stiffness& rh) {
    return fuzzy_greater(lh.newtons_per_meter, rh.newtons_per_meter);
  }

  bool operator!=(const Stiffness& lh, const Stiffness& rh) {
    return !(lh == rh);
  }

  bool operator<(const Stiffness& lh, const Stiffness& rh) {
    return rh > lh;
  }

  bool operator>=(const Stiffness& lh, const Stiffness& rh) {
    return lh > rh || lh == rh;
  }

  bool operator<=(const Stiffness& lh, const Stiffness& rh) {
    return rh > lh || rh == lh;
  }

  Stiffness operator""_Npm(long double val) {
    return Stiffness(val);
  }

  Stiffness operator""_Npm(unsigned long long val) {
    return Stiffness(val);
  }

  Stiffness operator""_Npmm(long double val) {
    return Stiffness(val * 1000);
  }

  Stiffness operator""_Npmm(unsigned long long val) {
    return Stiffness(val * 1000);
  }

  Stiffness operator""_lbpin(long double val) {
    return Stiffness(val * 175.12683524647637795);
  }

  Stiffness operator""_lbpin(unsigned long long val) {
    return Stiffness(val * 175.12683524647637795);
  }

  Stiffness operator""_lbpft(long double val) {
    return Stiffness(val * 14.593902937206364829);
  }

  Stiffness operator""_lbpft(unsigned long long val) {
    return Stiffness(val * 14.593902937206364829);
  }

};  // namespace physics
