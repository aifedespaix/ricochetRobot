#include <stdio.h>

#include "include.h"

#include "display_Multi.h"

#include "work_Environnement.h"

// Demand estimated bet.
void displayBet(int player, char robot)
{
    printf("Player %d bet on the number of moving it will do to move the robot %c. (Or 'q' to quit)\n", player+1, robot);
    printf("My bet : ");
}

// Displays messages round loser.
void displayLose(int player)
{
    environnementClearScreen();
    newLine(15);
    printf("       _______________________________________________________\n");
    printf("      /                                                      /|\n");
    printf("     /                                                      / |\n");
    printf("    /                 RICOCHET ROBOT BOX                   /  |\n");
    printf("   /                                                      /   |\n");
    printf("  /______________________________________________________/    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                    Round Result                      |    |\n");
    printf("  |                    ------------                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |       Player %3d lose ... ... ...                    |    |\n", player+1);
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |   /\n");
    printf("  |                                                      |  /\n");
    printf("  |   Press [enter] to continue ...                      | /\n");
    printf("  |______________________________________________________|/\n");
}

// Displays winning message round
void displayRoundWinner(int player)
{
    environnementClearScreen();
    newLine(15);
    printf("       _______________________________________________________\n");
    printf("      /                                                      /|\n");
    printf("     /                                                      / |\n");
    printf("    /                 RICOCHET ROBOT BOX                   /  |\n");
    printf("   /                                                      /   |\n");
    printf("  /______________________________________________________/    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                    Round Result                      |    |\n");
    printf("  |                    ------------                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |       Player %3d won this round, GOOD JOB ! ;)       |    |\n", player+1);
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |   /\n");
    printf("  |                                                      |  /\n");
    printf("  |   Press [enter] to continue ...                      | /\n");
    printf("  |______________________________________________________|/\n");
}

// Displays winner of the game.
void displayWinner(int winner)
{
    environnementClearScreen();
    newLine(15);
    if(winner == -1){
        printf("       _______________________________________________________\n");
        printf("      /                                                      /|\n");
        printf("     /                                                      / |\n");
        printf("    /                 RICOCHET ROBOT BOX                   /  |\n");
        printf("   /                                                      /   |\n");
        printf("  /______________________________________________________/    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                    Final Result                      |    |\n");
        printf("  |                    ------------                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |               There is no winner :/                  |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |   /\n");
        printf("  |                                                      |  /\n");
        printf("  |   Press [enter] to continue ...                      | /\n");
        printf("  |______________________________________________________|/\n");
    }else{

        printf("       _______________________________________________________\n");
        printf("      /                                                      /|\n");
        printf("     /                                                      / |\n");
        printf("    /                 RICOCHET ROBOT BOX                   /  |\n");
        printf("   /                                                      /   |\n");
        printf("  /______________________________________________________/    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                      Result                          |    |\n");
        printf("  |                      ------                          |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |       Player %3d won the game,   *APPLAUSE*          |    |\n", winner+1);
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |                                                      |   /\n");
        printf("  |                                                      |  /\n");
        printf("  |   Press [enter] to continue ...                      | /\n");
        printf("  |______________________________________________________|/\n");
    }
}
