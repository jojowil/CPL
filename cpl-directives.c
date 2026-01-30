#include "cpl-include.h"

typedef enum {
    ARGS, BY, CALL, CHECK, DATA,
    DEBUG, DO, ECHO, ELSE, END,
    ERROR, EXECUTE, EXPAND, FAIL, GOTO,
    IF, IGNORE, ITEMS, LABEL, LIST,
    MESSAGE, NO_ECHO, NO_EXECUTE, NO_RETURN, NO_WATCH,
    ON, OTHERWISE, REPEAT, RESULT, RETURN, REVERT,
    ROUTINE, SELECT, SET_VAR, SEVERITY, SIGNAL,
    STOP, THEN, TO, TTY, TTY_CONTINUE,
    UNTIL, WARNING, WATCH, WHEN, WHILE
} CPL_DIR;

int is_cpl_directive(const char *dir);

const char *cpl_directives[] = {
        "&ARGS", "&BY", "&CALL", "&CHECK", "&DATA",
        "&DEBUG", "&DO", "&ECHO", "&ELSE", "&END",
        "&ERROR", "&EXECUTE", "&EXPAND", "&FAIL", "&GOTO",
        "&IF", "&IGNORE", "&ITEMS", "&LABEL", "&LIST",
        "&MESSAGE", "&NO_ECHO", "&NO_EXECUTE", "&NO_RETURN", "&NO_WATCH",
        "&ON", "&OTHERWISE", "&REPEAT", "&RESULT", "&RETURN", "&REVERT",
        "&ROUTINE", "&SELECT", "&SET_VAR|&S", "&SEVERITY", "&SIGNAL",
        "&STOP", "&THEN", "&TO", "&TTY", "&TTY_CONTINUE",
        "&UNTIL", "&WARNING", "&WATCH", "&WHEN", "&WHILE"
};

#define NUM_DIRECT sizeof(cpl_directives)/sizeof(cpl_directives[0])

// is this a directive?
int is_cpl_directive(const char *dir) {
    for (int x = 0; x < NUM_DIRECT; x++)
        if (strcmp(cpl_directives[x], dir) == 0)
            return x;
    return 0;
}

#ifndef CPL_MAIN

int main (void) {
    return 0;
}

#endif