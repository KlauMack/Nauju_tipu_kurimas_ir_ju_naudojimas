#include "student.h"

Student::Student(std::string vardas, std::string pavarde, std::vector<double>& ND, double egzaminas)
{
    vardas_ = vardas;
    pavarde_ = pavarde;
    nd_ = ND;
    egz_ = egzaminas;
}

std::string Student::getVardas() const
{
    return vardas_;
}

std::string Student::getPavarde() const
{
    return pavarde_;
}

double Student::getEgz() const
{
    return egz_;
}

int Student::getSizeOfNd() const
{
    return nd_.size();
}

double Student::getNd(int i) const
{
    return nd_[i];
}

void Student::sortND()
{
    std::sort(nd_.begin(), nd_.end());
}