	#include <stdio.h>

	#include "include.h"

	#include "work_OnePlayer.h"

	#include "work_Environnement.h"

// User selects the robot he wants move
int askExchangeRobot(void)
{
	char choice;
	do{
		choice = environnementMyGetchar();
	} while(choice != 'Q' && choice != 'W' && choice != 'E' && choice != 'R' && choice != 'q');

    switch(choice)
    {
        case 'Q':
            return Q;

        case 'W':
            return W;

        case 'E':
            return E;

        case 'R':
            return R;

        default:
            return QUIT;
    }
	return choice;
}

// User selects the direction where he wants move
int askDirection(void)
{
	char choice;
	do{
		choice = environnementMyGetchar();
	} while(choice != 'Z'
         && choice != '8'
         && choice != 'S'
         && choice != '2'
         && choice != 'Q'
         && choice != '4'
         && choice != 'D'
         && choice != '6'
         && choice != '0'
         && choice != 'C'
         && choice != 'q');

    switch(choice)
    {
        case 'Z':
            return TOP;

        case '8':
            return TOP;

        case 'S':
            return BOTTOM;

        case '2':
            return BOTTOM;

        case 'Q':
            return LEFT;

        case '4':
            return LEFT;

        case 'D':
            return RIGHT;

        case '6':
            return RIGHT;

        case 'C':
            return CHANGE;

        case '0':
            return CHANGE;

        default:
            return QUIT;
    }

	return choice;
}

// Allows to pause to see results
void askContinue(void)
{
    environnementMyGetchar();
}
