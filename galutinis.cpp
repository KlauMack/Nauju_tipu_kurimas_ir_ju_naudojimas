#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

void galutinis (int z)
{
    int suma = 0;
    double Vidurkis;
    if (stud[z].nd.size() == 1)
    {
        stud[z].vidurkis = 0.4 *  stud[z].nd[0] + 0.6 * stud[z].egz;
        stud[z].mediana = (stud[z].nd[0] + stud[z].egz) / 2;
    }
    else
    {
        for (int i = 0; i < stud[z].nd.size(); i++)
        {
            suma += stud[z].nd[i];
        }
        Vidurkis = (double) suma / stud[z].nd.size();
        stud[z].vidurkis = 0.4 *  Vidurkis + 0.6 * stud[z].egz;

        stud[z].nd.push_back(stud[z].egz);
        sort(stud[z].nd.begin(), stud[z].nd.end());

        if(stud[z].nd.size() % 2 == 0)
        {
            stud[z].mediana = (double)((stud[z].nd[stud[z].nd.size() / 2 - 1]) + (stud[z].nd[stud[z].nd.size() / 2])) / 2;
        }
        else
        {
            stud[z].mediana = (double)stud[z].nd[stud[z].nd.size() / 2];
        }
        
    }
}