// Contains all the functions that will work with an external file.

#ifndef WORK_CONTACTFILE
	#define WORK_CONTACTFILE

    // Recovers the contents of the map file and puts it into the array.
	void retrieveMapInformations(Parameters *gameParameters);

    // Saves the array in the map file.
	void saveMapInformations(Parameters *gameParameters);

    // Retrieves the top scores in the score file.
	void retrieveHightScore(int scores[3]);

    // Saving the best scores in the score file.
	void saveHightScore(char scores[3], char destination[20]);

#endif
