#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <name> <phone_number>" << std::endl;
        return 1;
    }
//
//    std::string name = argv[1];
//    std::string phone_number = argv[2];

    std::ofstream file("phonebook.txt", std::ios::app); // Open in append mode
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        file << argv[i] << " ";
    }
    file << std::endl;
    file.close();

    return 0;
}
