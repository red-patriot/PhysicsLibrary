#ifndef Damping_h_INCLUDED
#define Damping_h_INCLUDED

#include "PhysicsBase.h"

#include <Eigen\Core>

namespace physics {

  /**
   * \class Damping A resistance to motion proportional to velocity
   */
  class PHYSICSLIBRARY_API Damping : public PhysicsBase {
  public:
    /**
     * \brief Construct a Damping
     * 
     * \param _Newton_seconds_per_meter the measure of Damping in Newton seconds per meter.
     */
    explicit Damping(const double _Newton_seconds_per_meter = 0) : PhysicsBase(_Newton_seconds_per_meter) { }
    Damping(const Damping&) = default;
    ~Damping() = default;

    double Nspm() const { return _value; }
    double kNspm() const { return _value / 1000; }

    double lbspin() const { return _value * 0.224808943099711 * .0254; }
    double lbspft() const { return _value * 0.224808943099711 * .3048; }

    Damping& operator+= (const Damping& rh) { _value += rh._value; return *this; }
    Damping& operator-= (const Damping& rh) { _value -= rh._value; return *this; }
    Damping& operator*= (const double& rh) { _value *= rh; return *this; }
    Damping& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  // Literal operators
  Damping PHYSICSLIBRARY_API operator"" _Nspm (long double val);
  Damping PHYSICSLIBRARY_API operator"" _Nspm (unsigned long long val);

  Damping PHYSICSLIBRARY_API operator"" _kNspm (long double val);
  Damping PHYSICSLIBRARY_API operator"" _kNspm (unsigned long long val);

  Damping PHYSICSLIBRARY_API operator"" _lbspin (long double val);
  Damping PHYSICSLIBRARY_API operator"" _lbspin (unsigned long long val);

  Damping PHYSICSLIBRARY_API operator"" _lbspft (long double val);
  Damping PHYSICSLIBRARY_API operator"" _lbspft (unsigned long long val);

  Damping PHYSICSLIBRARY_API operator- (const Damping& lh);

  Damping PHYSICSLIBRARY_API operator+ (const Damping& lh, const Damping& rh);

  Damping PHYSICSLIBRARY_API operator- (const Damping& lh, const Damping& rh);

  Damping PHYSICSLIBRARY_API operator* (const Damping& lh, const double& rh);
  Damping PHYSICSLIBRARY_API operator* (const double& lh, const Damping& rh);
  Damping PHYSICSLIBRARY_API operator* (const class Stiffness& lh, const class Time& rh);
  Damping PHYSICSLIBRARY_API operator* (const class Time& lh, const class Stiffness& rh);
  Damping PHYSICSLIBRARY_API operator* (const class Mass& lh, const class Frequency& rh);
  Damping PHYSICSLIBRARY_API operator* (const class Frequency& lh, const class Mass& rh);

  Damping PHYSICSLIBRARY_API operator/ (const Damping& lh, const double& rh);
  double PHYSICSLIBRARY_API operator/ (const Damping& lh, const Damping& rh);

  bool PHYSICSLIBRARY_API operator== (const Damping& lh, const Damping& rh);
  bool PHYSICSLIBRARY_API operator> (const Damping& lh, const Damping& rh);
  bool PHYSICSLIBRARY_API operator!= (const Damping& lh, const Damping& rh);
  bool PHYSICSLIBRARY_API operator< (const Damping& lh, const Damping& rh);
  bool PHYSICSLIBRARY_API operator>= (const Damping& lh, const Damping& rh);
  bool PHYSICSLIBRARY_API operator<= (const Damping& lh, const Damping& rh);

};  // namespace physics

using physics::operator"" _Nspm;        using physics::operator"" _kNspm;
using physics::operator"" _lbspin;      using physics::operator"" _lbspft;

#endif
