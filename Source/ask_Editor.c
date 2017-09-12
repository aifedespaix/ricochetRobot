#include <stdio.h>

#include "include.h"

#include "ask_Editor.h"

#include "work_Environnement.h"

// User chooses what to do : add, remove, test, back, exit.
int askEditorWhatToDo(void)
{
	char choice;
	do{
		choice = environnementMyGetchar();
	} while(choice != ADD && choice != DELETE && choice != CLEAR && choice != SAVE && choice != 'q');

    switch(choice)
    {
        case ADD:
            return 1;

        case DELETE:
            return 2;

        case CLEAR:
            return 3;

        case SAVE:
            return 4;

        default:
            return QUIT;
    }
}

// User chooses which object he wants to move: robot, goal, wall.
char askEditorChooseObject()
{
	char choice;
	do{
		choice = environnementMyGetchar();
	} while(choice != 'Q' && choice != 'W' && choice != 'E' && choice != 'R' && choice != 'M' && choice != 'O');

    return choice;
}

// User specifies the coordinates of the cell where he wants to handling
int askEditorCoordinate()
{
    int coordinate;
    do{
        scanf("%d", &coordinate);
        while(getchar() != '\n');
    }while(coordinate < 1 || coordinate > SIZE-1);
    return coordinate;
}
