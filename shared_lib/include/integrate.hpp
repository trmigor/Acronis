// "Copyright [2020] <Taraymovich Igor>"
#ifndef SHARED_LIB_INCLUDE_INTEGRATE_HPP_
#define SHARED_LIB_INCLUDE_INTEGRATE_HPP_

namespace integrate {

typedef double func(double);

double Integrate(func F, double left, double right, double eps);

}  // namespace integrate

#endif  // SHARED_LIB_INCLUDE_INTEGRATE_HPP_
