#ifndef TERMINAL_H
#define TERMINAL_H

#include "data.h"
#include "kilo.h"
#include "error_handling.h"

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

void disableRawMode(void);
void enableRawMode(void);
int getWindowSize(int *rows, int *cols);

#endif