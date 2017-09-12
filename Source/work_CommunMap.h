// Contains all functions related to the playground used by several game modes.

#ifndef WORK_COMMUNMAP
    #define WORK_COMMUNMAP

    // Create the empty base map.
    void createBasicMap(Object gameBoard[SIZE][SIZE]);

    // Fill the map according to the map file.
    void createMap(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters);

    // Applies the movements of the robot to the desired direction.
    void workMove(Object gameBoard[SIZE][SIZE], Object *robot, Parameters *gameParameters, int direction);

    // Deletes an object from the gameboard.
    void workErase(Object gameBoard[SIZE][SIZE], Object erase);

    // Place an object on the gameboard.
    void workPut(Object gameBoard[SIZE][SIZE], Object add);

    // Save the map in array.
    void saveMapInArray(Object gameBoard[SIZE][SIZE], Parameters *gameParameters);

    // Save the map in the text file.
    void saveMap(Object gameBoard[SIZE][SIZE], Parameters *gameParameters, char file[20]);

#endif
