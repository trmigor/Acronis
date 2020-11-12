// "Copyright [2020] <Taraymovich Igor>"
#include <iostream>
#include "integrate.hpp"

double square(double x) {
    return x * x;
}

int main(int argc, char* argv[]) {
    double left_border = 0;
    double right_border = 1;
    double eps = 1e-7;

    if (argc >= 3) {
        left_border = std::stod(argv[1]);
        right_border = std::stod(argv[2]);
    }
    if (argc >= 4) {
        eps = std::stod(argv[3]);
    }

    double I = integrate::Integrate(square, left_border, right_border, eps);

    std::cout << "Integrate function: f(x) = x^2;" << std::endl;
    std::cout << "Left border: " << left_border << ";" << std::endl;
    std::cout << "Right border: " << right_border << ";" << std::endl;
    std::cout << "Result: " << I << "." << std::endl;

    return EXIT_SUCCESS;
}
