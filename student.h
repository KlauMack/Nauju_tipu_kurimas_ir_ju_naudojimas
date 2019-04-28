#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>

class Student
{
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<double> nd_;
    double egz_;
public:
    Student() : egz_(0) {}
    Student(std::string, std::string, std::vector<double>&, double);
    std::string getVardas() const;
    std::string getPavarde() const;
    double getEgz() const;
    int getSizeOfNd() const;
    double getNd(int i) const;
    void sortND();
};

bool operator <(const Student & s1, const Student & s2)
{
	return s1.getVardas() < s2.getVardas();
}

#endif