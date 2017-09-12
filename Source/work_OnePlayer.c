    #include "include.h"

    #include "work_OnePlayer.h"

    #include "ask_CommunMap.h"
    #include "display_CommunMap.h"
    #include "work_CommunMap.h"

    #include "work_ContactFile.h"

    #include "work_Environnement.h"

// Main function of the solo game.
void workPlaySolo(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters)
{
    // Game preparation
    gameParameters->actualRobot = CHANGE; // by default 'c' : "Change robot", user must choise au new robot
    gameParameters->numberTrips = 0;
    gameParameters->numberPoints = 0;
    gameParameters->numberPointsPrevTurn = 0;

    createMap(gameBoard, robots, gameParameters);

    int direction;

    // Solo Game started
    int keep = 1;
    while(keep){
        // If the user won 1 point in the previous round, then the active robot to reach the goal
        // User have to choose a new robot
        if(gameParameters->numberPoints > gameParameters->numberPointsPrevTurn) {
            gameParameters->actualRobot = CHANGE;
            gameParameters->numberPointsPrevTurn = gameParameters->numberPoints; // refresh number of points of last turn
        }

        // If user want or have to change robot
        if(gameParameters->actualRobot == CHANGE){
            do{
                displayMap(gameBoard, *gameParameters);
                displayExchangeRobot();
                gameParameters->actualRobot = askExchangeRobot();
                if(gameParameters->actualRobot == QUIT) break;
            }while(robots[gameParameters->actualRobot].removable == 0);
            if(gameParameters->actualRobot == QUIT) break;
        }

        // Else, user can move his robot
        else{
            displayMap(gameBoard, *gameParameters);
            displayDirection();
            direction = askDirection();
            if(direction == QUIT) break;
            if(direction == CHANGE) gameParameters->actualRobot = CHANGE;
            else{
                workMove(gameBoard, &robots[gameParameters->actualRobot], gameParameters, direction);
            }
        }

        // If user got 4 points, all robots have achieved the goal
        if(gameParameters->numberPoints == 4){
            hightScore(gameParameters);
            displayVictory();
            askContinue();
            break;
        }
    }
}

// Saves the highscore if it takes place.
void hightScore(Parameters *gameParameters)
{
    retrieveHightScore(gameParameters->scores);
    char score[3];
    convertIntNumbToChar(gameParameters->numberTrips, score);
    retrieveHightScore(gameParameters->scores);
    switch(gameParameters->map)
    {
        case 0:
        if(gameParameters->numberTrips < gameParameters->scores[0]){ // New hightscore
            saveHightScore(score, "maps/easy.score");
        }
        break;


        case 1:
        if(gameParameters->numberTrips < gameParameters->scores[1]){ // New hightscore
            saveHightScore(score, "maps/medium.score");
        }
        break;

        case 2:
        if(gameParameters->numberTrips < gameParameters->scores[2]){ // New hightscore
            saveHightScore(score, "maps/hard.score");
        }
        break;
    }
}
