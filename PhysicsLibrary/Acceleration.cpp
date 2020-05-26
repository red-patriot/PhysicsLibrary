#include "pch.h"

#include "Acceleration.h"
#include "Velocity.h"
#include "Time.h"
#include "Mass.h"
#include "Force.h"

namespace physics {

  Acceleration operator- (const Acceleration& lh) {
    return Acceleration(-lh.value());
  }

  Acceleration operator+ (const Acceleration& lh, const Acceleration& rh) {
  	return Acceleration(lh.value() + rh.value());
  }
    
  Acceleration operator- (const Acceleration& lh, const Acceleration& rh) {
  	return Acceleration(lh.value() - rh.value());
  }

  Acceleration operator* (const Acceleration& lh, const double& rh) {
  	return Acceleration(lh.value() * rh);
  }
  Acceleration operator* (const double& lh, const Acceleration& rh) {
  	return Acceleration(lh * rh.value());
  }

  Acceleration operator/ (const Acceleration& lh, const double& rh) {
  	return Acceleration(lh.value() / rh);
  }
  double operator/ (const Acceleration& lh, const Acceleration& rh) {
  	return double(lh.value() / rh.value());
  }
  Acceleration operator/ (const Velocity& lh, const Time& rh) {
  	return Acceleration(lh.value() / rh.value());
  }
  Acceleration operator/ (const Force& lh, const Mass& rh) {
  	return Acceleration(lh.value() / rh.value());
  }


  Acceleration operator"" _mpsec2 (long double val) {
    return Acceleration(val);
  }
  Acceleration operator"" _mpsec2 (unsigned long long val) {
    return Acceleration(val);
  }

  Acceleration operator"" _inpsec2 (long double val) {
    return Acceleration(val);
  }
  Acceleration operator"" _inpsec2 (unsigned long long val) {
    return Acceleration(val);
  }

  Acceleration operator"" _ftpsec2 (long double val) {
    return Acceleration(val);
  }
  Acceleration operator"" _ftpsec2 (unsigned long long val) {
    return Acceleration(val);
  }

};
