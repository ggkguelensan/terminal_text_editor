#include "output.h"

void editorRefreshScreen(void)
{
    if(write(STDOUT_FILENO, "\x1b[2J", 4) < 0)
    die("write \x1b[2J");
    if(write(STDOUT_FILENO, "\x1b[H", 3) < 0)
    die("write \x1b[H");

    editorDrawRows();

    if(write(STDOUT_FILENO, "\x1b[H", 3))
    die("write");
}

void editorDrawRows(void)
{
    int y;
    for(y = 0; y < 24; y++)
    {
        if(write(STDOUT_FILENO, "~\r\n", 3))
        die("write");
    };
}