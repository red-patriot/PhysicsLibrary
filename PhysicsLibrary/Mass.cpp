#include "pch.h"
#include "Mass.h"

namespace physics {



  Mass physics::operator-(const Mass& lh) {
    return Mass(-lh.value());
  }

  Mass operator+ (const Mass& lh, const Mass& rh){
	  return Mass(lh.value() + rh.value());
  }

  Mass operator- (const Mass& lh, const Mass& rh){
	  return Mass(lh.value() - rh.value());
  }

  Mass operator* (const Mass& lh, const double& rh){
	  return Mass(lh.value() * rh);
  }
  Mass operator* (const double& lh, const Mass& rh){
	  return Mass(lh * rh.value());
  }

  Mass operator/ (const Mass& lh, const double& rh){
	  return Mass(lh.value() / rh);
  }

  // Comparison operators
  bool operator== (const Mass& lh, const Mass& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Mass& lh, const Mass& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }
  bool operator!= (const Mass& lh, const Mass& rh) {
    return !(lh == rh);
  }
  bool operator< (const Mass& lh, const Mass& rh) {
    return rh > lh;
  }
  bool operator>= (const Mass& lh, const Mass& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Mass& lh, const Mass& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
   * The following units are supported:
   * g, kg,
   * lbm, slug
   */

  Mass operator"" _g (long double val) {
    return Mass(val);
  }
  Mass operator"" _g (unsigned long long val) {
    return Mass(val);
  }

  Mass operator"" _kg (long double val) {
    return Mass(val);
  }
  Mass operator"" _kg (unsigned long long val) {
    return Mass(val);
  }

  Mass operator"" _lbm (long double val) {
    return Mass(val);
  }
  Mass operator"" _lbm (unsigned long long val) {
    return Mass(val);
  }

  Mass operator"" _slug (long double val) {
    return Mass(val);
  }
  Mass operator"" _slug (unsigned long long val) {
    return Mass(val);
  }

};  // namespace physics