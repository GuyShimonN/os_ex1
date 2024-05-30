#include <iostream>
#include "Poisson.h"

int main() {
    double lambdas[5] = {2, 2, 2, 3, 100};
    int ks[5] = {1, 10, 2, 3, 3};

    for (int i = 0; i < 5; i++) {
        std::cout.precision(15);  // Set precision for long double output
        std::cout << poisson(ks[i], lambdas[i]) << std::endl;
    }

    return 0;
}
