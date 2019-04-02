# Duomenų apdorojimas
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

- `git clone https://github.com/KlauMack/Duomenu-apdorojimas.git`
- `cd Duomenu_apdorojimas`
- `make`
- `./apdorojimas`
## Versijų istorija (changelog)
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
