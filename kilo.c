#include "terminal.h"
#include "input.h"

#include <stdio.h>
#include <stdio.h>

int main(void)
{
    enableRawMode();

    while(1)
    {
        editorRefreshScreen();
        editorProcessKeypress();
    };

    return EXIT_SUCCESS;
}