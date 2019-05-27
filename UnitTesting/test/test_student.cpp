#include <gtest/gtest.h>
#include "../include/student.h"
#include "../src/student.cpp"
#include <vector>
#include <string>

TEST (StudentTest, testClass)
{
    std::string name = "Klaudijus";
    std::string surname = "Mackonis";
    std::vector<double> temp {1, 2, 3};
    double exam = 4;
    Studentas newStudent(name, surname, temp, exam);

    EXPECT_EQ(newStudent.getVardas(), "Klaudijus");
    EXPECT_EQ(newStudent.getPavarde(), "Mackonis");
    EXPECT_EQ(newStudent.getSizeOfNd(), 3);
    EXPECT_EQ(newStudent.getEgz(), 4);
}

TEST (OperatorTest, testOperators)
{
    std::vector<Studentas> students;

    std::string name = "Klaudijus";
    std::string surname = "Mackonis";
    std::vector<double> temp {1, 2, 3};
    double exam = 4;
    Studentas newStudent(name, surname, temp, exam);
    students.push_back(newStudent);

    name = "Mackonis";
    surname = "Klaudijus";
    temp = {2, 3, 4};
    exam = 5;
    Studentas newStudent1(name, surname, temp, exam);
    students.push_back(newStudent1);

    EXPECT_FALSE(operator>(students[0].getVardas(), students[1].getVardas()));
    EXPECT_FALSE(operator<(students[1].getVardas(), students[0].getVardas()));
}

int main (int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}