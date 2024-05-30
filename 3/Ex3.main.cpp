#include <iostream>
#include <cstdlib>
#include "Ex3lib.hpp"

int main() {
    long double p_x_k = poisson_distribution(2.0, 1);
    std::cout.precision(40);
    std::cout << "p_X(k=1) = " << p_x_k << std::endl;

    p_x_k = poisson_distribution(2.0, 10);
    std::cout.precision(40);
    std::cout << "p_X(k=10) = " << p_x_k << std::endl;

    p_x_k = poisson_distribution(2.0, 2);
    std::cout.precision(40);
    std::cout << "p_X(k=2) = " << p_x_k << std::endl;

    p_x_k = poisson_distribution(3.0, 3);
    std::cout.precision(40);
    std::cout << "p_X(k=3) = " << p_x_k << std::endl;

    p_x_k = poisson_distribution(100.0, 3);
    std::cout.precision(40);
    std::cout << "p_X(k=100) = " << p_x_k << std::endl;

    return 0;
}