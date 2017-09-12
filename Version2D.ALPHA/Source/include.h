// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>

#define ORDONNEE 710/2-600/2

// ENUMERATIONS
typedef enum Type Type;
enum Type
{
    ROBOT, MUR1/* | */, MUR2/* _ */, OBJECTIF, VIDE, CROISEMENT
};

typedef enum Editeur;
enum
{
    QUITTER, CLIQUE_OBJET, PLACE_OBJET, BOUGE
} Editeur;

// STRUCTURES
typedef struct Objet Objet;
struct Objet
{
    SDL_Surface *images;
    SDL_Rect position;
    int x;
    int y;
    int amovible;
    Type type;
    char charactere;
};

typedef struct Composantes Composantes;
struct Composantes
{
    Objet robots[4];
    Objet objectif;
    Objet blanc;
    Objet plateau;
};

typedef struct Jeu Jeu;
struct Jeu
{
    Type type;
    int x;
    int y;
    char charactere;
};

typedef struct Parametres Parametres;
struct Parametres
{
    int nombrePoints;
    int nombreDeplacements;

    char fichierTitreMap[20];
    char titreMap[50];

    char fichierMap[20];
    char contenuFichierMap[2000];

    char messageErreur[200];

    int nombreDeJoueurs;
    int joueurQuiJoue;
};

#include "commun.h"
#include "imagesPlateau.h"
#include "editeur.h"
#include "ecriture.h"
//#include "solo.h"
//#include "multi.h"
//#include "environnement.h"
#include "contactAvecFichierExterne.h"
#include "deplacements.h"
#include "random.h"
#include "menus.h"

