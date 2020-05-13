#ifndef Velocity_h_INCLUDED
#define Velocity_h_INCLUDED

#include "PhysicsBase.h"

#include <Eigen/Core>

namespace physics {

  class Velocity : public PhysicsBase {
  public:
    Velocity(const double _meters_per_second) : PhysicsBase(_meters_per_second) { }
    Velocity(const Velocity&) = default;
    ~Velocity() = default;

    double meters_per_sec() const { return _value; }
    double km_per_hour() const { }

    double in_per_sec() const { }
    double ft_per_sec() const { }
    double mph() const { }
  };

  Velocity operator- (const Velocity& lh);

  Velocity operator+ (const Velocity& lh, const Velocity& rh);

  Velocity operator- (const Velocity& lh, const Velocity& rh);

  Velocity operator* (const Velocity& lh, const double& rh);
  Velocity operator* (const double& lh, const Velocity& rh);


  Velocity operator/ (const Velocity& lh, const double& rh);

};  // namespace physics

#endif
