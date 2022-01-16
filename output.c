#include "output.h"

void editorRefreshScreen(void)
{
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    editorDrawRows();

    write(STDOUT_FILENO, "\x1b[H", 3);
}

void editorDrawRows(void)
{
    int y;
    for(y = 0; y < 24; y++)
    {
        write(STDOUT_FILENO, "~\r\n", 3);
    };
}