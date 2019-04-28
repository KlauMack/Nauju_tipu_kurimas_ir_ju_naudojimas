# 1.0 versija su ```std::list``` konteineriu
## 1 strategija
- Studentų dalijimas:
  - Konteineris ```stud```, kuris laiko studentų duomenis, suskaidomas ir atitinkamai nukopijuojamas į du naujus to paties tipo konteinerius: 
  ```vargsiukai``` (jei galutinis rezultatų balas žemesnis nei 5) ir ```kietiakai``` (jei galutinis rezultatų balas aukštesnis arba lygus 5) 
  - Studentų duomenys esantys konteineryje ```vargsiukai``` įrašomi į failą ```vargšiukai.txt```
  - Studentų duomenys esantys konteineryje ```kietiakai``` įrašomi į failą ```kietiakai.txt```.
  Visos programos veikimo laikas - vidurkis, gaunamas paleidžiant programą 5 kartus
- Duomenų failą sudaro 10000 studentų įrašų.
```shell
Programos paleidimo laikai:
1.  0,966163 s
2.  0,971062 s
3.  0,985942 s
4.  1,00205 s
5.  1,00404 s

Galutinis programos laikas: 0,9858514 s
```
## 2 strategija
- Studentų dalijimas:
  - Jei studento galutinis rezultatų vidurkis mažesnis nei 5, jis iš konteinerio ```stud``` nukopijuojamas į to paties tipo kontenerį ```vargsiukai```;
  - Tada tie studentai, kurių galutinis rezultatų vidurkis žemesnis už 5, panaikinami iš konteinerio ```stud```
  - Studentų duomenys esantys konteineryje ```vargsiukai``` įrašomi į failą ```vargšiukai.txt```
  - Studentų duomenys esantys konteineryje ```stud``` įrašomi į failą ```kietiakai.txt```.
  Visos programos veikimo laikas - vidurkis, gaunamas paleidžiant programą 5 kartus
- Duomenų failą sudaro 10000 studentų įrašų.
```shell
Programos paleidimo laikai:
1.  0,956486 s
2.  0,958349 s
3.  0,977253 s
4.  0,972965 s
5.  0,990045 s

Galutinis programos laikas:  0.9710196 s
```
## 3 strategija
- Studentų dalijimas:
  - Jei studentų galutinis balų vidrukis mažesnis nei 5, studento **vardas**, **pavardė** ir **galutinis balų vidrukis** įrašomi į ```vargšiukai.txt``` failą
  - Kitu atveju studento duomenys surašomi į ```kietiakai.txt``` failą.
- Visos programos veikimo laikas - vidurkis, gaunamas paleidžiant programą 5 kartus
- Duomenų failą sudaro 10000 studentų įrašų.
```shell
Programos paleidimo laikai:
1.  8,62511 s
2.  8,57646 s
3.  9,14848 s
4.  8,61734 s
5.  8,74043 s

Galutinis programos laikas: 8,741564 s
```
