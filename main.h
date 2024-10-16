#ifndef __BASH_KEYLOGGER_H__
#define __BASH_KEYLOGGER_H__


#include <termios.h>
#include <stdint.h>


#define EXIT_STR "Ctrl + H"
#define EXIT_C (char)0x08

// ERROR EVENTS

typedef uint8_t errorEvent_t;
enum {
    NO_ERROR,
    ERROR_GETATTR,
    ERROR_SETATTR,
    ERROR_READ
};


// Deactivates the ICANON and ECHO flags to read without Enter and do not print
// Can return ERROR_GETATTR or ERROR_SETATTR
errorEvent_t setFlags(struct termios *_Termios);

// Activates ICANON and ECHO
// Can return ERROR_SETATTR
errorEvent_t defFlags(struct termios *_Termios);

// Prints error msg depending on the event
errorEvent_t errorHandler(errorEvent_t _Error);


#endif
