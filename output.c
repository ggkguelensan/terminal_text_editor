#include "output.h"

void editorRefreshScreen(struct editor_config E)
{
    if(write(STDOUT_FILENO, "\x1b[2J", 4) < 0) die("editorRefreshScreen write");
    if(write(STDOUT_FILENO, "\x1b[H", 3) < 0) die("editorRefreshScreen write");

    editorDrawRows(E);

    if(write(STDOUT_FILENO, "\x1b[H", 3) < 0) die("editorRefreshScreen write");
}

void editorDrawRows(struct editor_config E)
{
    int row;
    for(row = 0; row < E.screenrows; row++)
    {
        if(write(STDOUT_FILENO, "~\r\n", 3) < 0) die("editorDrawRows write");
    };
}