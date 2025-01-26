#include "cpl-include.h"

/* This is a simple linked list lib for managing variables. */

typedef enum {
    INT, CHAR, CHARL, DATE
} vartype;

#define VAR_NAME_LEN 33 // 32 chars plus null

struct variable {
    char name[VAR_NAME_LEN];
    vartype type;
    char *val;
    struct variable *next;
};

struct variable *cpl_variables = NULL;

// find a var pointer. O(n)
struct variable *cpl_find_var(const char *name) {
    // upcase var name
    char n[VAR_NAME_LEN];
    snprintf(n, VAR_NAME_LEN, "%s", name);
    strtoupper(n);

    struct variable *p = cpl_variables;
    while (p != NULL) {
        if (strcmp(p->name, n) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}

void cpl_set_var(const char *name, const char *val) {
    // get node space
    struct variable *n;
    // get existing or create new
    if ((n = cpl_find_var(name)) == NULL)
        n = malloc(sizeof(struct variable));
    else
        free(n->val); // get rid of old val!
    if (n == NULL)
        cpl_error_end(17, 0, name);
    // get var val space. name len limited!
    size_t len = strlen(val) + 1;
    n->val = malloc(len);
    if (n->val == NULL)
        cpl_error_end(17, 0, name);
    //set var name
    snprintf(n->name, VAR_NAME_LEN, "%s", strtoupper(name));
    snprintf(n->val, len, "%s", val);
    // add to list. O(1)
    n->next = cpl_variables;
    cpl_variables = n;
}

// get var value. O(n)
char *cpl_get_var(const char *name) {
    struct variable *n = cpl_find_var(name);
    return (n != NULL) ? n->val : NULL;
}

// destroy all variable data.
void cpl_destroy_all_vars() {
    struct variable *c, *p = cpl_variables;
    while (p != NULL) {
        free(p->val);
        c = p;
        p = p->next;
        free(c);
    }
}