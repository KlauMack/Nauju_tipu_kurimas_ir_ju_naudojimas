#include "main.h"
#include <iostream>
#include <chrono>
#include <fstream>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    try {
        read();
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
        return EXIT_FAILURE;
    }
    print ();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Visos programos veikimo laikas: " << diff.count() << " s\n";
    return 0;
}