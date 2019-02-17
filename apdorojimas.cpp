#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>

struct studentas
{
    std::string vardas, pavarde;
    int n = 0, egz;
    std::vector<int> nd;
    double vidurkis, mediana;
};

std::vector<studentas> stud;

void galutinis (int z)
{
    int suma = 0;
    if (stud[z].nd.size() == 1)
    {
        stud[z].vidurkis = 0.4 *  stud[z].nd[0] + 0.6 * stud[z].egz;
        stud[z].mediana = (stud[z].nd[0] + stud[z].egz) / 2;
    }
    else
    {
        for (int i = 0; i < stud[z].nd.size(); i++)
        {
            suma += stud[z].nd[i];
        }
        stud[z].vidurkis = 0.4 *  suma + 0.6 * stud[z].egz;

        stud[z].nd.push_back(stud[z].egz);
        for (int x = 0; x < stud[z].nd.size() - 1; x++)
        {
            for (int y = x + 1; y < stud[z].nd.size(); y++)
            {
                if (stud[z].nd[x] > stud[z].nd[y])
                {
                    std::swap (stud[z].nd[x], stud[z].nd[y]);
                }
            }
        }

        if(stud[z].nd.size() / 2 == 0)
        {
            stud[z].mediana = ((stud[z].nd[stud[z].nd.size() / 2]) + (stud[z].nd[stud[z].nd.size() / 2 + 1])) / 2;
        }
        else
        {
            stud[z].mediana = stud[z].nd[stud[z].nd.size() / 2];
        }
        
    }
}

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
        while (line != "Egzaminas") {
            t++;
            r >> line;
        }
        t = t - 2;
        while (!r.eof()) {
            std::cout << "lol" << std::endl;
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

int main()
{
    read();
    print ();

    return 0;
}