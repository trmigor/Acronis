// "Copyright [2020] <Taraymovich Igor>"
#include "integrate.hpp"

namespace integrate {

double Integrate(func F, double left, double right, double eps) {
    double sum = 0;
    for (double x = left + eps; x <= right - eps; x += eps) {
        sum += F(x);
    }
    sum += (F(left) + F(right)) / 2;

    return sum * eps;
}

}  // namespace integrate
