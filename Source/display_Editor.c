#include <stdio.h>

#include "include.h"

#include "display_Editor.h"

#include "work_Environnement.h"

// Displays the map in edit mode.
void displayMapEditor(Object gameBoard[SIZE][SIZE])
{
    environnementClearScreen();
    int i, j;
    space(45);
    for (i=1; i<SIZE-1; i++) printf("%02d ", i);
    newLine(1);
    if(OS == LINUX)
        color("0");
    for(i=0; i<SIZE; i++){
        space(40);
        if(i==0 || i== SIZE-1) printf("  ");
        else printf("%02d", i);
        for (j=0; j<SIZE; j++){
            if(OS == LINUX)
                switch (gameBoard[i][j].character){
                    case 'Q':
                    color("1;31");
                    break;

                    case 'W':
                    color("1;32");
                    break;

                    case 'E':
                    color("1;33");
                    break;

                    case 'R':
                    color("1;34");
                    break;

                    case '#':
                    color("35");
                    break;

                    case '+':
                    color("0");
                    break;

                    default:
                    color("1");
                    break;
                }

                switch(gameBoard[i][j].Type)
                {
                    case BLANK:
                        printf(" ");
                        break;

                    case WALL:
                        if(i%2 == 0)    printf("-");
                        else            printf("|");
                        break;

                    case CROSSING:
                        printf("+");
                        break;

                    case GOAL:
                        printf("#");
                        break;

                    default:
                        printf("%c", gameBoard[i][j].character);
                        break;
                }
                space(2);

                if(OS == LINUX)
                    color("0");
        }
        newLine(1);
    }
}

// Asks the user what to do.
void displayEditorWhatToDo()
{
    printf("Press : A to Add | D to Delete | C to Clear map | S to Save map and test it | q to Quit\n");
    printf("My choice :\n");
}

// Asks the user what he wants to add.
void displayEditorAddWhat()
{
    printf("     Add what ?\n");
    printf("  Robot (Q W E R) : (ex : R)\n");
    printf("  Goal            : O\n");
    printf("  Wall            : M\n");
    printf("My choice :\n");
}

// Asks the user coordinates on which he wants to work.
void displayEditorCoordinate(char letter)
{
    printf("     What Coordinates ?\n");
    printf("%c : ", letter);
}
