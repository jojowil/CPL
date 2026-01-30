#include <stdio.h>
#include <stdlib.h>

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

struct file *cpl_all_files = NULL;

int cpl_is_fd(int fd) {
    struct file *p = cpl_all_files;
    while (p != NULL) {
        if (p->fd == fd) return 1;
        p = p->next;
    }
    return 0;
}

// get file struct based on fd.
struct file *cpl_get_file(int fd) {
    struct file *p = cpl_all_files;
    while (p) {
        if (p->fd == fd)
            return p;
        p = p->next;
    }
    return NULL;
}

// open a file on a given mode, set a var and return the fd.
int cpl_file_open(const char *name, char mode, const char *svar) {
    char m[2] = {'\0', '\0'};
    char t[VAR_NAME_LEN];
    m[0] = tolower(mode);

    // try to open file. set var with errno.
    FILE *f = fopen(name, m);
    snprintf(t, VAR_NAME_LEN, "%d", errno);
    cpl_set_var(svar, t);
    // add new file struct on success and return fd. O(1)
    if (f) {
        struct file *sf = malloc(sizeof(struct file));
        sf->next = cpl_all_files;
        cpl_all_files->next = sf;
        sf->file = f;
        sf->fd = fileno(f);
        return sf->fd;
    }
    return 0;
}

// close fd and remove file struct entry. O(n).
int cpl_file_close(int fd) {
    FILE *file;
    if (!cpl_is_fd(fd)) return 0;
    struct file *b, *c = cpl_all_files;
    while (c != NULL) {
        if (c->fd == fd) break;
        b = c;
        c = c->next;
    }
    // not found
    if (c == NULL) return 0;
    fclose(c->file);
    // first in chain
    if (b == NULL)
        cpl_all_files = c->next;
    else
        b->next = c->next;
    // always free
    free(c);
    return 1;
}

int cpl_file_write(const char *data, int fd, const char *svar) {

}

char *cpl_file_read(int fd, const char *svar) {

}

#ifndef CPL_MAIN

int main (void) {
    return 0;
}

#endif