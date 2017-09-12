	#include "include.h"

	#include "ask_Menus.h"

	#include "work_Environnement.h"

// User selects a menu item.
int askMenuStart(void)
{
	char choice;
	do{
		choice = environnementMyGetchar();
	} while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 'q' );

    switch(choice)
    {
        case '1':
            return ONEPLAYER;

        case '2':
            return MULTIPLAYER;

        case '3':
            return EDITOR;

        case '4':
            return SCORES;

        default:
            return QUIT;
    }
}

// User selects the difficulty.
int askMenuDifficulty(void)
{
	char choice;
	do{
		choice = environnementMyGetchar();
	} while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != 'q');

    switch(choice)
    {
        case '1':
            return EASY;

        case '2':
            return MEDIUM;

        case '3':
            return HARD;

        case '4':
            return RANDOM;

        case '5':
            return CUSTOM;

        default:
            return QUIT;
    }
}

// User selects the map he wants to edit.
int askMenuEditor(void)
{
	char choice;
	do{
		choice = environnementMyGetchar();
	} while(choice != '1' && choice != '2' && choice != '3' && choice != 'q');


    switch(choice)
    {
        case '1':
            return 1;

        case '2':
            return 2;

        case '3':
            return 3;

        default:
            return QUIT;
    }
}

// User selects the number of players.
int askNumberPlayer(void)
{
    char numberPlayer;
    do{
        numberPlayer = environnementMyGetchar();
    }while(numberPlayer != '2' && numberPlayer != '3' && numberPlayer != '4' && numberPlayer != 'q');

    switch(numberPlayer)
    {
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case 'q': return -1;
        default: return -1;
    }
}

