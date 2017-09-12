// Contains all functions related to editing mode.

#ifndef WORK_EDITOR
    #define WORK_EDITOR

    // Main function of the editing mode.
    void workEditor(Object gameBoard[SIZE][SIZE], Object robots[4], Parameters *gameParameters);

    // Checks whether the object is already on the ground, if so, returns 1 otherwise returns 0.
    int workEditorAlreadyOne(Object gameBoard[SIZE][SIZE], Object object);

    // Adds an object on the gameboard.
    void workEditorAdd(Object gameBoard[SIZE][SIZE]);

#endif
