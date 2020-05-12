#include "pch.h"
#include "Time.h"

namespace physics {

  Time operator"" _sec (long double val) {
    return Time(val);
  }
  Time operator"" _sec (unsigned long long val) {
    return Time(val);
  }

  Time operator- (const Time& lh) {
    return Time(-lh.value());
  }

  Time operator+ (const Time& lh, const Time& rh) {
	  return Time(lh.value() + rh.value());
  }

  Time operator- (const Time& lh, const Time& rh) {
	  return Time(lh.value() - rh.value());
  }

  Time operator* (const Time& lh, const double& rh) {
	  return Time(lh.value() * rh);
  }
  Time operator* (const double& lh, const Time& rh) {
	  return Time(lh * rh.value());
  }

  Time operator/ (const Time& lh, const double& rh) {
	  return Time(lh.value() / rh);
  }

};  // namespace physics
