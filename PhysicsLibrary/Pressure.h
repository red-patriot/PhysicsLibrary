#ifndef Pressure_h_INCLUDED
#define Pressure_h_INCLUDED

/* Pressures.h
 * A class to represent pressures or anything with units of pressure
 */

#include "PhysicsBase.h"

#include <Eigen/Core>

namespace physics {

  class Pressure;
  class Pressure2;

  /**
   * \class Pressure A force distributed over an area
   */
  class PHYSICSLIBRARY_API Pressure : public PhysicsBase {
  public:
    /**
     * \brief Construct a pressure
     * 
     * \param _pascals the measure of pressure in Pascals
     */
    explicit Pressure(double _pascals = 0) : PhysicsBase(_pascals) { }
    Pressure(const Pressure&) = default;
    ~Pressure() = default;

    double Pa() const { return _value; }
    double kPa() const { return _value * 0.001; }
    double MPa() const { return _value * 0.000'001; }
    double GPa() const { return _value * 0.000'000'001; }

    double psi() const { return _value * 0.000'145'037'737'796'858'691'163; }
    double ksi() const { return _value * 0.000'000'145'037'737'796'858'691; }

    Pressure& operator+= (const Pressure& rh) { _value += rh._value; return *this; }
    Pressure& operator-= (const Pressure& rh) { _value -= rh._value; return *this; }
    Pressure& operator*= (const double& rh) { _value *= rh; return *this; }
    Pressure& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  // Literal operators
  Pressure PHYSICSLIBRARY_API operator"" _Pa (long double val);
  Pressure PHYSICSLIBRARY_API operator"" _Pa (unsigned long long val);

  Pressure PHYSICSLIBRARY_API operator"" _kPa (long double val);
  Pressure PHYSICSLIBRARY_API operator"" _kPa (unsigned long long val);

  Pressure PHYSICSLIBRARY_API operator"" _MPa (long double val);
  Pressure PHYSICSLIBRARY_API operator"" _MPa (unsigned long long val);

  Pressure PHYSICSLIBRARY_API operator"" _GPa (long double val);
  Pressure PHYSICSLIBRARY_API operator"" _GPa (unsigned long long val);

  Pressure PHYSICSLIBRARY_API operator"" _psi (long double val);
  Pressure PHYSICSLIBRARY_API operator"" _psi (unsigned long long val);

  Pressure PHYSICSLIBRARY_API operator"" _ksi (long double val);
  Pressure PHYSICSLIBRARY_API operator"" _ksi (unsigned long long val);

  Pressure PHYSICSLIBRARY_API operator- (const Pressure& lh);

  Pressure PHYSICSLIBRARY_API operator+ (const Pressure& lh, const Pressure& rh);

  Pressure PHYSICSLIBRARY_API operator- (const Pressure& lh, const Pressure& rh);

  Pressure2 PHYSICSLIBRARY_API operator* (const Pressure& lh, const Pressure& rh);
  Pressure PHYSICSLIBRARY_API operator* (const Pressure& lh, const double& n);
  Pressure PHYSICSLIBRARY_API operator* (const double& n, const Pressure& rh);
  class Force PHYSICSLIBRARY_API operator*(const Pressure& lh, const class Area& rh);  // defined in Force.cpp
  class Force PHYSICSLIBRARY_API operator*(const class Area& lh, const Pressure& rh);  // defined in Force.cpp
  class Stiffness PHYSICSLIBRARY_API operator* (const class Pressure& lh, const class Length& rh); // defined in Stiffness.cpp
  class Stiffness PHYSICSLIBRARY_API operator* (const class Length& lh, const class Pressure& rh); // defined in Stiffness.cpp

  double PHYSICSLIBRARY_API operator/ (const Pressure& lh, const Pressure& rh);
  Pressure PHYSICSLIBRARY_API operator/ (const Pressure2& lh, const Pressure& rh);
  Pressure PHYSICSLIBRARY_API operator/ (const Pressure& lh, const double& n);
  Pressure PHYSICSLIBRARY_API operator/ (const class Force& lh, const class Area& rh);
  Pressure PHYSICSLIBRARY_API operator/ (const class Stiffness& lh, const class Length& rh);

  bool PHYSICSLIBRARY_API operator== (const Pressure& lh, const Pressure& rh);
  bool PHYSICSLIBRARY_API operator> (const Pressure& lh, const Pressure& rh);
  bool PHYSICSLIBRARY_API operator!= (const Pressure& lh, const Pressure& rh);
  bool PHYSICSLIBRARY_API operator< (const Pressure& lh, const Pressure& rh);
  bool PHYSICSLIBRARY_API operator>= (const Pressure& lh, const Pressure& rh);
  bool PHYSICSLIBRARY_API operator<= (const Pressure& lh, const Pressure& rh);

  inline Pressure PHYSICSLIBRARY_API conj(const Pressure& x) { return x; }
  inline Pressure PHYSICSLIBRARY_API real(const Pressure& x) { return x; }
  inline Pressure PHYSICSLIBRARY_API imag(const Pressure&) { return 0_Pa; }

  /* Pressure^2, this class is only for use in intermetiate operations of 
     equations, so it has limited functionality. */
  class PHYSICSLIBRARY_API Pressure2 : public PhysicsBase {
  public:
    explicit Pressure2(double _pascals2 = 0) : PhysicsBase(_pascals2) { }
    ~Pressure2() = default;
  };

  // Friends
  Pressure2 PHYSICSLIBRARY_API operator+ (const Pressure2& lh, const Pressure2& rh);

  Pressure2 PHYSICSLIBRARY_API operator- (const Pressure2& lh, const Pressure2& rh);

  Pressure2 PHYSICSLIBRARY_API operator* (const Pressure& lh, const Pressure& rh);
  Pressure2 PHYSICSLIBRARY_API operator* (const Pressure2& lh, const double& n);
  Pressure2 PHYSICSLIBRARY_API operator* (const double& n, const Pressure2& rh);

  Pressure2 PHYSICSLIBRARY_API operator/ (const Pressure2& lh, const double& n);
  Pressure PHYSICSLIBRARY_API operator/ (const Pressure2& lh, const Pressure& rh);
  double PHYSICSLIBRARY_API operator/ (const Pressure2& lh, const Pressure2& rh);

  Pressure PHYSICSLIBRARY_API sqrt(const Pressure2& r);      // defined in PhysicsMath.cpp

}; // namespace physics

/* Integration with Eigen */
namespace Eigen {
  
  template<> struct NumTraits<physics::Pressure> : NumTraits<double> {
    typedef physics::Pressure Real;
    typedef physics::Pressure NonInteger;
    typedef physics::Pressure Nested;

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

using physics::operator"" _Pa;        using physics::operator"" _kPa;
using physics::operator"" _MPa;       using physics::operator"" _GPa;
using physics::operator"" _psi;       using physics::operator"" _ksi;

#endif
