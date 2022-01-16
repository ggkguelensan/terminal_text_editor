#ifndef OUTPUT_H
#define OUTPUT_H
#endif

#include "data.h"
#include "error_handling.h"

#include <unistd.h>

void editorRefreshScreen(struct editor_config E);
void editorDrawRows(struct editor_config E);