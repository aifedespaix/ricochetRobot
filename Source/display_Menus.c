	#include <stdio.h>

	#include "include.h"

	#include "display_Menus.h"

	#include "work_Environnement.h"

// Displays the main menu.
void displayMenuStart(void)
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
        printf("  |                      Main Menu                       |    |\n");
        printf("  |                      ---------                       |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |      (1) One Player                                  |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |      (2) MultiPlayer                                 |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |      (3) Map Editor                                  |    |\n");
        printf("  |                                                      |    |\n");
        printf("  |      (4) Highest Scores                              |    |\n");
        printf("  |                                                      |   /\n");
        printf("  |      (q) Quit                                        |  /\n");
        printf("  |                                                      | /\n");
        printf("  |______________________________________________________|/\n");
        newLine(2);
        printf("  |> My choice : \n");
}

// Display the menu of choice of difficulty.
void displayMenuDifficulty(void)
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
    printf("  |                  Difficulty Menu                     |    |\n");
    printf("  |                  ---------------                     |    |\n");
    printf("  |      (1) Easy                                        |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (2) Medium                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (3) Hard                                        |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (4) Random                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (5) Custom                                      |   /\n");
    printf("  |                                                      |  /\n");
    printf("  |      (q) Quit                                        | /\n");
    printf("  |______________________________________________________|/\n");
    newLine(2);
    printf("  |> My choice : \n");
}

// Displays the editing menu.
void displayMenuEditor(void)
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
    printf("  |                    Editor Menu                       |    |\n");
    printf("  |                    -----------                       |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (1) Custom 1                                    |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (2) Custom 2                                    |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (3) Custom 3                                    |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |   /\n");
    printf("  |                                                      |  /\n");
    printf("  |      (q) Quit                                        | /\n");
    printf("  |______________________________________________________|/\n");
    newLine(2);
    printf("  |> My choice : \n");
}

// Display the menu of choice of many players.
void displayNumberPlayers(void)
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
    printf("  |                   Players Menu                       |    |\n");
    printf("  |                   ------------                       |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (2) Two Players                                 |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (3) Three Players                               |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (4) Four Players                                |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      (q) Quit                                        |   /\n");
    printf("  |                                                      |  /\n");
    printf("  |                                                      | /\n");
    printf("  |______________________________________________________|/\n");
    newLine(2);
    printf("  |> My choice : \n");
}

// Displays the highscores.
void displayHightScore(int scores[3])
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
    printf("  |                  Highest Scores                      |    |\n");
    printf("  |                  --------------                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |      Easy   : %3d                                    |    |\n", scores[0]);
    printf("  |                                                      |    |\n");
    printf("  |      Medium : %3d                                    |    |\n", scores[1]);
    printf("  |                                                      |    |\n");
    printf("  |      Hard   : %3d                                    |    |\n", scores[2]);
    printf("  |                                                      |    |\n");
    printf("  |                                                      |    |\n");
    printf("  |                                                      |   /\n");
    printf("  |                                                      |  /\n");
    printf("  |   Press [enter] to continue ...                      | /\n");
    printf("  |______________________________________________________|/\n");
    newLine(2);
}
