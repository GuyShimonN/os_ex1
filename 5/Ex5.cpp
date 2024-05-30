#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#define minus -100
void alg1(std::vector<int>& arr) {
    int best = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i; j < arr.size(); j++) {
            int sum = 0;
            for (size_t m = i; m <= j; m++) {
                sum += arr[m];
            }
            best = std::max(best, sum);
        }
    }
    std::cout << "Algorithm 1 Best: " << best << std::endl;
}

void alg2(std::vector<int>& arr) {
    int best = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (size_t j = i; j < arr.size(); j++) {
            sum += arr[j];
            best = std::max(best, sum);
        }
    }
    std::cout << "Algorithm 2 Best: " << best << std::endl;
}

void alg3(std::vector<int>& arr) {
    int best = 0, sum = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        sum = std::max(arr[i], sum + arr[i]);
        best = std::max(best, sum);
    }
    std::cout << "Algorithm 3 Best: " << best << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <num_elements>" << std::endl;
        return 1;
    }
    int seed = std::stoi(argv[1]);
    int num_elements = std::stoi(argv[2]);
    std::vector<int> arr;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minus, seed);

    for (int i = 0; i < num_elements; i++) {
        arr.push_back(distrib(gen));
    }

    alg1(arr);
    alg2(arr);
    alg3(arr);

    return 0;
}
