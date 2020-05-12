#ifndef Mass_h_INCLUDED
#define Mass_h_INCLUDED

#include "PhysicsMath.h"

#include <Eigen/Core>

namespace physics {

  /**
   * \class Mass a mass
   */
  class PHYSICSLIBRARY_API Mass : public PhysicsBase {
  public:
    /**
     * \brief Construct a Mass
     * 
     * \param _kilograms the measure of the mass in kilograms
     */
    explicit Mass(const double _kilograms=0) : PhysicsBase(_kilograms) { }
    Mass(const Mass&) = default;
    ~Mass() = default;

    double g() const { return _value * 1000; }
    double kg() const { return _value; }

    double lbm() const { return 0; }
    double slug() const { return 0; }
  };

  Mass PHYSICSLIBRARY_API operator"" _g (long double val);
  Mass PHYSICSLIBRARY_API operator"" _g (unsigned long long val);

  Mass PHYSICSLIBRARY_API operator"" _kg (long double val);
  Mass PHYSICSLIBRARY_API operator"" _kg (unsigned long long val);

  Mass PHYSICSLIBRARY_API operator"" _lbm (long double val);
  Mass PHYSICSLIBRARY_API operator"" _lbm (unsigned long long val);

  Mass PHYSICSLIBRARY_API operator"" _slug (long double val);
  Mass PHYSICSLIBRARY_API operator"" _slug (unsigned long long val);

  Mass PHYSICSLIBRARY_API operator- (const Mass& lh);

  Mass PHYSICSLIBRARY_API operator+ (const Mass& lh, const Mass& rh);

  Mass PHYSICSLIBRARY_API operator- (const Mass& lh, const Mass& rh);

  Mass PHYSICSLIBRARY_API operator* (const Mass& lh, const double& rh);
  Mass PHYSICSLIBRARY_API operator* (const double& lh, const Mass& rh);

  Mass PHYSICSLIBRARY_API operator/ (const Mass& lh, const double& rh);

  bool PHYSICSLIBRARY_API operator== (const Mass& lh, const Mass& rh);
  bool PHYSICSLIBRARY_API operator> (const Mass& lh, const Mass& rh);
  bool PHYSICSLIBRARY_API operator!= (const Mass& lh, const Mass& rh);
  bool PHYSICSLIBRARY_API operator< (const Mass& lh, const Mass& rh);
  bool PHYSICSLIBRARY_API operator>= (const Mass& lh, const Mass& rh);
  bool PHYSICSLIBRARY_API operator<= (const Mass& lh, const Mass& rh);

};  // namespace physics

#endif
