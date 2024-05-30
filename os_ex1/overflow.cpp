//
// Created by guy on 5/16/24.
//
#include <iostream>

void recurse_forever(int depth) {
//    std::cout << "Depth: " << depth << std::endl;
    recurse_forever(depth + 1);
}

int main() {
    recurse_forever(1);
    return 0;
}
// The above code will cause a stack overflow. The stack overflow will cause the program to crash.

// To compile and debug the code, run the following command:

//ulimit -c unlimited

//./overflow

//gdb overflow core

//ddd  gdb ./Overflow /var/lib/apport/coredump/