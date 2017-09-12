	#include <stdio.h>

	#include "include.h"

	#include "work_ContactFile.h"

	#include "work_Environnement.h"

// Recovers the contents of the map file and puts it into the array.
void retrieveMapInformations(Parameters *gameParameters)
{
    // Reset Map array
    int i;
    for (i=0; i<3000; i++)
        gameParameters->mapContent[i] = '\0';

    // recovered file content
    FILE *mapFile = NULL;
    mapFile = fopen(gameParameters->fileMapContent, "r");
    if (mapFile != NULL){
        fgets(gameParameters->mapContent, 3000, mapFile);
        fclose(mapFile);
    }
}

// Saves the array in the map file.
void saveMapInformations(Parameters *gameParameters)
{
    FILE *mapFile = NULL;
    mapFile = fopen(gameParameters->fileMapContent, "w+");
    if (mapFile != NULL){
        fprintf(mapFile, gameParameters->mapContent);
        fclose(mapFile);
    }
}

// Retrieves the top scores in the score file.
void retrieveHightScore(int scores[3])
{
    int i;
    char scoresChar[3];
    /*Init scores*/
    for (i=0; i<3; i++){
        scores[i] = 0;
        scoresChar[i] = '\0';
    }

    // Recovered file content
    FILE *scoreFile = NULL;
    scoreFile = fopen("maps/easy.score", "r");
    if (scoreFile != NULL){
        fgets(scoresChar, 4, scoreFile);
        fclose(scoreFile);
    }
    scores[0] = convertCharNumbToInt(scoresChar);

    scoreFile = fopen("maps/medium.score", "r");
    if (scoreFile != NULL){
        fgets(scoresChar, 4, scoreFile);
        fclose(scoreFile);
    }
    scores[1] = convertCharNumbToInt(scoresChar);

    scoreFile = fopen("maps/hard.score", "r");
    if (scoreFile != NULL){
        fgets(scoresChar, 4, scoreFile);
        fclose(scoreFile);
    }
    scores[2] = convertCharNumbToInt(scoresChar);
}

// Saving the best scores in the score file.
void saveHightScore(char scores[3], char destination[20])
{
    FILE *scoreFile = NULL;
    scoreFile = fopen(destination, "w+");
    if (scoreFile != NULL)
    {
        fprintf(scoreFile, scores);
        fclose(scoreFile);
    }
}

