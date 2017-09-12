// Contains all functions related to the creation of random map.

#ifndef WORK_RANDOM
    #define WORK_RANDOM

    // Main function to create random map.
    void workCreateRandomMap(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters);

    // Randomly place walls.
    void workRandomUpWalls(Object gameBoard[SIZE][SIZE], int numberWalls);

    // Randomly place robots and objective.
    void workRandomUpObjects(Object gameBoard[SIZE][SIZE], Object robots[4]);

    // Test the map if it is playable. Returns 0 if definable.
    int workTryMap(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters);

    // Moves robots virtually based on a true random Management.
    void workRandomMoves(Object gameBoard[SIZE][SIZE], Object *robot, Parameters *gameParameters, int direction);

#endif
