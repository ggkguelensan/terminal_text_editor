#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>

struct termios orig_termios;

struct editorConfig
{
    struct termios orig_termios;
};

struct editorConfig E;

#define CTRL_KEY(k) ((k) & 0x1f)

void die(char const *err_msg)
{
    perror(err_msg);
    exit(EXIT_FAILURE);
}

void disableRawMode()
{
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
    die("tcsetattr");
}

void enableRawMode()
{
    if(tcgetattr(STDIN_FILENO, &E.orig_termios) == -1)
        die("tcgetattr");
    if(tcgetattr(STDIN_FILENO, &orig_termios) == -1)
        die("tcgetattr");
    atexit(disableRawMode);

    //struct termios raw = orig_termios;
    //tcgetattr(STDIN_FILENO, &raw);

    struct termios raw = E.orig_termios;
    raw.c_iflag &= ~(IXON | ICRNL | BRKINT | ICRNL | ISTRIP);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag &= ~(CS8);
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw)) die("tcsetattr");
}

char editorReadKey()
{
    int nread;
    char c;
    while((nread = read(STDIN_FILENO, &c, 1)) != 1)
    {
        if(nread == -1 && errno != EAGAIN) die("read");
    }
    return c;
}

void editorRefreshScreen()
{
    if(write(STDOUT_FILENO, "\x1b[2J", 4) < 0) die("write \x1b[2J");
    if(write(STDOUT_FILENO, "\x1b[H", 3) < 0) die("write \x1b[H");
}

void editorProcessKeypress()
{
    char c = editorReadKey();

    switch (c)
    {
    case CTRL_KEY('q'):
        exit(EXIT_SUCCESS);
        break;
    }
}

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