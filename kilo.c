#include "terminal.h"
#include "input.h"
#include "output.h"

#include <stdio.h>
#include <stdio.h>

struct editor_config E;

void initEditior(struct editor_config E)
{
    if(getWindowSize(&E.screenrows, &E.screencols) < 0)
    die("initEditior getWindowSize");
}

int main(void)
{
    enableRawMode(E);
    initEditor(E);

    while(1)
    {
        editorRefreshScreen(E);
        editorProcessKeypress();
    };

    return EXIT_SUCCESS;
}