# Naujų tipų kūrimas ir jų naudojimas
## Programos tikslas
- Programa nuskaito šiuos studentų duomenis:
  - **vardą** ir **pavardę**
  - *n* atliktų **namų darbų** (`nd`) rezultatus (10-balėje sistemoje) ir egzamino (`egz`) rezultatą.
- Iš šių duomenų programa suskaičiuoja galutinį balą.
## Išvedimo pavyzdys:
```shell
Vardas    Pavardė     Galutinis
----------------------------
Vardas1   Pavardė1    x.xx
Vardas2   Pavardė2    y.yy
...
```
## Įdiegimas (Unix kompiuteryje) naudojant `gcc`kompiliatorių 

- `git clone https://github.com/KlauMack/Nauju_tipu_kurimas_ir_ju_naudojimas.git`
- `cd Nauju_tipu_kurimas_ir_ju_naudojimas`
- `make`
- `./tipas`
## Versijų istorija (changelog)
### v2.0

**Pridėta:**

# Google Test
- `./runTest` failo sukūrimo instrukcijos:
   - ```cmake CMakeLists.txt```
   - ```make```
   - ```./runTests```
- Jei iškyla nesklandumų su programos paleidimu, galite vykdyti šias instrukcijas (`Ubuntu`):
   - Įdiekite `gtest` plėtros paketą:
`sudo apt-get install libgtest-dev`
   - Įdiegti `source` failai turėtų atsirasti `/usr/src/gtest` vietoje. Tuomet, įdiekite `cmake`:
`sudo apt-get install cmake`
`cd /usr/src/gtest`
`sudo cmake CMakeLists.txt`
`sudo make`
   - Nukopijuokite `libgtest.a` ir `libgtest_main.a` į savo `/usr/lib` aplankalą:
`sudo cp *.a /usr/lib`
   - Toliau vykdykite `./runTest` failo sukūrimo instrukcijas
- **`CMakeLists.txt`:**
```ruby
cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests test/test_student.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTests ${GTEST_LIBRARIES} gtest_main pthread)
```
- **`test_student.cpp:`**
```ruby
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
```
- Testuojama, ar `Studentas` klasė grąžina tikėtinus rezultatus (vardą, pavardę, namų darbų rezultatų vekotriaus dydį bei egzamino rezultatą)
```ruby
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
```
- Testuojami `overloaded` operatoriai pagal duotus studentų vardus.
```ruby
int main (int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
- `main` funkcija

**Rezultatai:**
```Ruby
[==========] Running 2 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from StudentTest
[ RUN      ] StudentTest.testClass
[       OK ] StudentTest.testClass (0 ms)
[----------] 1 test from StudentTest (0 ms total)

[----------] 1 test from OperatorTest
[ RUN      ] OperatorTest.testOperators
[       OK ] OperatorTest.testOperators (0 ms)
[----------] 1 test from OperatorTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test cases ran. (2 ms total)
[  PASSED  ] 2 tests.
```

### v1.51

**Pridėta:**

- 3 operatoriai, tačiau nepanaudoti programoje
```ruby
bool operator >(Studentas & s1, Studentas & s2)
{
	return s1.getVardas() < s2.getVardas();
}
```
```ruby
bool operator <=(Studentas & s1, Studentas & s2)
{
	return s1.getVardas() < s2.getVardas();
}
```
```ruby
bool operator >=(Studentas & s1, Studentas & s2)
{
	return s1.getVardas() < s2.getVardas();
}
```

### v1.5

**Pridėta:**

- **Derived** klasė `Studentas`:
`class Studentas : public StudentBase`

**Koreguota:**

- Klasė `Students` tapo **base** klase `StudentBase`
- Programoje kuriami objektai ir kviečiamos funkcijos iš išvestinės `Studentas` klasės:
```shell
std::vector<Studentas> students;

Studentas newStudent(name, surname, temp, exam);

bool operator <(Studentas & s1, Studentas & s2)
{
	return s1.getVardas() < s2.getVardas();
}
```
- Programos veikimo laikas:
```shell
v1.2: 4,66906 s
v1.5: 2.22834 s
```

### v1.2

**Koreguota:**

- `student.h` faile pridėta operatorius (operator<)
```shell
bool operator <(const Student & s1, const Student & s2)
{
	return s1.getVardas() < s2.getVardas();
}
```
- `main.cpp` faile panaudota `std::sort` funkcija
```shell
std::sort(students.begin(), students.end(), operator<);
```
- Visos programos veikimo laikas (su 100000 studentų įrašų)
```shell
v1.1: 2,14142 s
v1.2: 4,66906 s
```

### v1.1

**Koreguota:**

- Sumažintas failų kiekis:
  - ```student.h``` failas saugo *Student* klasę
  - ```functions.h``` failas saugo su klase nesusijusias funkcijas
- Versijų v1.0 ir v1.1 programos spartos lyginimas (programa leidžiama 5 kartus ir gaunamas vidurkis):
```shell
Tikrinama su 10000 studentų

v1.0: 0,0623813 s
v1.1: 0,21713 s
```
```shell
Tikrinama su 100000 studentų

