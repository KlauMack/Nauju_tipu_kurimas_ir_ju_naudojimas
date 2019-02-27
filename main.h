#include <vector>
#include <string>

#ifndef HEADER_H
#define HEADER_H

struct studentas
{
    std::string vardas, pavarde;
    int n = 0, egz;
    std::vector<int> nd;
    double vidurkis, mediana;
};

extern std::vector<studentas> stud;

void print ();
void read ();
void galutinis (int z);

#endif
