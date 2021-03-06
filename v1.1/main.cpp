#include "student.h"
#include "functions.h"
#include <iostream>
#include <algorithm>
#include <chrono>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<Student> students;

    std::string input1 = "taip";
    //std::cout << "Ar norite nuskaityti duomenis iš failo (kursiokai.txt)? (taip/ne) "; std::cin >> input1;
    if(input1 == "taip")
    {
        int count = 10000;
        //std::cout << "Kiek studentų norėtumėte sugeneruoti? "; std::cin >> count;
        if (count == 0)
        {
            std::cerr << "Prašome sugeneruoti nors vieną studentą" << std::endl;
            exit(1);
        }
        generate(count);
        try
        {
            readGenerated(students);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else if (input1 == "ne")
    {
        readUser(students);
    }
    else
    {
        std::cerr << "Prašome pasirinkti taip arba ne" << std::endl;
        exit(1);
    }
    
    std::sort(std::begin(students), std::end(students), compareNames);

    for(int i = 0; i < students.size(); i++)
    {
        students[i].sortND();
    }

    std::string input2 = "vid";
    //std::cout << "Ką norėtumėte matyti - vidurkį (vid) ar medianą (med)? (vid/med) "; std::cin >> input2;
    if (input2 == "vid")
    {
        vidurkis(students);
    }
    else if (input2 == "med")
    {
        mediana(students);
    }
    else
    {
        std::cerr << "Prašome pasirinkti vid arba med" << std::endl;
        exit(1);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Visos programos veikimo laikas: " << diff.count() << " s\n";
}