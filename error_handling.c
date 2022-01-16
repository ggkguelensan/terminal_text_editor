#include "error_handling.h"

void die(char const *err_msg)
{
    if(write(STDOUT_FILENO, "\x1b[2J", 4) < 0) perror("die write");
    if(write(STDOUT_FILENO, "\x1b[H", 3) < 0) perror("die write");

    perror(err_msg);
    exit(EXIT_FAILURE);
}