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

    double slug() const { return _value * 0.06852176556196105; }
  };

  Mass PHYSICSLIBRARY_API operator"" _g (long double val);
  Mass PHYSICSLIBRARY_API operator"" _g (unsigned long long val);

  Mass PHYSICSLIBRARY_API operator"" _kg (long double val);
  Mass PHYSICSLIBRARY_API operator"" _kg (unsigned long long val);

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

  inline Mass PHYSICSLIBRARY_API conj(const Mass& x) { return x; }
  inline Mass PHYSICSLIBRARY_API real(const Mass& x) { return x; }
  inline Mass PHYSICSLIBRARY_API imag(const Mass& x) { return 0_kg; }

};  // namespace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Mass> : NumTraits<double> {
    typedef physics::Mass Real;
    typedef physics::Mass NonInteger;
    typedef physics::Mass Nested;

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

using physics::operator"" _g;       using physics::operator"" _kg;
using physics::operator"" _slug;

#endif
