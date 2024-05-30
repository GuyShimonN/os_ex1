#include "Poisson.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Check if the number of arguments is exactly 3 (program name, lambda, k)
    if (argc != 3) {
        std::cout << "Error\n";
        return 1;
    }

    // Parse lambda and k from the command line arguments
    double lambda = std::atof(argv[1]);
    int k = std::atoi(argv[2]);

    // Calculate the Poisson probability
    long double poissonProbability = poisson(k, lambda);

    // Print the result with high precision
    std::cout.precision(30);
    std::cout << poissonProbability << std::endl;

    return 0;
}