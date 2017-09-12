	#include <stdio.h>
	#include <stdlib.h>

	#include "include.h"

	#include "work_Environnement.h"

// Clears it currently screen.
void environnementClearScreen(void)
{
	switch(OS){
		case LINUX:
			system("clear");
		break;

		case APPLE:
			/*system("clear");*/ // Not sure
		break;

		case WINDOWS:
			system("cls");
		break;
	}
}

// Retrieve a character depending on the OS used.
char environnementMyGetchar(void)
{
	char character;
	switch(OS){
		case LINUX:
			character = environnementGetCharEnterLess();
		break;

		default:
			scanf("%c", &character);
			while(getchar() != '\n');
		break;
	}

	return character;
}

// Retrieve a character without the need to press the enter key (currently needs to be with linux).
char environnementGetCharEnterLess(void)
{
	// Source : http://forums.macg.co/developpement-mac/lire-touche-appuyer-entree-c-176764.html
	struct termios tios;
	tcgetattr(STDIN_FILENO, &tios);

	tcflag_t old_c_lflag = tios.c_lflag;

	tios.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &tios);

	unsigned char c;
	read(STDIN_FILENO, &c, 1);
	fflush(stdout);

	tios.c_lflag = old_c_lflag;
	tcsetattr(STDIN_FILENO, TCSANOW, &tios);

	return c;
}

// x jumps lines.
void newLine(int numberNewline)
{
	int i;
	for(i=0; i<numberNewline; i++)
		printf("\n");
}

// x is space.
void space(int numberSpace)
{
	int i;
	for(i=0; i<numberSpace; i++)
		printf(" ");
}

// Expects an instant court.
void workWait()
{
    usleep(100000);
}

// Returns a true random integer.
int randomInt(int iMin, int iMax)
{
    return (iMin+rand()%(iMax-iMin));
}

// Converts a number to string between 0 and 999 into an integer.
int convertCharNumbToInt(char nb[3])
{
    int size = 0;
    int number = 0;
    int multiple;

    //Calc size of number array
    int i = 0;
    int j;
    while(i++<3 && nb[i] != '\0') size++;

    // Convert to int
    i = 0;
    while(nb[i] != '\0' && i<3){
        multiple = 1;
        for(j=size; j>i; j--){
            multiple *= 10;
        }
        number = number + multiple*(((int)nb[i])-48);
        i++;
    }
    return number;
}

// Converts an integer between 0 and 999 string.
void convertIntNumbToChar(int nb, char number[3])
{
    int i;
    // Reset number
    for(i=0; i<3; i++){
        number[i] = '0';
    }

    // Create value
    i = 2;
    while(nb != 0){
        number[i] = (char)(nb % 10 + 48);
        nb = (nb - nb%10)/10;
        i--;
    }
}
