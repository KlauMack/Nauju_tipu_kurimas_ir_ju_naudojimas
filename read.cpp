#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <list>
#include <time.h>
#include <iterator>
#include <vector>

std::list<studentas> stud;

void read ()
{
    char input;
    float genNumber;
    int i = 0;
    //std::cout << "Ar norite nuskaityti duomenis iš failo (kursiokai.txt)?" << std::endl;
    //std::cout << "Jei taip, rašykite t, jei ne - n: "; std::cin >> input;
    input = 't';
    if(input == 't') {
        //std::cout << "Pasirinkite sugeneruoti 10, 100, 1000, 10000, 100000 studentų duomenų įrašų: "; std::cin >> genNumber;
        //genNumber = 100;
        //generate (genNumber);

        std::ifstream r ("kursiokai.txt");
        std::string line;
        int number, t = 0;

        r >> line;
        if (r.eof()) {
            throw "File failed to open.";
        }

        while (line != "Egzaminas") {
            t++;
            r >> line;
        }
        t = t - 2;

        while (!r.eof()) {
            studentas s;
            r >> s.vardas;
            r >> s.pavarde;
            for (int q = 0; q < t; q++) {
                r >> number;
                s.nd.push_back(number);
            }
            r >> s.egz;
            stud.push_back(s);
            if (i == genNumber) {
                stud.pop_back();
            }
            galutinis (i); 
            ++i;
        }
        r.close();
        stud.clear();
        }
    /*else
    {
        std::advance(j, i);
        int a;
        std::cout << "Įveskite studento vardą(-us) ir pavardę(-es)." << std::endl;
        std::string v;
        std::cout << "Vardas: "; std::cin >> v;
        while (v != "0") {
            srand (time(NULL));
            stud.push_back(studentas());
            j.vardas = v;
            std::cout << "Pavardė: "; std::cin >> j.pavarde;
            std::cout << "Ar norite, kad studentų namų darbų ir egzaminų rezultatai būtų generuojami atsitiktinai?" << std::endl;
            std::cout << "Jei taip, rašykite - t, jei ne - n: "; std::cin >> input;
            if (input == 't') {
                std::cout << "Įveskite namų darbų rezultatų kiekį: "; std::cin >> j.n;
                for (int x = 0; x < j.n; x++) {
                    j.nd.push_back(rand() % 10 + 1);
                }
                j.egz = rand() % 10 + 1;
            }
            else {
                std::cout << "Įveskite studento namų darbų ir egzamino rezultatus (10-balėje sistemoje)." << std::endl;
                std::cout << "Namu darbai (baigę įveskite 0): "; std::cin >> a;
                while (a != 0) {
                    j.nd.push_back(a);
                    std::cin >> a;
                }
                //std::cout << "Egzaminas: "; std::cin >> (*it2).egz;
            }
            galutinis (i);
            i++;
            std::cout << "Vardas (spauskite 0, jei norite baigti): "; std::cin >> v;
        }
    }*/
}