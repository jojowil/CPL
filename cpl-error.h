#ifndef CPL_CPL_ERROR_H
#define CPL_CPL_ERROR_H

// struct for all errors.
typedef struct {
    int error;
    const char *text;
} CPL_ERROR;

const char *get_cpl_error(int err);

void cpl_error_end(int err, int line, const char *subst);

#endif //CPL_CPL_ERROR_H
