#include "include.h"

void wait() // On attend un peu pour que le joueur voit ce qu'il ce passe.
{
    usleep(500);
}

int Random(int iMin, int iMax) // Balance un nombre aléatoire compris entre iMin et iMax.
{
    return (iMin+rand()%(iMax-iMin));
}
