#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>

struct termios orig_termios;

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
    if(tcgetattr(STDIN_FILENO, &orig_termios) == -1)
    die("tcgetattr");
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    //tcgetattr(STDIN_FILENO, &raw);

    raw.c_iflag &= ~(IXON | ICRNL | BRKINT | ICRNL | ISTRIP);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag &= ~(CS8);
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw)) die("tcsetattr");
}

int main(void)
{
    enableRawMode();

    while(1)
    {
        char c = '\0';
        ssize_t read_ret = read(STDIN_FILENO, &c, 1);
        if(read_ret < 0 && errno != EAGAIN) die("read");
        if(iscntrl(c))
        {
            printf("%d\r\n", c);
        }
        else
        {
            printf("%d ('%c')\r\n", c, c);
        }
        if(c == 'q') break;
    };
    return EXIT_SUCCESS;
}