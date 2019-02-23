#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>

void print ()
{
    for (int x = 0; x < stud.size() - 1; x++) {
        for (int y = x + 1; y < stud.size(); y++) {
             if (stud[x].vardas > stud[y].vardas) {
                    std::swap(stud[x], stud[y]);
            }
        }
    }

    std::string pasirinkti;
    std::cout << "Ka noretumete matyti - vidurki (Vid) ar mediana (Med)? "; std::cin >> pasirinkti;
    if (pasirinkti == "vid" || pasirinkti == "Vid")
    {
        std::cout << "Vardas\t" << "Pavarde\t" << "Galutinis (Vid.)" << std::endl; 
        for (int i = 0; i < 50; i++)
        {
            std::cout << "-";
        }
        std::cout << "\n";

        for (int x = 0; x < stud.size(); x++) {
            std::cout << stud[x].vardas << "\t" << stud[x].pavarde << "\t" << std::fixed << std::setprecision(2) << stud[x].vidurkis << std::endl;
        }
    }

    else
    {
        std::cout << "Vardas\t" << "Pavarde\t" << "Galutinis (Med.)" << std::endl; 
        for (int i = 0; i < 50; i++)
        {
            std::cout << "-";
        }
        std::cout << "\n";

        for (int x = 0; x < stud.size(); x++) {
            std::cout << stud[x].vardas << "\t" << stud[x].pavarde << "\t" << std::fixed << std::setprecision(2) << stud[x].mediana << std::endl;
        }
    }
}