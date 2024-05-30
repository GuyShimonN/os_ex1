//
// Created by guy on 5/13/24.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "dijkstra.h"
using namespace std;

void test_dijkstra() {
    // Redirect the standard input to read from the file
    ifstream in("input.txt");
    streambuf *cinbuf = cin.rdbuf(); // Save old buf
    cin.rdbuf(in.rdbuf()); // Redirect cin to in.txt!

    // Call the main function
    run_dijkstra();

    // Reset the standard input
    cin.rdbuf(cinbuf); // Reset to standard input again
}

int main() {
    test_dijkstra();
    return 0;
}