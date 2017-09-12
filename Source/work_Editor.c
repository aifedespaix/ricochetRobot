    #include <stdio.h>

    #include "include.h"

    #include "ask_Editor.h"
    #include "display_Editor.h"
    #include "work_Editor.h"

    #include "display_CommunMap.h"
    #include "work_CommunMap.h"

    #include "work_OnePlayer.h"

// Main function of the editing mode.
void workEditor(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters)
{
    //Copy starting
    int i;
    char mapName[20];
    sprintf(mapName, gameParameters->fileMapContent); // For saving

    Object gameBoardCopy[SIZE][SIZE]; // For testing
    int j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++) gameBoardCopy[i][j] = gameBoard[i][j];

    Parameters gameParametersCopy;
    gameParametersCopy = *gameParameters;
    //Copy ending

    createMap(gameBoard, robots, gameParameters);

    Object objectInfos;
    int whatTodo;

    int restart = 1;
    while(restart){
        displayMapEditor(gameBoard);
        displayEditorWhatToDo();
        whatTodo = askEditorWhatToDo();

        switch(whatTodo)
        {
            case 1: // Add
                workEditorAdd(gameBoard);
                break;

            case 2: // Delete
                displayEditorCoordinate('x');
                objectInfos.x = askEditorCoordinate();

                displayEditorCoordinate('y');
                objectInfos.y = askEditorCoordinate();

                workErase(gameBoard, objectInfos);
                break;

            case 3: // Clear Map
                createBasicMap(gameBoard);
                break;

            case 4: // Save
                saveMap(gameBoard, gameParameters, mapName);
                workPlaySolo(gameBoardCopy, robots, &gameParametersCopy);
                break;

            case QUIT:
                restart = 0;
                break;
        }
    }
}

// Checks whether the object is already on the ground, if so, returns 1 otherwise returns 0.
int workEditorAlreadyOne(Object gameBoard[SIZE][SIZE], Object object)
{
    int i, j;
    for(i=1; i<SIZE-1; i++)
        for(j=1; j<SIZE-1; j++)
            if(gameBoard[i][j].Type == object.Type){
                if(object.Type == ROBOT){
                    if(gameBoard[i][j].character == object.character) return 1;
                    else continue;
                }
                return 1;
            }
    return 0;
}

// Adds an object on the gameboard.
void workEditorAdd(Object gameBoard[SIZE][SIZE])
{
    Object objectInfos;

    displayMapEditor(gameBoard);

    displayEditorAddWhat();
    objectInfos.character = askEditorChooseObject();

    displayEditorCoordinate('x');
    objectInfos.y = askEditorCoordinate();

    displayEditorCoordinate('y');
    objectInfos.x = askEditorCoordinate();

    objectInfos.Type = BLANK;
    switch(objectInfos.character)
    {
        case 'M': // WALL
            if(objectInfos.x%2 != objectInfos.y%2) objectInfos.Type = WALL;
            break;

        case 'O': // GOAL
            if(objectInfos.x%2 == 1 && objectInfos.y%2 == 1)
            {
                objectInfos.Type = GOAL;
                if(!workEditorAlreadyOne(gameBoard, objectInfos))
                    objectInfos.character = '#';
                else objectInfos.Type = BLANK;
            }
            break;

        default: // ROBOT
            if(objectInfos.x%2 == 1 && objectInfos.y%2 == 1)
            {
                objectInfos.Type = ROBOT;
                if(workEditorAlreadyOne(gameBoard, objectInfos))
                    objectInfos.Type = BLANK;
            }
            break;
    }
    if(objectInfos.Type != BLANK){
        workPut(gameBoard, objectInfos);
    }
}
