#include "error_handling.h"
#include "terminal.h"
#include "input.h"
#include "output.h"

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