#include "include.h"

#include "ask_Multi.h"
#include "display_Multi.h"
#include "work_Multi.h"

#include "ask_CommunMap.h"
#include "display_CommunMap.h"
#include "work_CommunMap.h"

#include "work_Environnement.h"

// Main function of the multiplayer game.
void workPlayMulti(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters)
{
    // Vars déclaration
    int winner;
    int direction;
    int quit = 0; // Boolean
    int i, j;
    Multi players[gameParameters->numberPlayers];

    createMap(gameBoard, robots, gameParameters);

    //Copy variables global for game
    Object gameBoardCopy[SIZE][SIZE];
    workCopyMap(gameBoard, gameBoardCopy);

    Object robotsCopy[4];
    for(i=0; i<4; i++) robotsCopy[i] = robots[i];

    //Initialisation variables
    gameParameters->numberPoints = 0;
    gameParameters->numberPointsPrevTurn = 0;

    for(i=0; i<gameParameters->numberPlayers; i++){
            players[i].player = i;
            players[i].numberPoints = 0;
    }

    // Init robot statut
    char robotsWhoCompleted[4];
    for(i=0; i<4; i++){
        robotsWhoCompleted[i] = 0; // To start, no robot completed the map
    }

    // Let's Play multi
    while(gameParameters->numberPoints < 4){
        // choose a random robot to use
        do{
            gameParameters->robotToPlace.nb = randomInt(0, 4);
        }while(robotsWhoCompleted[gameParameters->robotToPlace.nb] == 1);

        switch(gameParameters->robotToPlace.nb)
        {
            case 0:
                gameParameters->robotToPlace.robot = 'Q';
                break;

            case 1:
                gameParameters->robotToPlace.robot = 'W';
                break;

            case 2:
                gameParameters->robotToPlace.robot = 'E';
                break;

            case 3:
                gameParameters->robotToPlace.robot = 'R';
                break;
        }


        gameParameters->numberTrips = 0;
        gameParameters->bet = 0;
        // Multi players bet :
        for(i=0; i<gameParameters->numberPlayers; i++){
            gameParameters->actualPlayer = players[i].player;
            displayMap(gameBoard, *gameParameters);
            displayBet(players[i].player, gameParameters->robotToPlace.robot);
            players[i].bet = askBet();
            if(players[i].bet == -1){
                quit = 1;
                break;
            }
        }
        if(quit) break; // If one player want to quit ... break.
        workOrderPlayers(players, gameParameters->numberPlayers);

        winner = -1;  // No winner
        for(i=0; i<gameParameters->numberPlayers; i++){
            // Prepare copy map and copy robots
            workCopyMap(gameBoard, gameBoardCopy);
            gameParameters->bet = players[i].bet;
            gameParameters->actualPlayer = players[i].player;

            for(j=0; j<4; j++){
                robotsCopy[j] = robots[j];
            }

            // Preparing Vars
            gameParameters->actualRobot = CHANGE; // by default 'c' : "Change robot", user must choise au new robot
            gameParameters->numberTrips = 0;
            // Solo Game started
            int keep = 1;
            while(keep){
                displayMap(gameBoardCopy, *gameParameters);
                // If user want or have to change robot
                if(gameParameters->actualRobot == CHANGE){
                    displayExchangeRobot();
                    gameParameters->actualRobot = askExchangeRobot();
                    if(gameParameters->actualRobot == QUIT) break;
                }

                // Else, user can move his robot
                else{
                    displayDirection();
                    direction = askDirection();
                    if(direction == QUIT) break;
                    else if(direction == CHANGE) gameParameters->actualRobot = CHANGE;
                    else{
                        workMove(gameBoardCopy, &robotsCopy[gameParameters->actualRobot], gameParameters, direction);
                    }
                }

                // Verifications
                if(gameParameters->numberPoints > gameParameters->numberPointsPrevTurn){
                    keep = 0;
                    if(players[i].bet == gameParameters->numberTrips+1){ // If user respect the conditions, validation of points
                        winner = i;
                        (players[i].numberPoints)++;
                        gameParameters->numberPointsPrevTurn = gameParameters->numberPoints;
                    }
                    else{ // else retrogradation of points
                        gameParameters->numberPoints = gameParameters->numberPointsPrevTurn;
                    }
                }
                if(gameParameters->numberTrips > players[i].bet) keep = 0;
            }

            displayMap(gameBoardCopy, *gameParameters);
            if(winner != -1){
                robotsWhoCompleted[gameParameters->robotToPlace.nb] = 1;
                displayRoundWinner(players[i].player);
                askContinue();
                break;
            } else{
                displayLose(players[i].player);
                askContinue();
            }
        }
    }
    if(gameParameters->numberPoints == 4){
        displayWinner(workFoundWinner(players, gameParameters->numberPlayers));
        askContinue();
    }
}

// Orders the array of players by betting.
void workOrderPlayers(Multi players[], int numberPlayers)
{
    int i, j;
    int min;
    Multi stock;
    for(i=0; i<numberPlayers; i++){
        min = i;
        for(j=i; j<numberPlayers; j++){
            if(players[j].bet < players[min].bet) min = j;
        }
        if(min != i){
            stock = players[i];
            players[i] = players[min];
            players[min] = stock;
        }
    }
}

// Makes a copy of the gameboard.
void workCopyMap(Object gameBoard[SIZE][SIZE], Object gameBoardCopy[SIZE][SIZE])
{
    int i, j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++)
            gameBoardCopy[i][j] = gameBoard[i][j];
}

// Found the winner of the game.
int workFoundWinner(Multi players[], int numberPlayers)
{
    int winner = -1;
    int bestScore = 0;
    int i;
    for(i=0; i<numberPlayers; i++){
        if(players[i].numberPoints > bestScore){
            winner = players[i].player;
            bestScore = players[i].numberPoints;
        }
    }
    for(i=0; i<numberPlayers; i++){
        if(players[i].player != winner && players[i].numberPoints == bestScore) winner = -1; // No winner
    }
    return winner;
}
