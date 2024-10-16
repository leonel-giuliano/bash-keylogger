#include <unistd.h>
#include <termios.h>

#include "main.h"


errorEvent_t setFlags(struct termios *tm) {
    // Get the config of the terminal
    if((tcgetattr(STDIN_FILENO, tm)) == -1) return ERROR_GETATTR;

    // Read data input without pressing Enter and do not display it
    tm->c_lflag &= ~(ICANON | ECHO);

    if((tcsetattr(STDIN_FILENO, TCSANOW, tm)) == -1) return ERROR_GETATTR;

    return 0;
}
