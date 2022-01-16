#include "input.h"

void editorProcessKeypress()
{
    char c = editorReadKey();

    switch (c)
    {
    case CTRL_KEY('q'):
        if(write(STDOUT_FILENO, "\x1b[2J", 4) < 0)
            die("editorProcessKeypress write");
        if(write(STDOUT_FILENO, "\x1b[H", 3) < 0)
            die("editorProcessKeypress write");
        exit(EXIT_SUCCESS);
        break;
    }
}

char editorReadKey(void)
{
    int nread;
    char c;
    while((nread = read(STDIN_FILENO, &c, 1)) != 1)
    {
        if(nread == -1 && errno != EAGAIN) die("editorReadKey read");
    }
    return c;
}