#include "include.h"

#include "work_Random.h"

#include "work_CommunMap.h"

#include "work_Environnement.h"

// Main function to create random map.
void workCreateRandomMap(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters)
{
    int numberWalls;
    do{
        createBasicMap(gameBoard);
        numberWalls = randomInt(25, 50);
        workRandomUpWalls(gameBoard, numberWalls);
        workRandomUpObjects(gameBoard, robots);
    }while(workTryMap(gameBoard, robots, gameParameters));
    saveMap(gameBoard, gameParameters, "maps/random.map");
}

// Randomly place walls.
void workRandomUpWalls(Object gameBoard[SIZE][SIZE], int numberWalls)
{
    int i;
    int x, y;
    int restart;
    for(i=0; i<numberWalls; i++){
        restart = 1;
        while(restart){
            restart = 0;
            x = randomInt(1, 32);
            y = randomInt(1, 32);
            if(x%2 != y%2){
                gameBoard[x][y].Type = WALL;
            } else restart = 1;
        }
    }
}

// Randomly place robots and objective.
void workRandomUpObjects(Object gameBoard[SIZE][SIZE], Object robots[4])
{
    int i;
    int x, y;
    int restart;
    for(i=0; i<5; i++){ // All robots + Goal
        restart = 1;
        while(restart){
            x = randomInt(2, 30);
            y = randomInt(2, 30); // No robot or Goal next a game border.
            if(gameBoard[x][y].Type == BLANK && ( x%2 == 1 && y%2 == 1 )){
                restart = 0;
                switch(i)
                {
                    case Q:
                        gameBoard[x][y].character = 'Q';
                        break;

                    case W:
                        gameBoard[x][y].character = 'W';
                        break;

                    case E:
                        gameBoard[x][y].character = 'E';
                        break;

                    case R:
                        gameBoard[x][y].character = 'R';
                        break;

                    case 4: //This is the Goal
                        gameBoard[x][y].character = '#';
                        gameBoard[x][y].Type = GOAL;
                        break;
                }
                if(i != 4){ // i != 4 => it's a ROBOT
                    gameBoard[x][y].Type = ROBOT;
                    robots[i].x = x;
                    robots[i].y = y;
                }
            }
        }
    }
}

// Test the map if it is playable. Returns 0 if definable.
int workTryMap(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters)
{
    int i, j;
    int notAvailable = 1;
    gameParameters->numberPoints = 0;

    // Copy robots :
    Object robotsCopy[4];
    for(i=0; i<4; i++)
        robotsCopy[i] = robots[i];

    // Copy gameParameters
    Parameters gameParametersCopy = *gameParameters;

    // Copy gameBoard
    Object gameBoardCopy[SIZE][SIZE];
    for(i=0; i<33; i++)
        for(j=0; j<33; j++)
            gameBoardCopy[i][j] = gameBoard[i][j];

    int randomRobot;
    for(j=0; j<4000; j++){
        while(!robotsCopy[randomRobot = randomInt(0, 4)].removable);
        if(robotsCopy[randomRobot].removable){
            workRandomMoves(gameBoardCopy, &robotsCopy[randomRobot], &gameParametersCopy, randomInt(0, 4));
        }
        if(gameParametersCopy.numberPoints == 4){
            notAvailable = 0;
            break;
        }
    }
    return notAvailable;
}

// Moves robots virtually based on a true random Management.
void workRandomMoves(Object gameBoard[SIZE][SIZE], Object *robot, Parameters *gameParameters, int direction)
{
    int bottom = 0, right = 0;

    switch(direction)
    {
        case TOP:
            bottom = -1;
            break;

        case BOTTOM:
            bottom = 1;
            break;

        case LEFT:
            right = -1;
            break;

        case RIGHT:
            right = 1;
            break;
    }

    if(robot->removable){
        // while where you want to go, there is no wall or ROBOT or Goal, you can move
        while(gameBoard[robot->x+bottom][robot->y+right].Type != WALL
              && gameBoard[robot->x+2*bottom][robot->y+2*right].Type != ROBOT
              && gameBoard[robot->x+2*bottom][robot->y+2*right].Type != GOAL){

            workErase(gameBoard, *robot);

            // 2 possibilities : (bottom = 1 || -1)  (EXCLUSIVE OR)  (right = 1 || -1)
            if(bottom != 0) robot->x = (robot->x) + 2*bottom;
            else robot->y = (robot->y) + 2*right;

            workPut(gameBoard, *robot);
        }

        // if there is the goal next you, you won a point
        if(gameBoard[robot->x+2*bottom][robot->y+2*right].Type == GOAL
           && gameBoard[robot->x+1*bottom][robot->y+1*right].Type != WALL){

            workErase(gameBoard, *robot);
            robot->removable = 0;
            (gameParameters->numberPoints)++;
        }
    }
}
