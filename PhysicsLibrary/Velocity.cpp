#include "pch.h"

#include "Velocity.h"

namespace physics {

  Velocity operator- (const Velocity& lh) {
    return Velocity(-lh.value());
  }

  Velocity operator+ (const Velocity& lh, const Velocity& rh) {
	  return Velocity(lh.value() + rh.value());
  }

  Velocity operator- (const Velocity& lh, const Velocity& rh) {
	  return Velocity(lh.value() - rh.value());
  }

  Velocity operator* (const Velocity& lh, const double& rh) {
	  return Velocity(lh.value() * rh);
  }
  Velocity operator* (const double& lh, const Velocity& rh) {
	  return Velocity(lh * rh.value());
  }

  Velocity operator/ (const Velocity& lh, const double& rh) {
	  return Velocity(lh.value() / rh);
  }

};  // namespace physics
