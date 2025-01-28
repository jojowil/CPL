#ifndef CPL_CPL_STRINGS_H
#define CPL_CPL_STRINGS_H

long cpl_strtol(const char *num, int base);

size_t strindexof(const char *s, const char *p);

char *strtoupper(char *s);

char *strtolower(char *s);

int strtolines(const char *chars, char ***lines);

#endif //CPL_CPL_STRINGS_H
