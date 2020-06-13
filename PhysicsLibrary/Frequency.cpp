#include "pch.h"

#include "Frequency.h"
#include "Time.h"
#include "Velocity.h"
#include "Acceleration.h"
#include "Length.h"
#include "PhysicsMath.h"

namespace physics {

  Frequency operator- (const Frequency& lh) {
    return Frequency(-lh.value());
  }

  Frequency operator+ (const Frequency& lh, const Frequency& rh) {
  	return Frequency(lh.value() + rh.value());
  }

  Frequency operator- (const Frequency& lh, const Frequency& rh) {
  	return Frequency(lh.value() - rh.value());
  }

  Frequency operator* (const Frequency& lh, const double& rh) {
  	return Frequency(lh.value() * rh);
  }
  Frequency operator* (const double& lh, const Frequency& rh) {
  	return Frequency(lh * rh.value());
  }

  Frequency operator/ (const Frequency& lh, const double& rh) {
  	return Frequency(lh.value() / rh);
  }
  double operator/ (const Frequency& lh, const Frequency& rh) {
  	return double(lh.value() / rh.value());
  }
  Frequency operator/ (const double& lh, const Time& rh) {
  	return Frequency(lh / rh.value());
  }
  Frequency operator/ (const Velocity& lh, const Length& rh) {
  	return Frequency(lh.value() / rh.value());
  }
  Frequency operator/ (const Acceleration& lh, const Velocity& rh) {
  	return Frequency(lh.value() / rh.value());
  }

  bool operator== (const Frequency& lh, const Frequency& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Frequency& lh, const Frequency& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }

  bool operator!= (const Frequency& lh, const Frequency& rh) {
    return !(lh == rh);
  }
  bool operator< (const Frequency& lh, const Frequency& rh) {
    return rh > lh;
  }
  bool operator>= (const Frequency& lh, const Frequency& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Frequency& lh, const Frequency& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
   * The following units are supported:
   * Hz, kHz, MHz
   */

  Frequency operator"" _Hz (long double val) {
    return Frequency(val);
  }
  Frequency operator"" _Hz (unsigned long long val) {
    return Frequency(val);
  }

  Frequency operator"" _kHz (long double val) {
    return Frequency(val);
  }
  Frequency operator"" _kHz (unsigned long long val) {
    return Frequency(val);
  }

  Frequency operator"" _MHz (long double val) {
    return Frequency(val);
  }
  Frequency operator"" _MHz (unsigned long long val) {
    return Frequency(val);
  }

};
