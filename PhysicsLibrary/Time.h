#ifndef Time_h_INCLUDED
#define Time_h_INCLUDED

#include "PhysicsBase.h"

namespace physics {

  class PHYSICSLIBRARY_API Time : public PhysicsBase {
  public:
    Time(const double _seconds = 0) : PhysicsBase(_seconds) { }
    Time(const Time&) = default;
    ~Time() = default;

    double sec() const { return _value; }
  };

Time operator"" _sec (long double val);
Time operator"" _sec (unsigned long long val);

Time operator- (const Time& lh);

Time operator+ (const Time& lh, const Time& rh);

Time operator- (const Time& lh, const Time& rh);

Time operator* (const Time& lh, const double& rh);
Time operator* (const double& lh, const Time& rh);

Time operator/ (const Time& lh, const double& rh);

};  // namepsace physics

#endif

