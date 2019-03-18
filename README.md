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

- `git clone https://github.com/KlauMack/Duomenu_apdorojimas.git`
- `cd Duomenu_apdorojimas`
- `g++ -std=c++11 main.o galutinis.o print.o read.o generate.o -o apdorojimas`
- `./apdorojimas`
## Versijų istorija (changelog)
### [v0.5.1](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.5.1)

**Koreguota:**

- Matuojamas programos veikimo laikas, naudojant `std::list` konteinerį.
- Skaičiavimai vykdomi iš identiško duomenų failo, kurį sudaro 100 studentų duomenų.
```shell
Programos veikimo laikas: 0,00046482 s.

### [v0.5.1](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.5.1)

**Koreguota:**

- Matuojamas programos veikimo laikas (be failo kūrimo ir studentų duomenų išvedimo į du naujus failus), naudojant `std::vector` konteinerį.
- Skaičiavimai vykdomi iš identiško duomenų failo, kurį sudaro 100 studentų duomenų.
```shell
Programos veikimo laikas: 0,00043326 s.
### [v0.4.1](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.4.1)

**Koreguota:**

- Pridėtas ```main.h``` failas.

### [v0.4](https://github.com/KlauMack/Duomenu_apdorojimas/releases/tag/v0.4)

**Papildyta:**

- Programa sugeneruoja pasirinktinai duomenų failą su (10, 100, 1000, 10000, 100000) studentų įrašais.
- Studentai pagal galutinį balą suskirstomi į dvi kategorijas:
  - **vargšiukai**, jei **galutinis balas < 5**
  - **kietiakai**, jei **galutinis balas >= 5**
- Surūšiuoti studentai išvedami į du naujus failus (```"vargšiukai.txt", "kietiakai.txt"```)
- Programa išmatuoja visos programos veikimo laiką (naudojant ```<chrono>``` biblioteką) bei šias programos dalis:
  - duomenų failo kūrimas
  - surūšiuotų studentų išvedimas į failus
  
**Laikų rezultatai:**
- Visi skaičiavimai vykdomi, kai studentų namų darbų rezultatų skaičius lygus 5.
```shell
Duomenų failą sudaro 10 studentų įrašų
Failo kūrimas:
Išvedimas į du failus:
Visos prgoramos veikimas:

Duomenų failą sudaro 100 studentų įrašų
Failo kūrimas:
Išvedimas į du failus:
Visos prgoramos veikimas:

Duomenų failą sudaro 1000 studentų įrašų
Failo kūrimas:
Išvedimas į du failus:
Visos prgoramos veikimas:

Duomenų failą sudaro 10000 studentų įrašų
Failo kūrimas:
Išvedimas į du failus:
Visos prgoramos veikimas:

Duomenų failą sudaro 100000 studentų įrašų
Failo kūrimas:
Išvedimas į du failus:
Visos prgoramos veikimas:
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
