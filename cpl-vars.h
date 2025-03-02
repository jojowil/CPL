#ifndef CPL_CPL_VARS_H
#define CPL_CPL_VARS_H

#define VAR_NAME_LEN 33 // 32 chars plus null

extern int WATCH_ON;

struct watch {
    char name[VAR_NAME_LEN];
    struct watch *next;
};

struct variable {
    char name[VAR_NAME_LEN];
    char *val;
    struct variable *next;
};

int cpl_is_var_name(const char *s);

int cpl_is_watch(const char *name);

struct variable *cpl_find_var(const char *name);

void cpl_set_watch(const char *name);

void cpl_remove_watch(const char *name);

void cpl_set_var(const char *name, const char *val);

char *cpl_get_var(const char *name);

void cpl_destroy_all_watches();

void cpl_destroy_all_vars();

#endif //CPL_CPL_VARS_H
