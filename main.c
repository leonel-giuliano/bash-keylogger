#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <string.h>

#include "main.h"


int main(void) {
    struct termios tm;
    errorEvent_t e;

    if((e = setFlags(&tm)) != 0) return errorHanlder(e);

    printf("Insert any key (%c exits the code):\n", EXIT_C);

    if(defFlags(&tm)) return errorHanlder(ERROR_SETATTR);
    return 0;
}


errorEvent_t setFlags(struct termios *tm) {
    // Get the config of the terminal
    if((tcgetattr(STDIN_FILENO, tm)) == -1) return ERROR_GETATTR;

    // Read data input without pressing Enter and do not display it
    tm->c_lflag &= ~(ICANON | ECHO);
    if((tcsetattr(STDIN_FILENO, TCSANOW, tm)) == -1) return ERROR_SETATTR;

    return 0;
}


errorEvent_t defFlags(struct termios *tm) {
    tm->c_lflag |= (ICANON | ECHO);
    if((tcsetattr(STDIN_FILENO, TCSANOW, tm)) == -1) return ERROR_SETATTR;

    return 0;
}


errorEvent_t errorHanlder(errorEvent_t e) {
    fprintf(stderr, "\nbash-keylogger: ");

    switch (e) {
        case ERROR_GETATTR:
            fprintf(
                stderr,
                "problem accessing the terminal config: %s\n",
                strerror(errno)
            );

            break;

        case ERROR_SETATTR:
            fprintf(
                stderr,
                "problem modifying the terminal config: %s\n",
                strerror(errno)
            );

            break;
    }

    return e;
}
