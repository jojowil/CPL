#ifndef CPL_CPL_VARS_H
#define CPL_CPL_VARS_H

struct variable *cpl_find_var(const char *name);

void cpl_add_var(const char *name, const char *val);

char *cpl_get_var(const char *name);

void cpl_destroy_all_vars();

#endif //CPL_CPL_VARS_H
