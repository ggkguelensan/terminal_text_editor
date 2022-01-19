#include "output.h"

void editorRefreshScreen(void)
{
    if(write(STDOUT_FILENO, "\x1b[2J", 4) < 0) die("editorRefreshScreen write");
    if(write(STDOUT_FILENO, "\x1b[H", 3) < 0) die("editorRefreshScreen write");

    editorDrawRows();

    if(write(STDOUT_FILENO, "\x1b[H", 3) < 0) die("editorRefreshScreen write");
}

void editorDrawRows(void)
{
    int row;
    for(row = 0; row < E.screenrows; row++)
    {
        if(write(STDOUT_FILENO, "~\r\n", 3) < 0) die("editorDrawRows write");
    };
}