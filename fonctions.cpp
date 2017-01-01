#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fonctions.h"

using namespace std;


void multiplier(point* A,float transformation[4][4])
{
    float temp[4];
    cout << "Coordonnee du point traite :" << endl;
    for(int i = 0 ; i < 4 ; i++)
    {
       cout <<"|" << A->coord_p[i]<< endl;;
    }

    cout << "Matrice de traitement : " << endl;
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            cout << "|" << transformation[i][j] << "|" ;
        }
        cout << endl;
    }

    for (int i = 0 ; i < 4 ; i ++)
    {
        temp[i] = 0;
        for (int j = 0 ; j < 4 ; j ++)
        {
            temp[i] = transformation[i][j]*A->coord_p[j] + temp[i];
        }
    }

    cout << "Coordonnee du point apres traitement :" << endl;
    for (int i = 0; i < 4 ; i ++)
    {
        A->coord_p[i]=temp[i];
        cout <<"|" << A->coord_p[i]<< endl;;
    }
}

void copie_point(point A, point* B)
{
    for(int i = 0; i < 4 ; i++)
    {
        B->coord_p[i] = A.coord_p[i];
    }
}

void prepa_sdl(point* A,float view[4][4],float projection[4][4],float matrice_trans[4][4])
{
    cout << "Application View" << endl;
    multiplier(A,view);
    cout << "Application projection" << endl;
    multiplier(A,projection);
    cout << "Application ndc" << endl;
    ndc(A);
    for(int i = 0 ; i < 4 ; i++)
    {
       cout <<"|" << A->coord_p[i]<< endl;;
    }
}

void ndc(point* A)
{
    A->coord_p[0] = A->coord_p[0]/A->coord_p[3];
    A->coord_p[1] = A->coord_p[1]/A->coord_p[3];
    A->coord_p[2] = A->coord_p[2]/A->coord_p[3];
    A->coord_p[3] = A->coord_p[3]/A->coord_p[3];
}


