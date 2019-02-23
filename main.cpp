#include "main.h"
#include <iostream>

int main()
{
    try {
        read();
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
        return EXIT_FAILURE;
    }
    print ();

    return 0;
}