v1.0: 0,752753 s
v1.1: 2,14142 s
```
- Visos programos veikimo laikas priklausomai nuo kompiliatoriaus optimizavimo lygio (su 100000 studentų įrašais):
```shell
default: 2,28562 s
Flag O1: 2,26381 s
Flag O2: 2,2869 s
Flag O3: 2,3517 s
```

### v1.0

- Programos veikimo sparta prieš koreguojant jos dalis: 2,18899 s.

**Koreguota:**

- Pakeistas studento **vardo** rūšiavimo algortimas, pridėta lyginimo funkcija (```compareByLetter```) ir panadutoas ```std::sort``` algoritmas
  - Programos sparta: 0,049468 s.
```shell
for (int x = 0; x < stud.size() - 1; x++)         
{
  for (int y = x + 1; y < stud.size(); y++)
  {  
    if (stud[x].vardas > stud[y].vardas)
    {
      std::swap(stud[x], stud[y]);
    }
  }
}

                    ↓
                    
bool compareByLetter(const studentas &a, const studentas &b)
{
    return a.vardas < b.vardas;
}
------------------------------------------------------------
std::sort(stud.begin(), stud.end(), compareByLetter);
```
- Pakeistas atsitiktinių skaičių generavimo algoritmas:
  - Programos sparta: 0,126222 s.
```shell
std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist (1, 10);
```
### [v0.5.3](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.5.3)

**Koreguota:**

- Matuojamas programos veikimo laikas, naudojant `std::deque` konteinerį
- Skaičiavimai vykdomi iš identiško duomenų failo, kurį sudaro 100 studentų duomenų.
```shell
Programos veikimo laikas (vidurkis iš 5 skaičiavimų): 0,00096704 s
```
### [v0.5.2](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.5.2)

**Koreguota:**

- Matuojamas programos veikimo laikas, naudojant `std::list` konteinerį
- Skaičiavimai vykdomi iš identiško duomenų failo, kurį sudaro 100 studentų duomenų.
```shell
Programos veikimo laikas (vidurkis iš 5 skaičiavimų): 0,00046482 s
```
### [v0.5.1](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.5.1)

**Koreguota:**

- Matuojamas programos veikimo laikas (be failo kūrimo ir studentų duomenų išvedimo į du naujus failus), naudojant `std::vector` konteinerį
- Skaičiavimai vykdomi iš identiško duomenų failo, kurį sudaro 100 studentų duomenų.
```shell
Programos veikimo laikas (vidurkis iš 5 skaičiavimų): 0,00043326 s
```
### [v0.4.1](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.4.1)

**Koreguota:**

- Pridėtas ```main.h``` failas.

### [v0.4](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.4)

**Papildyta:**

- Programa sugeneruoja pasirinktinai duomenų failą su (10, 100, 1000, 10000, 100000) studentų įrašais
- Studentai pagal galutinį balą suskirstomi į dvi kategorijas:
  - **vargšiukai**, jei **galutinis balas < 5**
  - **kietiakai**, jei **galutinis balas >= 5**
- Surūšiuoti studentai išvedami į du naujus failus (```"vargšiukai.txt"```, ```"kietiakai.txt"```)
- Programa išmatuoja visos programos veikimo laiką (naudojant ```<chrono>``` biblioteką) bei šias programos dalis:
  - duomenų failo kūrimas
  - surūšiuotų studentų išvedimas į failus
  
**Laikų rezultatai:**
- Visi skaičiavimai vykdomi, kai studentų namų darbų rezultatų skaičius lygus 5
- Gauti skaičiavimų rezultatai - vidurkis iš 5 skaičiavimų.
- Galutinis balas, kuris buvo pasirinktas skačiuoti - vidurkis.
```shell
Duomenų failą sudaro 10 studentų įrašų
Failo kūrimas:            0,00362138 s
Išvedimas į du failus:    0,00365794 s
Visos prgoramos veikimas: 0,01728572 s

Duomenų failą sudaro 100 studentų įrašų
Failo kūrimas:            0,0212869 s
Išvedimas į du failus:    0,00361348 s
Visos prgoramos veikimas: 0,02436062 s

Duomenų failą sudaro 1000 studentų įrašų
Failo kūrimas:            0,00642516 s
Išvedimas į du failus:    0,0054372 s
Visos prgoramos veikimas: 0,1331356 s

Duomenų failą sudaro 10000 studentų įrašų
Failo kūrimas:            0,0277831 s
Išvedimas į du failus:    0,01065764 s
Visos prgoramos veikimas: 5,705478 s

Duomenų failą sudaro 100000 studentų įrašų
Failo kūrimas:            0,2306435 s
Išvedimas į du failus:    0,1029456 s
Visos prgoramos veikimas: 464,4325 s
```
### [v0.3](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.3)

**Koreguota:**

- Funkcijų aprašai ir struktūros perkeltos į ```header``` failą (```main.h```)
- Panaudotas išimčių valdymas, tikrinant ar programa gali nuskaityti duomenų failą.

### [v0.2](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.2)

**Papildyta:**

- Programa geba nuskaityti duomenis iš failo (```kursiokai.txt```) - sukurkite failą pavadinimu ```kursiokai.txt``` tame pačiame aplankale kaip ir ```source``` failas arba parsisiųskite duomenų failo pavyzdį
- Išvesti studentai surušiuoti pagal vardus (ir pavardes) abecėlės tvarka.

### [v0.1](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.1)

**Papildyta:**

- Iš duomenų suskaičiuojamas galutinis balas (rezultatų **vidurkis** (*Vid*) arba **mediana** (*Med*)) ir išvedama į ekrana pavidalu:
```shell
Vardas   Pavardė   Galutinis (Vid.) / Galutinis (Med.)
------------------------------------------------------
Vardas1  Pavardė1  x.xx
Vardas2  Pavardė2  y.yy
...
```
