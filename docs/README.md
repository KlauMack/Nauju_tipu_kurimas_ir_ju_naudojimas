# Doxygen dokumentacija
## Dokumentacijos generavimas (turite turėti Doxygen)
- Šiame `README.md` pateikti programoje esantys `Doxygen` komentuojami blokai
```ruby
**student.h**
/*! file student.h
    Failas saugantis Base ir Derived klases.
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>

/*! Base klasė "StudentBase" */

class StudentBase
{
protected:
    std::string vardas_;
    std::string pavarde_;
    std::vector<double> nd_;
    double egz_;
    StudentBase() : egz_(0) {}
    StudentBase(std::string, std::string, std::vector<double>&, double);
};

/*! Derived klasė "Studentas" */

class Studentas : public StudentBase
{
public:
    Studentas(std::string vardas, std::string pavarde, std::vector<double>& ND, double egzaminas) : 
        StudentBase(vardas, pavarde, ND, egzaminas) {}

    std::string getVardas() const;
    std::string getPavarde() const;
    double getEgz() const;
    int getSizeOfNd() const;
    double getNd(int i) const;
    void sortND();
};
```
**student.cpp**
```ruby
/*! \file student.cpp
    Klasių realizacijos failas.
*/
#include "student.h"

StudentBase::StudentBase(std::string vardas, std::string pavarde, std::vector<double>& ND, double egzaminas)
{
    vardas_ = vardas;
    pavarde_ = pavarde;
    nd_ = ND;
    egz_ = egzaminas;
}
```
**functions.h**
```ruby
/*! \file functions.h
    Failas, saugantis funkcijas, nesusijusias su klasėmis.
*/
...
/*! Funkcija generuoti "kursiokai.txt" failą */

void generate(int count)
...
/*! Funkcija, perskaityti "kursiokai.txt" failą */

void readGenerated(std::vector<Studentas>& newVec)
...
/*! Funkcija, išsaugoti vartotojo įvestus duomenis */

void readUser(std::vector<Studentas>& newVec)
...
/*! Funkcija, skaičiuojanti vidurkį ir išvedanti duomenis į "kietiakai.txt" ir "vargšiukai.txt" failus */

void vidurkis(const std::vector<Studentas>& newVec)
...
/*! Funkcija, skaičiuojanti medianą ir išvedanti duomenis į "kietiakai.txt" ir "vargšiukai.txt" failus */

void mediana(const std::vector<Studentas>& newVec)
...
/*! Funkcija, išvedanti klasės vektoriaus turinį */

void displayVector(const std::vector<Studentas>& newVec)
```