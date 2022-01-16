#include "error_handling.h"

void die(char const *err_msg)
{
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    perror(err_msg);
    exit(EXIT_FAILURE);
}