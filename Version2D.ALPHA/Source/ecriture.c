#include "include.h"

void afficheScore(int entier, int x, int y, SDL_Surface *screen)
{
    int unite=0, dizaine=0, centaine=0;

    unite = entier%10;

    if (entier > 9)
        dizaine=((entier-unite)/10)%10;

    if (entier > 99)
        centaine=((entier-dizaine-unite)/100)%10;

    if (entier > 999)
    {
        unite = 9;
        dizaine = 9;
        centaine = 9;
    }

    Objet nombre[3];
    int i;
    for (i=0; i<3; i++)
    {
        nombre[i].position.x=x+(38*i);
        nombre[i].position.y=y;
        switch (i)
        {
            case 0:
            entier=centaine;
            break;

            case 1:
            entier=dizaine;
            break;

            case 2:
            entier=unite;
            break;
        }

        switch (entier)
        {
            case 0:
            nombre[i].images = SDL_LoadBMP("images/chiffres/0.bmp");
            break;

            case 1:
            nombre[i].images = SDL_LoadBMP("images/chiffres/1.bmp");
            break;

            case 2:
            nombre[i].images = SDL_LoadBMP("images/chiffres/2.bmp");
            break;

            case 3:
            nombre[i].images = SDL_LoadBMP("images/chiffres/3.bmp");
            break;

            case 4:
            nombre[i].images = SDL_LoadBMP("images/chiffres/4.bmp");
            break;

            case 5:
            nombre[i].images = SDL_LoadBMP("images/chiffres/5.bmp");
            break;

            case 6:
            nombre[i].images = SDL_LoadBMP("images/chiffres/6.bmp");
            break;

            case 7:
            nombre[i].images = SDL_LoadBMP("images/chiffres/7.bmp");
            break;

            case 8:
            nombre[i].images = SDL_LoadBMP("images/chiffres/8.bmp");
            break;

            case 9:
            nombre[i].images = SDL_LoadBMP("images/chiffres/9.bmp");
            break;
        }
        placeImage(&nombre[i], screen);
    }
}
