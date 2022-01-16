#ifndef TERMINAL_H
#define TERMINAL_H
#endif

#include "error_handling.h"
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

struct editorConfig E;

struct termios orig_termios;

struct editorConfig
{
    struct termios orig_termios;
};

void disableRawMode(void);
void enableRawMode(void);