#include <iostream>
#include <cmath> // Include cmath for exp and pow functions
#include <cstdlib> // Include cstdlib for atoi and atof functions
#include "Poisson.h"
// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0) return 1;
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to calculate Poisson probability
long double poisson(int k, double lambda) {
    return (std::exp(-lambda) * std::pow(lambda, k)) / factorial(k);
}
