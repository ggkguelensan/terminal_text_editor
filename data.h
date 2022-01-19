#ifndef DATA_H
#define DATA_H

#include <termios.h>

typedef struct
{
    int screenrows;
    int screencols;
    struct termios orig_termios;
} editor_config;

extern editor_config E;

#endif