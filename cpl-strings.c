//
// Created by Bill Jojo on 1/12/25.
//

#include "cpl-include.h"

long cpl_strtol(const char *num) {
    char *p;
    bool success;
    errno = 0;
    long a = strtol(num, &p, 10);
    //printf("p = %p, buf = %p, len = %lu, p-buf = %ld\n", p, buf, strlen(buf), p-buf);

    // *p can be '\0' or '\n', but p cannot be buf.
    success = ((!*p || *p == '\n') && p != num && !errno);
    if (errno)
        return -1;
    else if (!success) {
        errno = EINVAL;
        return -1;
    }
    return a;
}