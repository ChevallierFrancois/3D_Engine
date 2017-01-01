#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct point
{
    float coord_p[4];

}point;

void ini(point* A);

void multiplier(point* A,float transformation[4][4]);
float det(float transformation[4][4]);
void affichage (int);
int choix(int);
float conversion(float a);
void rotation(point* A,float transformation[4][4],int);
void prepa_sdl(point* A,float view[4][4],float projection[4][4],float matrice_trans[4][4]);
void ndc(point* A);
void copie_point(point A, point* B);
#endif
