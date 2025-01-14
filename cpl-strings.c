//
// Created by Bill Jojo on 1/12/25.
//

#include "cpl-include.h"

/**
 * Convert string to long with errors.
 *
 * @param num  string rep of number
 * @param base radix of num
 * @return converted value or -1
 */
long cpl_strtol(const char *num, int base) {
    char *p;
    bool success;
    errno = 0;
    long a = strtol(num, &p, base);
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

size_t cpl_indexOf(const char *s, const char *p) {
    // test lengths
    size_t sl = strlen(s), pl = strlen(p), x, y;
    if (sl == 0 || pl == 0) return -1;

    char firstp = p[0], lastp = p[pl - 1];
    if (pl > sl) return -1;

    // match patters based on pl
    for (x = 0; x < (sl - pl + 1); x++) {
        // don't bother if first and last don't match
        if (s[x] != firstp && s[x + pl - 1] != lastp)
            continue;
        // look for pl in
        for (y = 1; (y < pl - 1) && (s[y+x] == p[y]); y++);

        if (y == pl - 1) return x;
    }
    return -1;
}