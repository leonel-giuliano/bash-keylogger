#ifndef __BASH_KEYLOGGER_H__
#define __BASH_KEYLOGGER_H__


#include <termios.h>
#include <stdint.h>


// ERROR EVENTS

typedef uint8_t errorEvent_t;
enum {
    NO_ERROR,
    ERROR_GETATTR,
    ERROR_SETATTR
};


// Deactivates the ICANON and ECHO flags to read without Enter and do not print
// Can return ERROR_GETATTR or ERROR_SETATTR
errorEvent_t setFlags(struct termios *_Termios);


#endif
