#include "pch.h"

#include "Damping.h"
#include "Stiffness.h"
#include "TIme.h"

namespace physics {

  Damping operator- (const Damping& lh) {
    return Damping(-lh.value());
  }

  Damping operator+ (const Damping& lh, const Damping& rh) {
  	return Damping(lh.value() + rh.value());
  }

  Damping operator- (const Damping& lh, const Damping& rh) {
  	return Damping(lh.value() - rh.value());
  }

  Damping operator* (const Damping& lh, const double& rh) {
  	return Damping(lh.value() * rh);
  }
  Damping operator* (const double& lh, const Damping& rh) {
  	return Damping(lh * rh.value());
  }
  Damping operator* (const Stiffness& lh, const Time& rh) {
  	return Damping(lh.value() * rh.value());
  }
  Damping operator* (const Time& lh, const Stiffness& rh) {
  	return Damping(lh.value() * rh.value());
  }
    
  Damping operator/ (const Damping& lh, const double& rh) {
  	return Damping(lh.value() / rh);
  }
  double operator/ (const Damping& lh, const Damping& rh) {
  	return double(lh.value() / rh.value());
  }

  Damping operator"" _Nspm (long double val) {
    return Damping(val);
  }
  Damping operator"" _Nspm (unsigned long long val) {
    return Damping(val);
  }

  Damping operator"" _kNspm (long double val) {
    return Damping(val);
  }
  Damping operator"" _kNspm (unsigned long long val) {
    return Damping(val);
  }

  Damping operator"" _lbspin (long double val) {
    return Damping(val);
  }
  Damping operator"" _lbspin (unsigned long long val) {
    return Damping(val);
  }

  Damping operator"" _lbspft (long double val) {
    return Damping(val);
  }
  Damping operator"" _lbspft (unsigned long long val) {
    return Damping(val);
  }

};  // namespace physics
