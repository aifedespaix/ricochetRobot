// Contains all functions on the multiplayer game mode.

#ifndef WORK_MULTI
    #define WORK_MULTI

    // Main function of the multiplayer game.
    void workPlayMulti(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters);

    // Orders the array of players by betting.
    void workOrderPlayers(Multi players[], int numberPlayers);

    // Makes a copy of the gameboard.
    void workCopyMap(Object gameBoard[SIZE][SIZE], Object gameBoardCopy[SIZE][SIZE]);

    // Found the winner of the game.
    int workFoundWinner(Multi players[], int numberPlayers);

#endif
