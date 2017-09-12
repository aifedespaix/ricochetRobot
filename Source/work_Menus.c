	#include <stdio.h>

	#include "include.h"

	#include "ask_Menus.h"
	#include "display_Menus.h"
	#include "work_Menus.h"

	#include "ask_CommunMap.h"

	#include "work_ContactFile.h"

	#include "work_Editor.h"

	#include "work_Multi.h"

	#include "work_OnePlayer.h"

	#include "work_Random.h"

// Manages the main menu.
void menuStart(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters)
{
	int keep = 1;
	int choice;
	while(keep){
        gameParameters->numberPlayers = 1;
		displayMenuStart();
		choice = askMenuStart();
		switch(choice){
			case ONEPLAYER:
                gameParameters->numberPlayers = 1;
				menuDifficulty(gameBoard, robots, gameParameters);
			break;

			case MULTIPLAYER:
                displayNumberPlayers();
                gameParameters->numberPlayers = askNumberPlayer();
                if(gameParameters->numberPlayers == -1){break;}
				menuDifficulty(gameBoard, robots, gameParameters);
			break;

			case EDITOR:
                menuEditor(gameBoard, robots, gameParameters, 1);
			break;

			case SCORES:
                menuScores(gameParameters->scores);
			break;

			case QUIT:
				keep = 0;
			break;
		}
	}
}

// Manages the difficulty menu.
void menuDifficulty(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters)
{
	int choice;
    displayMenuDifficulty();
    choice = askMenuDifficulty();
    int quit=0;
    switch(choice){
        case EASY:
            gameParameters->map = 0;
            sprintf(gameParameters->fileMapContent, "maps/easy.map");
        break;

        case MEDIUM:
            gameParameters->map = 1;
            sprintf(gameParameters->fileMapContent, "maps/medium.map");
        break;

        case HARD:
            gameParameters->map = 2;
            sprintf(gameParameters->fileMapContent, "maps/hard.map");
        break;

        case RANDOM:
            workCreateRandomMap(gameBoard, robots, gameParameters);
        break;

        case CUSTOM:
            menuEditor(gameBoard, robots, gameParameters, 0);
        break;

        default:
            quit = 1;
        break;
    }

    if(!quit){
        if(gameParameters->numberPlayers == 1) workPlaySolo(gameBoard, robots, gameParameters);
        else workPlayMulti(gameBoard, robots, gameParameters);
    }
}

// Manages the editor menu.
void menuEditor(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters, int edit) // int edit = 0 : playing || edit = 1 : editor
{
    int choice;
    displayMenuEditor();
    choice = askMenuEditor();
    int quit = 0;
    switch(choice){
        case 1:
            sprintf(gameParameters->fileMapContent, "maps/custom1.map");
        break;

        case 2:
            sprintf(gameParameters->fileMapContent, "maps/custom2.map");
        break;

        case 3:
            sprintf(gameParameters->fileMapContent, "maps/custom3.map");
        break;

        default:
            quit = 1;
        break;
    }

    if(edit == 1 && !quit) workEditor(gameBoard, robots, gameParameters); // If we are in edit mode.
}

// Manages the menu hightcores.
void menuScores(int scores[3])
{
    retrieveHightScore(scores);
    displayHightScore(scores);
    askContinue();
}
