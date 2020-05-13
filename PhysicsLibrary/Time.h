#ifndef Time_h_INCLUDED
#define Time_h_INCLUDED

#include "PhysicsBase.h"

#include <Eigen/Core>

namespace physics {

  /**
   * \class Time a time
   */
  class PHYSICSLIBRARY_API Time : public PhysicsBase {
  public:
    /**
     * \brief Construct a Time
     * 
     * \param _seconds the measure of time in seconds
     */
    Time(const double _seconds = 0) : PhysicsBase(_seconds) { }
    Time(const Time&) = default;
    ~Time() = default;

    double sec() const { return _value; }
    double minute() const { return _value / 60; }
    double hour() const { return _value / 3600; }
  };

  Time PHYSICSLIBRARY_API operator"" _sec (long double val);
  Time PHYSICSLIBRARY_API operator"" _sec (unsigned long long val);

  Time operator"" _minute (long double val);
  Time operator"" _minute (unsigned long long val);

  Time operator"" _hour (long double val);
  Time operator"" _hour (unsigned long long val);

  Time PHYSICSLIBRARY_API operator- (const Time& lh);

  Time PHYSICSLIBRARY_API operator+ (const Time& lh, const Time& rh);

  Time PHYSICSLIBRARY_API operator- (const Time& lh, const Time& rh);
  
  Time PHYSICSLIBRARY_API operator* (const Time& lh, const double& rh);
  Time PHYSICSLIBRARY_API operator* (const double& lh, const Time& rh);

  Time PHYSICSLIBRARY_API operator/ (const Time& lh, const double& rh);

  bool operator== (const Time& lh, const Time& rh);
  bool operator> (const Time& lh, const Time& rh);
  bool operator!= (const Time& lh, const Time& rh);
  bool operator< (const Time& lh, const Time& rh);
  bool operator>= (const Time& lh, const Time& rh);
  bool operator<= (const Time& lh, const Time& rh);


  inline Time PHYSICSLIBRARY_API conj(const Time& x) { return x; }
  inline Time PHYSICSLIBRARY_API real(const Time& x) { return x; }
  inline Time PHYSICSLIBRARY_API imag(const Time& x) { return 0_sec; }

};  // namepsace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Time> : NumTraits<double> {
    typedef physics::Time Real;
    typedef physics::Time NonInteger;
    typedef physics::Time Nested;

    enum {
      IsComplex = 0,
      IsInteger = 0,
      IsSigned = 1,
      RequireInitialization = 1,
      ReadCost = 1,
      AddCost = 3,
      MulCost = 3
    };
  };

};  // namespace Eigen

using physics::operator"" _sec;

#endif
