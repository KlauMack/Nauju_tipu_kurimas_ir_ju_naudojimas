#include "main.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>

void generate (int a)
{
    if (a == 10 || a == 100 || a == 1000 || a == 10000 || a == 100000)
    {
        auto start = std::chrono::high_resolution_clock::now();

        std::ofstream outfile ("kursiokai.txt");
        srand (time(NULL));
        int number;

        outfile << "Vardas\t" << "Pavarde\t";
        for (int i = 1; i <= 5; i++)
        {
            outfile << "ND" << i << "\t";
        }
        outfile << "Egzaminas" << std::endl;

        for (int x = 1; x < a; x++)
        {
            outfile << "Vardas" << x << "\t" << "Pavarde" << x << "\t";
            for (int y = 1; y <= 6; y++)
            {
                number = rand() % 10 + 1;
                outfile << number << "\t";
            }
            outfile << "\n";
        }

        outfile << "Vardas" << a << " " << "Pavarde" << a << " ";
        for (int y = 1; y <= 6; y++)
        {
            number = rand() % 10 + 1;
            outfile << number << "\t";
        }
        outfile.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Failo kūrimo laikas sekundėmis: " << diff.count() << " s\n";
    }
    else
    {
        std::cout << "Prašome pasirinkti sugeneruoti 10, 100, 1000, 10000, 100000 studentų duomenų įrašus." << std::endl;
    }
}