#include <terminal.h>

void die(char const *err_msg)
{
    if(write(STDOUT_FILENO, "\x1b[2J", 4) < 0)
    die("write \x1b[2J");
    if(write(STDOUT_FILENO, "\x1b[H", 3) < 0)
    die("write \x1b[H");

    perror(err_msg);
    exit(EXIT_FAILURE);
}

void disableRawMode(void)
{
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
    die("tcsetattr");
}

char editorReadKey(void)
{
    int nread;
    char c;
    while((nread = read(STDIN_FILENO, &c, 1)) != 1)
    {
        if(nread == -1 && errno != EAGAIN) die("read");
    }
    return c;
}

void enableRawMode(void)
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

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw))
    die("tcsetattr");
}