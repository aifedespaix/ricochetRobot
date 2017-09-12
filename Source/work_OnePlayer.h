// Contains all functions on the single player mode.

#ifndef WORK_ONEPLAYER
	#define WORK_ONEPLAYER

    // Main function of the solo game.
	void workPlaySolo(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *GameParameters);

    // Saves the highscore if it takes place.
    void hightScore(Parameters *gameParameters);

#endif
