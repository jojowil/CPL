//
// Created by Bill Jojo on 1/12/25.
//

#include "cpl-strings.h"

long cpl_strtol(const char* num) {
    errno = 0;
    a = strtol(buf, &p, 10);
    //printf("p = %p, buf = %p, len = %lu, p-buf = %ld\n", p, buf, strlen(buf), p-buf);

    // *p can be '\0' or '\n', but p cannot be buf.
    success = ((!*p || *p == '\n')  && p != buf && !errno);
    if (errno)
        perror("strtol");
    else if (!success)
        printf("You did not enter a valid number.\n");
}