#include <cmath>

long double poisson_distribution(double lambda, int k) {
    // Check for invalid input (optional)
    if (lambda < 0 || k < 0) {
        return -1.0;
    }

    // Calculate lambda^k using powl for long double precision
    long double lambda_k = powl(lambda, k);

    // Calculate e^-lambda using expl for long double precision
    long double exp_neg_lambda = expl(-lambda);

    // Calculate k! (factorial of k)
    long double k_factorial = 1;
    for (int i = 1; i <= k; ++i) {
        k_factorial *= i;
    }

    // Calculate p_X(k)
    long double p_x_k = (lambda_k * exp_neg_lambda) / k_factorial;

    return p_x_k;
}