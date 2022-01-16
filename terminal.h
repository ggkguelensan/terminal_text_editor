#ifndef TERMINAL_H
#define TERMINAL_H
#endif

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

struct editorConfig E;

struct termios orig_termios;

struct editorConfig
{
    struct termios orig_termios;
};

void die(char const *err_msg);
void disableRawMode(void);
void enableRawMode(void);
char editorReadKey(void);