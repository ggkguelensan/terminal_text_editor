#ifndef INPUT_H
#define INPUT_H

#include "data.h"
#include "error_handling.h"

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define CTRL_KEY(k) ((k) & 0x1f)

void editorProcessKeypress(void);
char editorReadKey(void);

#endif