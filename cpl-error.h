//
// Created by Bill Jojo on 1/25/25.
//

#ifndef CPL_CPL_ERROR_H
#define CPL_CPL_ERROR_H

// struct for all errors.
typedef struct {
    int error;
    const char *text;
} CPL_ERROR;

const char *get_cpl_error(int);

#endif //CPL_CPL_ERROR_H
