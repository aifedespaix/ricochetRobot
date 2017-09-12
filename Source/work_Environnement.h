// Contains all the "special" functions such as random functions, sorting, conversion, newline ...

#ifndef WORK_ENVIRONNEMENT
	#define WORK_ENVIRONNEMENT

    // Clears it currently screen.
	void environnementClearScreen(void);

    // Retrieve a character depending on the OS used.
    char environnementMyGetchar(void);

    // Retrieve a character without the need to press the enter key (currently needs to be with linux).
    char environnementGetCharEnterLess(void);

    // x jumps lines.
    void newLine(int numberNewline);

    // x is space.
    void space(int numberSpace);

    // Expects an instant court.
    void workWait();

    // Returns a true random integer.
    int randomInt(int iMin, int iMax);

    // Converts a number to string between 0 and 999 into an integer.
    int convertCharNumbToInt(char nb[3]);

    // Converts an integer between 0 and 999 string.
    void convertIntNumbToChar(int nb, char number[3]);

#endif
