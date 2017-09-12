// What is your OS ?
#if defined ( __APPLE__ )

	#define OS 1

#elif defined ( linux )

	#define OS 2
	#include <unistd.h> 	// For getchar without "enter" press
	#include <termios.h>	// For getchar without "enter" press
	#define color(param) printf("\033[%sm",param)

#else // Else, it's windows

	#define OS 3
	#include <conio.h>

#endif


#ifndef DEF_CONSTANTS
	#define DEF_CONSTANTS

	// Main array game size : 33x33 ( (16x16 : Playable) + Walls )
	#define SIZE 33

    //Enums :
	enum {TOP, BOTTOM, RIGHT, LEFT};
	enum {APPLE=1, LINUX=2, WINDOWS=3};
	enum {Q=0, W=1, E=2, R=3};
	enum {CHANGE='c'};
	enum {QUIT=-1};

	typedef enum { WALL, ROBOT, GOAL, BLANK, CROSSING } Types;


    // Structs :
	typedef struct{
		int x;
		int y;
		Types Type;
		char character;
		int removable;
	} Object;

	typedef struct{
        int nb;
        char robot;
	} robot;

	typedef struct{
		int numberPoints;
		int numberPointsPrevTurn;
		int numberTrips;
		int actualRobot;

		int numberPlayers;
		int actualPlayer;
		int bet;

		robot robotToPlace;


		char fileMapAs[20];
		char asMap[50];

		char fileMapContent[20];
		char mapContent[3000];

		char errorMessage[200];

        int map; //for hight score
        int scores[3]; // Score easy, medium and hard (map)
	} Parameters;

	typedef struct{
        int player;
        int bet;
        int numberPoints;
        int numberPointsPrevTurn;
	} Multi;

#endif
