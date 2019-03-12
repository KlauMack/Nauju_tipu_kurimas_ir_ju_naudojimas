#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>

void galutinis (int z)
{
    std::list<studentas>::iterator it = std::next(stud.begin(), z);
    int suma = 0;
    double Vidurkis;
    /*if (it.nd.size() == 1)
    {
        it.vidurkis = 0.4 *  k + 0.6 * it.egz;
        (*it1).mediana = (*it2 + (*it1).egz) / 2;
    }*/
    //else
    //{
        for (int i = 0; i < it->nd.size(); i++)
        {
            suma += it->nd[i];
        }
        Vidurkis = (double) suma / it->nd.size();
        it->vidurkis = 0.4 *  Vidurkis + 0.6 * it->egz;

        it->nd.push_back(it->egz);
        sort(it->nd.begin(), it->nd.end());

        /*if((*it1).nd.size() % 2 == 0)
        {
            (*it1).mediana = (double)(((*it1).nd[(*it1).nd.size() / 2 - 1]) + ((*it1).nd[(*it1).nd.size() / 2])) / 2;
        }
        else
        {
            (*it1).mediana = (double)(*it1).nd[(*it1).nd.size() / 2];
        }*/
        
   // }
}