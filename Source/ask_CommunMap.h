// Interactions with user during the game

#ifndef ASK_ONEPLAYER
	#define ASK_ONEPLAYER

    // User selects which robot he wants move
	int askExchangeRobot(void);

    // User selects the direction where he wants move
	int askDirection(void);

    // Allows to pause to see results
    void askContinue(void);

#endif
