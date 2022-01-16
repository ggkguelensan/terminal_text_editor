#ifndef TERMINAL_H
#define TERMINAL_H
#endif

#include "data.h"
#include "error_handling.h"

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

void disableRawMode(struct editor_config E);
void enableRawMode(struct editor_config E);
int getWindowSize(int *rows, int *cols);