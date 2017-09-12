	#include <time.h>
    #include <stdlib.h>

	#include "include.h"
	#include "work_Menus.h"

int main(void)
{
	srand (time (NULL));

	Object gameBoard[SIZE][SIZE];

	// Init robots
	Object robots[4];

	// 4 robots : Q W E and R
	robots[Q].character = 'Q';
	robots[W].character = 'W';
	robots[E].character = 'E';
	robots[R].character = 'R';

	// Init base values of robots objects
	int i;
	for(i=0; i<4; i++){
		robots[i].Type = ROBOT;		// Is a robot
		robots[i].removable = 1;	// Can move on the map
	}

	Parameters gameParameters;

    // Let's Play
	menuStart(gameBoard, robots, &gameParameters);

	return 0;
}
