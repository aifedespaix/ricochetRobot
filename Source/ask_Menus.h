// Interacts with the user in the menu.

#ifndef ASK_MENU
	#define ASK_MENU

    // Start Menu :
    enum {ONEPLAYER, MULTIPLAYER, EDITOR, SCORES};
        // User selects a menu item.
    int askMenuStart(void);


    // Difficulty Menu :
    enum {EASY, MEDIUM, HARD, RANDOM, CUSTOM};
        // User selects the difficulty.
    int askMenuDifficulty(void);

    // Editor Menu :
        // User selects the map he wants to edit.
    int askMenuEditor(void);

    // Multiplayer
        // User selects the number of players.
    int askNumberPlayer(void);

#endif
