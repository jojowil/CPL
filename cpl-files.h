#include <stdio.h>

#ifndef CPL_CPL_FILES_H
#define CPL_CPL_FILES_H

struct file {
    FILE *file;
    int fd;
    struct file* next;
};

int cpl_is_fd(int fd);

struct file *cpl_get_file(int fd);

int cpl_file_open(const char *name, char mode, const char *svar);

int cpl_file_close(int fd);

int cpl_file_write(const char *data, int fd, const char *svar);

char *cpl_file_read(int fd, const char *svar);

#endif //CPL_CPL_FILES_H
