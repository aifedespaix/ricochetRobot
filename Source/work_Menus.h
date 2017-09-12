// Contains all the functions that manage menus.

#ifndef WORK_MENU
	#define WORK_MENU

    // Manages the main menu.
	void menuStart(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters);


    // Manages the difficulty menu.
    void menuDifficulty(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters);

    // Manages the editor menu.
    void menuEditor(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters, int edit);

    // Manages the menu hightcores.
    void menuScores(int scores[3]);

#endif
