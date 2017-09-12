#include <stdio.h>

#include "include.h"

#include "display_CommunMap.h"

#include "work_Environnement.h"

// Displays the playground.
void displayMap(Object gameBoard[SIZE][SIZE], Parameters gameParameters)
{
    environnementClearScreen();
    int i, j;

    if(gameParameters.numberPlayers == 1){
        printf("Number of moves : %d | Number of Points : %d", gameParameters.numberTrips, gameParameters.numberPoints);
    }else{ // MultiPlayer
        printf("Actual player : %d\nNumber of moves : %d | Bet : %d | Robot to place : %c | Number of robots to validate : %d", gameParameters.actualPlayer+1, gameParameters.numberTrips, gameParameters.bet, gameParameters.robotToPlace.robot, 4-gameParameters.numberPoints);
    }

    if(OS == LINUX)
        color("0");
    newLine(2);
    for(i=0; i<SIZE; i++){
        space(40);
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

                    default:
                        printf("%c", gameBoard[i][j].character);
                        break;
                }
                space(1);

                if(OS == LINUX)
                    color("0");
        }
        newLine(1);
    }
}

// Message displays victory.
void displayVictory(void)
{
        environnementClearScreen();
        newLine(10);
        printf("       _______________________________________________________\n");
        printf("      /                                                      /|\n");
        printf("     /                                                      / |\n");
        printf("    /                 RICOCHET ROBOT BOX                   /  |\n");
        printf("   /                                                      /   |\n");
        printf("  /______________________________________________________/    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                       VICTORY                        |    |\n");
        printf("  |                       -------                 \\0/    |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |         CONGRATULATIONS                              |    |\n");
        printf("  |      \\0/         GOOD JOB                            |    |\n");
        printf("  |               \\0/                                    |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                       YOU WON                        |    |\n");
        printf("  |                    \\0/                               |    |\n");
        printf("  |                                                      |   /\n");
        printf("  |    OH YEAH !                                         |  /\n");
        printf("  | \\0/                                                  | /\n");
        printf("  |______________________________________________________|/\n");
        newLine(2);
        printf("Press enter (2x) to continue");
}

// Change message displays robot.
void displayExchangeRobot(void)
{
    printf("Choose your robot : Q, W, E or R ... or q to quit.\n");
}

// Message displayed executive choice.
void displayDirection(void)
{
    printf("Where do you want to go ?\n");
    printf("Z or 8 -> TOP\n");
    printf("S or 2 -> BOTTOM\n");
    printf("Q or 4 -> LEFT\n");
    printf("D or 6 -> RIGHT\n");
    printf("C or 0 -> CHANGE ROBOT");
    printf("... or q to quit...\n");
}
