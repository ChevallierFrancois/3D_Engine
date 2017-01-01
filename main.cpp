#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fonctions.h"
#include <SDL/SDL.h>

using namespace std;

int main(int argc, char **argv)
{
    int continuer = 1;
    int cis = 1;

    point A;
    point Aa;
    point B;
    point Ba;
    point C;
    point Ca;
    point D;
    point Da;
    point E;
    point Ea;
    point F;
    point Fa;
    point G;
    point Ga;
    point H;
    point Ha;
    point I;
    point Ia;
    point J;
    point Ja;

    A.coord_p[0] = 0;
    A.coord_p[1] = 0;
    A.coord_p[2] = 0;
    A.coord_p[3] = 1;

    B.coord_p[0] = 1;
    B.coord_p[1] = 0;
    B.coord_p[2] = 0;
    B.coord_p[3] = 1;

    G.coord_p[0] = 1;
    G.coord_p[1] = 0;
    G.coord_p[2] = 0.50;
    G.coord_p[3] = 1;

    F.coord_p[0] = 0;
    F.coord_p[1] = 0;
    F.coord_p[2] = 0.50;
    F.coord_p[3] = 1;

    D.coord_p[0] = 1;
    D.coord_p[1] = 0.50;
    D.coord_p[2] = 0;
    D.coord_p[3] = 1;

    E.coord_p[0] = 0;
    E.coord_p[1] = 0.50;
    E.coord_p[2] = 0.50;
    E.coord_p[3] = 1;

    C.coord_p[0] = 0;
    C.coord_p[1] = 0.50;
    C.coord_p[2] = 0;
    C.coord_p[3] = 1;

    H.coord_p[0] = 1;
    H.coord_p[1] = 0.50;
    H.coord_p[2] = 0.50;
    H.coord_p[3] = 1;

    I.coord_p[0] = 0;
    I.coord_p[1] = 0.25;
    I.coord_p[2] = 0.75;
    I.coord_p[3] = 1;

    J.coord_p[0] = 1;
    J.coord_p[1] = 0.25;
    J.coord_p[2] = 0.75;
    J.coord_p[3] = 1;


    float view[4][4] = {-1,0,0,0,
                        0,0,1,0,
                        0,1,0,4,
                        0,0,0,1
                       };
    float projection[4][4] = {0.82,0,0,0,
                              0,0.82,0,0,
                              0,0,-2.222,-2.222,
                              0,0,-1,0
                             };

    float matrice_trans[4][4] = {1,0,0,0,
                                 0,1,0,0,
                                 0,0,1,0,
                                 0,0,0,1
                                };

    SDL_Event event;
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *pointA = NULL, *pointB = NULL, *pointC = NULL, *pointD = NULL, *pointE = NULL, *pointF = NULL, *pointG = NULL, *pointH = NULL, *pointI = NULL, *pointJ = NULL;
    SDL_Rect positionA, positionB, positionC, positionD, positionE, positionF, positionG, positionH, positionI, positionJ, positionFond ;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY/3, SDL_DEFAULT_REPEAT_INTERVAL);

    int taille_fenetre = 840;

    positionFond.x = (taille_fenetre / 2); // Les coordonnées de la surface seront (0, 0)
    positionFond.y = (taille_fenetre / 2);

    imageDeFond = SDL_LoadBMP("axe.bmp");
    ecran = SDL_SetVideoMode(taille_fenetre, taille_fenetre, 32, SDL_HWSURFACE);
    pointA = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    pointB = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    pointC = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    pointD = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    pointE = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    pointF = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    pointG = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    pointH = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    pointI = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    pointJ = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0); // Allocation de la surface
    SDL_WM_SetCaption("Moteur 3D : TAI Algebre lineaire", NULL);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    imageDeFond = SDL_LoadBMP("axe.bmp");
    SDL_Flip(ecran); // Mise à jour de l'écran

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_UP: // Flèche haut
                matrice_trans[1][3] = 0.25;
                break;
            case SDLK_DOWN: // Flèche bas
                matrice_trans[1][3] = -0.25;
                break;
            case SDLK_RIGHT: // Flèche droite
                matrice_trans[0][3] = 0.25;
                break;
            case SDLK_LEFT: // Flèche gauche
                matrice_trans[0][3] = -0.25;
                break;
            case SDLK_KP_PLUS: // Flèche gauche
                matrice_trans[2][3] = 0.25;
                break;
            case SDLK_KP_MINUS: // Flèche gauche
                matrice_trans[2][3] = -0.25;
                break;
            case SDLK_c: // Flèche gauche
                if (cis == 1) cis = 0;
                else cis = 1;
                break;
            case SDLK_q: // Flèche gauche
                matrice_trans[0][0] = cos(0.1);
                matrice_trans[0][2] = sin(0.1);
                matrice_trans[2][0] = -sin(0.1);
                matrice_trans[2][2] = cos(0.1);
                break;
            case SDLK_a: // Flèche gauche
                matrice_trans[0][0] = cos(-0.1);
                matrice_trans[0][2] = sin(-0.1);
                matrice_trans[2][0] = -sin(-0.1);
                matrice_trans[2][2] = cos(-0.1);
                break;
            case SDLK_w: // Flèche gauche
                matrice_trans[0][0] = cos(0.1);
                matrice_trans[1][0] = sin(0.1);
                matrice_trans[0][1] = -sin(0.1);
                matrice_trans[1][1] = cos(0.1);
                break;
            case SDLK_s: // Flèche gauche
                matrice_trans[0][0] = cos(-0.1);
                matrice_trans[1][0] = sin(-0.1);
                matrice_trans[0][1] = -sin(-0.1);
                matrice_trans[1][1] = cos(-0.1);
                break;
            case SDLK_e: // Flèche gauche
                matrice_trans[1][1] = cos(0.1);
                matrice_trans[2][1] = sin(0.1);
                matrice_trans[1][2] = -sin(0.1);
                matrice_trans[2][2] = cos(0.1);
                break;
            case SDLK_d: // Flèche gauche
                matrice_trans[1][1] = cos(-0.1);
                matrice_trans[2][1] = sin(-0.1);
                matrice_trans[1][2] = -sin(-0.1);
                matrice_trans[2][2] = cos(-0.1);
                break;
            case SDLK_t: // Flèche gauche
                matrice_trans[0][0] = -1;
                matrice_trans[1][1] = -1;
                matrice_trans[2][2] = -1;
                break;
            case SDLK_g: // Flèche gauche
                matrice_trans[1][1] = -1;
                matrice_trans[2][2] = -1;
                break;
            case SDLK_b: // Flèche gauche
                matrice_trans[0][0] = -1;
                break;
            case SDLK_z: // Flèche gauche
                A.coord_p[0] = 0;
                A.coord_p[1] = 0;
                A.coord_p[2] = 0;
                A.coord_p[3] = 1;
                B.coord_p[0] = 1;
                B.coord_p[1] = 0;
                B.coord_p[2] = 0;
                B.coord_p[3] = 1;
                G.coord_p[0] = 1;
                G.coord_p[1] = 0;
                G.coord_p[2] = 0.50;
                G.coord_p[3] = 1;
                F.coord_p[0] = 0;
                F.coord_p[1] = 0;
                F.coord_p[2] = 0.50;
                F.coord_p[3] = 1;
                D.coord_p[0] = 1;
                D.coord_p[1] = 0.50;
                D.coord_p[2] = 0;
                D.coord_p[3] = 1;
                E.coord_p[0] = 0;
                E.coord_p[1] = 0.50;
                E.coord_p[2] = 0.50;
                E.coord_p[3] = 1;
                C.coord_p[0] = 0;
                C.coord_p[1] = 0.50;
                C.coord_p[2] = 0;
                C.coord_p[3] = 1;
                H.coord_p[0] = 1;
                H.coord_p[1] = 0.50;
                H.coord_p[2] = 0.50;
                H.coord_p[3] = 1;
                I.coord_p[0] = 0;
                I.coord_p[1] = 0.25;
                I.coord_p[2] = 0.75;
                I.coord_p[3] = 1;
                J.coord_p[0] = 1;
                J.coord_p[1] = 0.25;
                J.coord_p[2] = 0.75;
                J.coord_p[3] = 1;
                break;
            }
            break;
        case SDL_KEYUP:
            matrice_trans[0][0] = 1;
            matrice_trans[0][1] = 0;
            matrice_trans[0][2] = 0;
            matrice_trans[0][3] = 0;
            matrice_trans[1][0] = 0;
            matrice_trans[1][1] = 1;
            matrice_trans[1][2] = 0;
            matrice_trans[1][3] = 0;
            matrice_trans[2][0] = 0;
            matrice_trans[2][1] = 0;
            matrice_trans[2][2] = 1;
            matrice_trans[2][3] = 0;
            matrice_trans[3][0] = 0;
            matrice_trans[3][1] = 0;
            matrice_trans[3][2] = 0;
            matrice_trans[3][3] = 1;
            break;
        }

        cout << "==============================================================================================" << endl;
        if(cis == 1)
        {
            cout << "================================ A ================================" << endl;
            multiplier(&A,matrice_trans);
            copie_point(A, &Aa);
            prepa_sdl(&Aa, view, projection, matrice_trans);
            cout << "================================ B ================================" << endl;
            multiplier(&B,matrice_trans);
            copie_point(B, &Ba);
            prepa_sdl(&Ba, view, projection, matrice_trans);
            cout << "================================ C ================================" << endl;
            multiplier(&C,matrice_trans);
            copie_point(C, &Ca);
            prepa_sdl(&Ca, view, projection, matrice_trans);
            cout << "================================ D ================================" << endl;
            multiplier(&D,matrice_trans);
            copie_point(D, &Da);
            prepa_sdl(&Da, view, projection, matrice_trans);
        }
        cout << "================================ E ================================" << endl;
        multiplier(&E,matrice_trans);
        copie_point(E, &Ea);
        prepa_sdl(&Ea, view, projection, matrice_trans);
        cout << "================================ F ================================" << endl;
        multiplier(&F,matrice_trans);
        copie_point(F, &Fa);
        prepa_sdl(&Fa, view, projection, matrice_trans);
        cout << "================================ G ================================" << endl;
        multiplier(&G,matrice_trans);
        copie_point(G, &Ga);
        prepa_sdl(&Ga, view, projection, matrice_trans);
        cout << "================================ H ================================" << endl;
        multiplier(&H,matrice_trans);
        copie_point(H, &Ha);
        prepa_sdl(&Ha, view, projection, matrice_trans);
        cout << "================================ I ================================" << endl;
        multiplier(&I,matrice_trans);
        copie_point(I, &Ia);
        prepa_sdl(&Ia, view, projection, matrice_trans);
        cout << "================================ J ================================" << endl;
        multiplier(&J,matrice_trans);
        copie_point(J, &Ja);
        prepa_sdl(&Ja, view, projection, matrice_trans);


        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

        positionA.x = (taille_fenetre/2)*(Aa.coord_p[0] + 1); // Les coordonnées de la surface seront (0, 0)
        positionA.y = (taille_fenetre/2)*(Aa.coord_p[1] + 1);

        SDL_FillRect(pointA, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointA, NULL, ecran, &positionA); // Collage de la surface sur l'écran

        positionB.x = (taille_fenetre/2)*(Ba.coord_p[0] + 1);
        positionB.y = (taille_fenetre/2)*(Ba.coord_p[1] + 1);

        SDL_FillRect(pointB, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointB, NULL, ecran, &positionB); // Collage de la surface sur l'écran

        positionC.x = (taille_fenetre/2)*(Ca.coord_p[0] + 1);
        positionC.y = (taille_fenetre/2)*(Ca.coord_p[1] + 1);

        SDL_FillRect(pointC, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointC, NULL, ecran, &positionC); // Collage de la surface sur l'écran

        positionD.x = (taille_fenetre/2)*(Da.coord_p[0] + 1);
        positionD.y = (taille_fenetre/2)*(Da.coord_p[1] + 1);

        SDL_FillRect(pointD, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointD, NULL, ecran, &positionD); // Collage de la surface sur l'écran

        positionE.x = (taille_fenetre/2)*(Ea.coord_p[0] + 1);
        positionE.y = (taille_fenetre/2)*(Ea.coord_p[1] + 1);

        SDL_FillRect(pointE, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointE, NULL, ecran, &positionE); // Collage de la surface sur l'écran

        positionF.x = (taille_fenetre/2)*(Fa.coord_p[0] + 1);
        positionF.y = (taille_fenetre/2)*(Fa.coord_p[1] + 1);

        SDL_FillRect(pointF, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointF, NULL, ecran, &positionF); // Collage de la surface sur l'écran

        positionG.x = (taille_fenetre/2)*(Ga.coord_p[0] + 1);
        positionG.y = (taille_fenetre/2)*(Ga.coord_p[1] + 1);

        SDL_FillRect(pointG, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointG, NULL, ecran, &positionG); // Collage de la surface sur l'écran

        positionH.x = (taille_fenetre/2)*(Ha.coord_p[0] + 1);
        positionH.y = (taille_fenetre/2)*(Ha.coord_p[1] + 1);

        SDL_FillRect(pointH, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointH, NULL, ecran, &positionH); // Collage de la surface sur l'écran

        positionI.x = (taille_fenetre/2)*(Ia.coord_p[0] + 1);
        positionI.y = (taille_fenetre/2)*(Ia.coord_p[1] + 1);

        SDL_FillRect(pointI, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointI, NULL, ecran, &positionI); // Collage de la surface sur l'écran

        positionJ.x = (taille_fenetre/2)*(Ja.coord_p[0] + 1);
        positionJ.y = (taille_fenetre/2)*(Ja.coord_p[1] + 1);

        SDL_FillRect(pointJ, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Remplissage de la surface avec du blanc
        SDL_BlitSurface(pointJ, NULL, ecran, &positionJ); // Collage de la surface sur l'écran

        SDL_Flip(ecran); // Mise à jour de l'écran
    }


    SDL_FreeSurface(pointA); // Libération de la surface
    SDL_FreeSurface(pointB); // Libération de la surface
    SDL_FreeSurface(pointC); // Libération de la surface
    SDL_FreeSurface(pointD); // Libération de la surface
    SDL_FreeSurface(pointE); // Libération de la surface
    SDL_FreeSurface(pointF); // Libération de la surface
    SDL_FreeSurface(pointG); // Libération de la surface
    SDL_FreeSurface(pointH); // Libération de la surface
    SDL_Quit();

    return EXIT_SUCCESS;

}
