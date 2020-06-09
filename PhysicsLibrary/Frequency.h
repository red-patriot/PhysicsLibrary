#pragma once
#include "PhysicsBase.h"

namespace physics {


  /**
   * \class Frequency a measure of cycles/repetitions per unit time
   */
  class PHYSICSLIBRARY_API Frequency : public PhysicsBase { 
  public:
    /**
     * \brief Construct a frequency
     * 
     * \param _hertz the measure of cycles per second
     */
    explicit Frequency(const double _hertz=0) : PhysicsBase(_hertz) { }
    Frequency(const Frequency&) = default;
    ~Frequency() = default;

    double Hz() const { return _value; }
    double kHz() const { return _value * 0.001; }
    double MHz() const { return _value * 0.000'001; }

    Frequency& operator+= (const Frequency& rh) { _value += rh._value; return *this; }
    Frequency& operator-= (const Frequency& rh) { _value -= rh._value; return *this; }
    Frequency& operator*= (const double& rh) { _value *= rh; return *this; }
    Frequency& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  // Literal operators
  Frequency PHYSICSLIBRARY_API operator"" _Hz (long double val);
  Frequency PHYSICSLIBRARY_API operator"" _Hz (unsigned long long val);

  Frequency PHYSICSLIBRARY_API operator"" _kHz (long double val);
  Frequency PHYSICSLIBRARY_API operator"" _kHz (unsigned long long val);

  Frequency PHYSICSLIBRARY_API operator"" _MHz (long double val);
  Frequency PHYSICSLIBRARY_API operator"" _MHz (unsigned long long val);

  Frequency PHYSICSLIBRARY_API operator- (const Frequency& lh);

  Frequency PHYSICSLIBRARY_API operator+ (const Frequency& lh, const Frequency& rh);

  Frequency PHYSICSLIBRARY_API operator- (const Frequency& lh, const Frequency& rh);

  Frequency PHYSICSLIBRARY_API operator* (const Frequency& lh, const double& rh);
  Frequency PHYSICSLIBRARY_API operator* (const double& lh, const Frequency& rh);

  Frequency PHYSICSLIBRARY_API operator/ (const Frequency& lh, const double& rh);
  double PHYSICSLIBRARY_API operator/ (const Frequency& lh, const Frequency& rh);
  Frequency PHYSICSLIBRARY_API operator/ (const double& lh, const class Time& rh);
  Frequency PHYSICSLIBRARY_API operator/ (const class Velocity& lh, const class Length& rh);
  Frequency PHYSICSLIBRARY_API operator/ (const class Acceleration& lh, const class Velocity& rh);

};

using physics::operator"" _Hz;        using physics::operator"" _kHz;
using physics::operator"" _MHz;
