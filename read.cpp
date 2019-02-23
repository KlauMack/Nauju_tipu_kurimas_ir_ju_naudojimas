#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

std::vector<studentas> stud;

void read ()
{
    char input;
    int i = 0;
    std::cout << "Ar norite nuskaityti duomenis is failo kursiokai.txt?" << std::endl;
    std::cout << "Jei taip rasykite t, jei ne - n: "; std::cin >> input;
    if(input == 't') {
        std::ifstream r ("kursiokai.txt");
        std::string line;
        int number, t = 0;
        r >> line;
        if (!r) {
            throw "File failed to open.";
        }
        while (line != "Egzaminas") {
            t++;
            r >> line;
        }
        t = t - 2;
        while (!r.eof()) {
            stud.push_back(studentas());
            r >> stud[i].vardas;
            r >> stud[i].pavarde;
            for (int y = 0; y < t; y++) {
                r >> number;
                stud[i].nd.push_back(number);
            }
            r >> stud[i].egz;
            galutinis (i); 
            i++;
        }
        r.close();
    }
    else
    {
        int a;
        std::cout << "Iveskite studento varda ir pavarde." << std::endl;
        std::string v;
        std::cout << "Vardas: "; std::cin >> v;
        while (v != "0") {
            srand (time(NULL));
            stud.push_back(studentas());
            stud[i].vardas = v;
            std::cout << "Pavarde: "; std::cin >> stud[i].pavarde;
            std::cout << "Ar norite, kad studentu namu darbu ir egzaminu rezultatai butu generuojami atsitiktinai?" << std::endl;
            std::cout << "Jei taip rasykite - t, jei ne - n: "; std::cin >> input;
            if (input == 't') {
                std::cout << "Iveskite namu darbu rezultatu kieki: "; std::cin >> stud[i].n;
                for (int x = 0; x < stud[i].n; x++) {
                    stud[i].nd.push_back(rand() % 10 + 1);
                }
                stud[i].egz = rand() % 10 + 1;
            }
            else {
                std::cout << "Iveskite studento namu darbu ir egzamino rezultatus (10-baleje sistemoje)." << std::endl;
                std::cout << "Namu darbai (baige iveskite 0): "; std::cin >> a;
                while (a != 0) {
                    stud[i].nd.push_back(a);
                    std::cin >> a;
                }
                std::cout << "Egzaminas: "; std::cin >> stud[i].egz;
            }
            galutinis (i);
            i++;
            std::cout << "Vardas (spauskite 0, jei norite praleisti): "; std::cin >> v;
        }
    }
}