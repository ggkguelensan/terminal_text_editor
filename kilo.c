#include "kilo.h"

editor_config E;

void initEditor(void)
{
    if(getWindowSize(&E.screenrows, &E.screencols) < 0)
    die("initEditior getWindowSize");
}

int main(void)
{
    enableRawMode();
    initEditor();

    while(1)
    {
        editorRefreshScreen();
        editorProcessKeypress();
    };

    return EXIT_SUCCESS;
}