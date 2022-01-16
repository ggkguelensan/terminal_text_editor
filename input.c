#include "input.h"

void editorProcessKeypress()
{
    char c = editorReadKey();

    switch (c)
    {
    case CTRL_KEY('q'):
        if(write(STDOUT_FILENO, "\x1b[2J", 4) < 0)
        die("write \x1b[2J");
        if(write(STDOUT_FILENO, "\x1b[H", 3) < 0)
        die("write \x1b[H");
        exit(EXIT_SUCCESS);
        break;
    }
}