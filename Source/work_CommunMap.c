#include <stdio.h>
#include "include.h"

#include "display_CommunMap.h"
#include "work_CommunMap.h"

#include "work_ContactFile.h"

#include "work_Environnement.h"

// Create the empty base map.
void createBasicMap(Object gameBoard[SIZE][SIZE])
{
    int i, j;
    // Reset MAP
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++){
                gameBoard[i][j].removable=0;
                gameBoard[i][j].character=' ';
                gameBoard[i][j].Type=BLANK;
            }
    // Fin reinitialise MAP

    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if(i == 0 || i==SIZE-1){
                if(j%2==0){
                    gameBoard[i][j].Type = CROSSING;
                }
                else{
                    gameBoard[i][j].Type = WALL;
                }
            }
            else if(j==0 || j==SIZE-1){
                    if(i%2 == 1){
                        gameBoard[i][j].Type = WALL;
                    }
                    else{
                        gameBoard[i][j].Type = CROSSING;
                    }
            }
            else{
                if(i%2 == 1){
                    if(j==0 || j==SIZE-1){
                        gameBoard[i][j].Type = WALL;
                    }
                    else{
                        gameBoard[i][j].Type = BLANK;
                    }
                }
                else{
                    if(j%2 == 1){
                        gameBoard[i][j].Type = BLANK;
                    }
                    else gameBoard[i][j].Type = CROSSING;
                }
            }
        }
    }
}

// Fill the map according to the map file.
void createMap(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters)
{
    createBasicMap(gameBoard);
    retrieveMapInformations(gameParameters);
    Object Stock;
    int i=0;
    while(i<3000)
    {
        if (((int)gameParameters->mapContent[i] > 57 || (int)gameParameters->mapContent[i] < 48) && gameParameters->mapContent[i] != ',' )
        {
            // Part 1, x
            Stock.character=gameParameters->mapContent[i];
            if ( (int)(gameParameters->mapContent[i+2]) >= 48 && (int)(gameParameters->mapContent[i+2]) <= 57 )
            {
                Stock.x=((int)(gameParameters->mapContent[i+2]))-48;
                Stock.x += (((int)(gameParameters->mapContent[i+1]))-48)*10;
                i+=3;
            }
            else
            {
                Stock.x=((int)(gameParameters->mapContent[i+1])-48);
                i+=2;
            }

            // Part 2, y
            if ( (int)(gameParameters->mapContent[i+2]) >= 48 && (int)(gameParameters->mapContent[i+2]) <= 57 )
            {
                Stock.y=((int)(gameParameters->mapContent[i+2]))-48;
                Stock.y += (((int)(gameParameters->mapContent[i+1]))-48)*10;
                i+=2;
            }
            else{
                Stock.y=((int)(gameParameters->mapContent[i+1])-48);
                i+=1;
            }

            //Partie 3, put on the gameboard
            gameBoard[Stock.x][Stock.y].character = Stock.character;

            if (Stock.character == 'Q'){
                gameBoard[Stock.x][Stock.y].Type = ROBOT;
                robots[0].x = Stock.x;
                robots[0].y = Stock.y;
                robots[0].Type = ROBOT;
                robots[0].character = Stock.character;
                robots[0].removable = 1;
            }
            else if (Stock.character == 'W'){
                gameBoard[Stock.x][Stock.y].Type = ROBOT;
                robots[1].x = Stock.x;
                robots[1].y = Stock.y;
                robots[1].Type = ROBOT;
                robots[1].character = Stock.character;
                robots[1].removable = 1;
            }
            else if (Stock.character == 'E'){
                gameBoard[Stock.x][Stock.y].Type = ROBOT;
                robots[2].x = Stock.x;
                robots[2].y = Stock.y;
                robots[2].Type = ROBOT;
                robots[2].character = Stock.character;
                robots[2].removable = 1;
            }
            else if (Stock.character == 'R'){
                gameBoard[Stock.x][Stock.y].Type = ROBOT;
                robots[3].x = Stock.x;
                robots[3].y = Stock.y;
                robots[3].Type = ROBOT;
                robots[3].character = Stock.character;
                robots[3].removable = 1;
            }
            else if (Stock.character == '#'){
                gameBoard[Stock.x][Stock.y].Type = GOAL;
            }
            else if(Stock.character == '-' || Stock.character == '|'){
                gameBoard[Stock.x][Stock.y].Type = WALL;
            }
        }
        i++;
    }
}

// Applies the movements of the robot to the desired direction.
void workMove(Object gameBoard[SIZE][SIZE], Object *robot, Parameters *gameParameters, int direction)
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

    int robotMoved = 0; // Boolean : if the robot moved : 1 else : 0

    if(robot->removable){
        // while where you want to go, there is no wall or ROBOT or Goal, you can move
        while(gameBoard[robot->x+bottom][robot->y+right].Type != WALL
              && gameBoard[robot->x+2*bottom][robot->y+2*right].Type != ROBOT
              && gameBoard[robot->x+2*bottom][robot->y+2*right].Type != GOAL){
            workErase(gameBoard, *robot);

            // 2 possibilities : (bottom = 1 || -1)  (EXCLUSIVE OR)  (right = 1 || -1)
            if(bottom != 0) robot->x = (robot->x) + 2*bottom;
            else            robot->y = (robot->y) + 2*right;

            workPut(gameBoard, *robot);
            displayMap(gameBoard, *gameParameters);
            workWait();
            robotMoved = 1;
        }

        if(robotMoved) (gameParameters->numberTrips)++;

        // if there is the goal next you, you won a point
        if(gameBoard[robot->x+2*bottom][robot->y+2*right].Type == GOAL
           && gameBoard[robot->x+1*bottom][robot->y+1*right].Type != WALL
           &&   (
               gameParameters->numberPlayers == 1
               ||
               gameParameters->robotToPlace.nb == gameParameters->actualRobot
                )
            ){
            workErase(gameBoard, *robot);
            robot->removable = 0;
            (gameParameters->numberPoints)++;
        }
    }
}

// Deletes an object from the gameboard.
void workErase(Object gameBoard[SIZE][SIZE], Object erase)
{
    gameBoard[(erase).x][(erase).y].Type = BLANK;
}

// Place an object on the gameboard.
void workPut(Object gameBoard[SIZE][SIZE], Object add)
{
    gameBoard[add.x][add.y].Type = add.Type;

    if(add.Type == ROBOT)
    {
        gameBoard[add.x][add.y].character = add.character;
    }
}

// Save the map in array.
void saveMapInArray(Object gameBoard[SIZE][SIZE], Parameters *gameParameters)
{
    int i, j;
    for (i=0; i<3000; i++)
    gameParameters->mapContent[i] = '\0';

    for (i=1; i<32; i++){
        for (j=1; j<32; j++){
            if ((i%2 != 0 || j%2 != 0) && gameBoard[i][j].Type != BLANK){
                if(gameBoard[i][j].Type == WALL) gameBoard[i][j].character = '-';
                sprintf(gameParameters->mapContent, "%s%c%d,%d", gameParameters->mapContent, gameBoard[i][j].character, i, j);
            }
        }
    }
}

// Save the map in the text file.
void saveMap(Object gameBoard[SIZE][SIZE], Parameters *gameParameters, char file[20])
{
    int i;
    for(i=0; i<20; i++)
        gameParameters->fileMapContent[i] = '\0';

    sprintf(gameParameters->fileMapContent, file);
    saveMapInArray(gameBoard, gameParameters);
    saveMapInformations(gameParameters);
}
