#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <chrono>

void print ()
{
    for (int x = 0; x < stud.size() - 1; x++) {
        for (int y = x + 1; y < stud.size(); y++) {
             if (stud[x].vardas > stud[y].vardas) {
                    std::swap(stud[x], stud[y]);
            }
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream v;
    v.open ("vargšiukai.txt");
    std::ofstream k;
    k.open ("kietiakai.txt");

    std::string pasirinkti;
    //std::cout << "Ką norėtumėte matyti - vidurkį (Vid) ar medianą (Med)? "; std::cin >> pasirinkti;
    pasirinkti = "vid";
    if (pasirinkti == "vid" || pasirinkti == "Vid")
    {
        /*std::cout << "Vardas\t" << "Pavarde\t" << "Galutinis (Vid.)" << std::endl; 
        for (int i = 0; i < 50; i++)
        {
            std::cout << "-";
        }
        std::cout << "\n";
        */
        for (int x = 0; x < stud.size(); x++) {
            //std::cout << stud[x].vardas << " " << stud[x].pavarde << "\t" << std::fixed << std::setprecision(2) << stud[x].vidurkis << std::endl;
            if (stud[x].vidurkis < 5)
                v << stud[x].vardas << " " << stud[x].pavarde << "\t" << std::fixed << std::setprecision(2) << stud[x].vidurkis << "\r\n";
            else
                k << stud[x].vardas << " " << stud[x].pavarde << "\t" << std::fixed << std::setprecision(2) << stud[x].vidurkis << "\r\n";
        }
        v.close();
        k.close();
    }

    else
    {
        /*std::cout << "Vardas\t" << "Pavarde\t" << "Galutinis (Med.)" << std::endl; 
        for (int i = 0; i < 50; i++)
        {
            std::cout << "-";
        }
        std::cout << "\n";*/

        for (int x = 0; x < stud.size(); x++) {
            //std::cout << stud[x].vardas << " " << stud[x].pavarde << " " << std::fixed << std::setprecision(2) << stud[x].mediana << std::endl;
            if (stud[x].mediana < 5)
                v << stud[x].vardas << " " << stud[x].pavarde << "\t" << std::fixed << std::setprecision(2) << stud[x].mediana << "\r\n";
            else
                k << stud[x].vardas << " " << stud[x].pavarde << "\t" << std::fixed << std::setprecision(2) << stud[x].mediana << "\r\n";
        }
        v.close();
        k.close();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Išvedimo į du naujus failus laikas: " << diff.count() << " s\n";
}