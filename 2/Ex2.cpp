#include <iostream>
#include <cmath>
#include <cstdlib> // For exit and EXIT_FAILURE

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr <<"Error \n";
        exit(EXIT_FAILURE);
    }

    // Parse input using std::stold for long double and std::stoi for integer
    long double lambda = std::stold(argv[1]);
    int k = std::stoi(argv[2]);

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

    // Print the result with high precision
    std::cout.precision(40); // Set precision to 20 digits
    std::cout << "p_X(" << k << ") = " << p_x_k << std::endl;

    return 0;
}