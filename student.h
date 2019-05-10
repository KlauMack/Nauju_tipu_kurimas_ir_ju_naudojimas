#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>

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

bool operator <(Studentas & s1, Studentas & s2)
{
	return s1.getVardas() < s2.getVardas();
}

#endif