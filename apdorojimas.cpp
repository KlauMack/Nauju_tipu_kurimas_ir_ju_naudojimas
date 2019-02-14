#include <iostream>
#include <string>
#include <iomanip>

struct studentas
{
    std::string vardas, pavarde;
    double nd, egz, galutinis;
};

studentas A[20];

void read (int a)
{
    for (int i = 0; i < a; i++)
    {
        std::cout << "Iveskite studento varda ir pavarde." << std::endl;
        std::cout << "Vardas: "; std::cin >> A[i].vardas;
        std::cout << "Pavarde: "; std::cin >> A[i].pavarde;
        std::cout << "Iveskite studento namu darbu ir egzamino rezultatus (10-baleje sistemoje)." << std::endl;
        std::cout << "Namu darbai: "; std::cin >> A[i].nd;
        std::cout << "Egzaminas: "; std::cin >> A[i].egz;
    }
}

void print (int a)
{
    std::cout << "Vardas\t" << "Pavarde\t" << "Galutinis (Vid.)" << std::endl; 
    for (int i = 0; i < 50; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";

    for (int x = 0; x < a; x++)
    {
        std::cout << A[x].vardas << "\t" << A[x].pavarde << "\t" << std::fixed << std::setprecision(2) << A[x].galutinis << std::endl;
    }
}

void galutinis (int a)
{
    for (int i = 0; i < a; i++)
    {
        A[i].galutinis = 0.4 * A[i].nd + 0.6 * A[i].egz;
    }
}

int main()
{
    int sk;
    std::cout << "Iveskite studentu skaiciu: "; std::cin >> sk;

    read(sk);
    galutinis (sk);
    print (sk);

    return 0;
}