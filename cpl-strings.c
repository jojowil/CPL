long cpl_strtol(const char *num, int base);

size_t strindexof(const char *s, const char *p);

char *strtoupper(char *s);

char *strtolower(char *s);

int strtolines(const char *chars, char ***lines);

/**
 * Convert string to long with errors.
 *
 * @param num  string rep of number
 * @param base radix of num
 * @return converted value or -1
 */
long cpl_strtol(const char *num, int base) {
    char *p;
    int success;
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

size_t strindexof(const char *s, const char *p) {
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

char *strtoupper(char *s) {
    char c, *p = s;
    while ((c = *p))
        *p++ = toupper(c);
    return s;
}

char *strtolower(char *s) {
    char c, *p = s;
    while ((c = *p))
        *p++ = tolower(c);
    return s;
}

int strtolines(const char *chars, char ***lines) {
    int numlines = 0;
    const char *b, *c = chars;

    while (*c) {
        b = c;
        while (*c && *c++ != '\n');
        size_t len = c - b;
        if (((*lines)[numlines] = malloc(len + 1)) == NULL)
            cpl_error_end(1, 0, NULL);
        memcpy((*lines)[numlines], b, len);
        (*lines)[numlines++][len] = '\0';
    }
    return numlines;
}

#ifndef CPL_MAIN

int main (void) {
    return 0;
}

#endif