// Interactions with user during the editor.

#ifndef ASK_EDITOR
    #define ASK_EDITOR

    enum{ADD='A', DELETE='D', CLEAR='C', SAVE='S'};
    // User chooses what to do : add, remove, test, back, exit.
    int askEditorWhatToDo(void);

    // User chooses which object he wants to move: robot, goal, wall.
    char askEditorChooseObject();

    // User specifies the coordinates of the cell where he wants to handling
    int askEditorCoordinate();

#endif
