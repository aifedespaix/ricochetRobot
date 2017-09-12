#include "include.h"

void editeurMap(Composantes *composantes, SDL_Surface *screen, Jeu jeu[33][33], Parametres *ParametresDuJeu)
{
    creerMapBase(jeu);
    placeMurs(screen, jeu);
    composantes->plateau.images = SDL_LoadBMP("images/plateaux/plateauJeu.bmp");
    placeImage(&composantes->plateau, screen);

    Objet enAttente[9];

    enAttente[0].images = SDL_LoadBMP("images/objectif.bmp");
    enAttente[1].images = SDL_LoadBMP("images/robots/red.bmp");
    enAttente[2].images = SDL_LoadBMP("images/robots/blue.bmp");
    enAttente[3].images = SDL_LoadBMP("images/robots/green.bmp");
    enAttente[4].images = SDL_LoadBMP("images/robots/yellow.bmp");
    enAttente[5].images = SDL_LoadBMP("images/murs/mur1.bmp");
    enAttente[6].images = SDL_LoadBMP("images/murs/mur2.bmp");
    enAttente[7].images = SDL_LoadBMP("images/editeur/bombe.bmp");

    ////-------------------
    SDL_Rect clipper, oldPositionSuiveuse;
    Objet copiePlateauJeu = composantes->plateau;
    ////-------------------

    Objet suiveuse;
    suiveuse.images = SDL_LoadBMP("images/editeur/vide.bmp");

    int i;
    for (i=0; i<5; i++)
    {
        enAttente[i].position.x = 750+(i*100);
        enAttente[i].position.y = 100;
        placeImage(&enAttente[i], screen);
    }
    for (i=5; i<8; i++)
    {
        enAttente[i].position.x = 750+((i-5)*100);
        enAttente[i].position.y = 200;
        placeImage(&enAttente[i], screen);
    }

    int continuer=1;
    int objetActuel;

    Uint32 currentTime/*, nextPrint=0*/;
    while(continuer)
    {
        int choix = returnEventEditeur(&suiveuse, &clipper, &objetActuel);
        if (choix == QUITTER)
            break;

        if (choix == BOUGE)
        {
                SDL_Event event;
                SDL_WaitEvent(&event);

                if (event.type == SDL_MOUSEMOTION)
                {
                    clipper.x = oldPositionSuiveuse.x;
                    clipper.y = oldPositionSuiveuse.y;
                    clipper.h = suiveuse.position.h;
                    clipper.w = suiveuse.position.w;
                    SDL_SetClipRect(screen, &clipper);

                    copiePlateauJeu.position.x = composantes->plateau.position.x;
                    copiePlateauJeu.position.y = composantes->plateau.position.y;

                    SDL_BlitSurface(composantes->plateau.images, NULL, screen, &copiePlateauJeu.position); // Effacer suiveuse

                    SDL_SetClipRect(screen, NULL); // Enlever le clipper

                    SDL_BlitSurface(suiveuse.images, NULL, screen, &suiveuse.position);

                    oldPositionSuiveuse.x = suiveuse.position.x;
                    oldPositionSuiveuse.y = suiveuse.position.y;

                    suiveuse.position.x = event.motion.x;
                    suiveuse.position.y = event.motion.y;

                    SDL_Flip(screen);
            }
        }
        else if (choix == PLACE_OBJET)
        {
            switch (objetActuel)
            case OBJECTIF:
                composantes->objectif.x=suiveuse.position.x/29;
                composantes->objectif.y=suiveuse.position.y/29;
                jeu[composantes->objectif.x][composantes->objectif.y].type = OBJECTIF;

                composantes->objectif.position.x=29*composantes->objectif.x;
                composantes->objectif.position.y=29*composantes->objectif.y;
                placeImage(&composantes->objectif, screen);
                break;
//
//            case ROBOT:
//                composantes->robots[0].x=suiveuse.position.x/29;
//                composantes->robots[0].y=suiveuse.position.y/29;
//                jeu[composantes->robots[0].x][composantes->objectif.y].type = OBJECTIF;
//
//                composantes->robots[0].position.x=29*composantes->objectif.x;
//                composantes->robots[0].position.y=29*composantes->objectif.y;
//                placeImage(&composantes->robots[0], screen);
//                break;
        } else
        {
            suiveuse.images = enAttente[choix].images;
        }

        afficherEdition(screen, composantes, jeu);
    }
}

int returnEventEditeur(Objet *suiveuse, SDL_Rect *clipper, int *objetActuel)
{
    SDL_Event event;
    int keepA=1;
    while(keepA)
    {
        while(SDL_WaitEvent(&event))
        switch(event.type)
        {
            case SDL_QUIT:
                return QUITTER;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    return QUITTER;
                break;

            case SDL_MOUSEBUTTONUP:
                if( (event.button.x > 750) && (event.button.x < 750+40) && (event.button.y > 100) && (event.button.y < 100+40) )
                *objetActuel=OBJECTIF;

                if( (event.button.x > 850) && (event.button.x < 850+40) && (event.button.y > 100) && (event.button.y < 100+40) )
                *objetActuel=ROBOT;

                if( (event.button.x > 950) && (event.button.x < 950+40) && (event.button.y > 100) && (event.button.y < 100+40) )
                *objetActuel=ROBOT;

                if( (event.button.x > 1050) && (event.button.x < 1050+40) && (event.button.y > 100) && (event.button.y < 100+40) )
                *objetActuel=ROBOT;

                if( (event.button.x > 1050) && (event.button.x < 1150+40) && (event.button.y > 100) && (event.button.y < 100+40) )
                *objetActuel=ROBOT;

                if( (event.button.x > 750) && (event.button.x < 750+40) && (event.button.y > 200) && (event.button.y < 200+40) )
                *objetActuel=MUR1;

                if( (event.button.x > 850) && (event.button.x < 850+40) && (event.button.y > 100) && (event.button.y < 200+40) )
                *objetActuel=MUR2;

                if( (event.button.x > 950) && (event.button.x < 950+40) && (event.button.y > 200) && (event.button.y < 200+40) )
                *objetActuel=VIDE;


            //--------------------
                if( (event.button.x > 0) && (event.button.x < 600) && (event.button.y > ORDONNEE) && (event.button.y < 600+ORDONNEE) )
                {
                    return PLACE_OBJET;
                }
                else
                {
                    return CLIQUE_OBJET;
                }
                break;

            case SDL_MOUSEMOTION:
            {
                return BOUGE;
            }
                break;

        }
    }
    return -1;
}
