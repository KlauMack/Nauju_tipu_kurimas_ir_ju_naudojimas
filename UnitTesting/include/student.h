/*! \file student.h
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

inline bool operator <(Studentas s1, Studentas s2)
{
	return s1.getVardas() < s2.getVardas();
}

inline bool operator >(Studentas s1, Studentas s2)
{
	return s1.getVardas() < s2.getVardas();
}

inline bool operator <=(Studentas s1, Studentas s2)
{
	return s1.getVardas() < s2.getVardas();
}

inline bool operator >=(Studentas s1, Studentas s2)
{
	return s1.getVardas() < s2.getVardas();
}

#endif