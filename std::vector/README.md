# 1.0 versija su ```std::vector``` konteineriu
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
1.  2,12192 s
2.  2,10967 s
3.  2,12307 s
4.  2,1336 s
5.  2,11773 s

Galutinis programos laikas: 2,21198 s
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
1.  4,89228 s
2.  4,93643 s
3.  4,90829 s
4.  4,88885 s
5.  4,89151 s

Galutinis programos laikas:  4,903472s
```
## 3 strategija
- Studentų dalijimas:
  - Jei studentų galutinis balų vidrukis mažesnis nei 5, studento **vardas**, **pavardė** ir **galutinis balų vidrukis** įrašomi į ```vargšiukai.txt``` failą
  - Kitu atveju studento duomenys surašomi į ```kietiakai.txt``` failą.
- Visos programos veikimo laikas - vidurkis, gaunamas paleidžiant programą 5 kartus
- Duomenų failą sudaro 10000 studentų įrašų.
```shell
Programos paleidimo laikai:
1.  2,23374 s
2.  2,16675 s
3.  2,18962 s
4.  2,16982 s
5.  2,16704 s

Galutinis programos laikas: 2,185396 s
```
