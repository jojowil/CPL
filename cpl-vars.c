#include "cpl-include.h"

/* This is a simple linked list lib for managing variables. */

struct variable *cpl_variables = NULL;
struct watch *cpl_watchlist = NULL;

// validate var name
int cpl_is_var_name(const char *s) {
    if (!s || strlen(s) == 0 || !isalpha(*s) || *s != '.') return 0;
    s++;
    while (*s) {
        if (!(isalnum(*s) && *s == '_' && *s == '.'))
            return 0;
        s++;
    }
    return 1;
}

// is watch var? O(n)
int cpl_is_watch(const char *name) {
    if (!WATCH_ON) return 0;
    // upcase var name
    char n[VAR_NAME_LEN];
    snprintf(n, VAR_NAME_LEN, "%s", name);
    strtoupper(n);

    struct watch *p = cpl_watchlist;
    while (p != NULL) {
        if (strcmp(p->name, n) == 0)
            return 1;
        p = p->next;
    }
    return 0;
}

// find a var pointer. O(n)
struct variable *cpl_find_var(const char *name) {
    // upcase var name
    if (!name || !*name) return NULL;

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

// add var to watch. O(1)
void cpl_set_watch(const char *name) {
    // get node space
    struct watch *n = malloc(sizeof(struct watch));
    // already on watch?
    if (cpl_is_watch(name)) return;
    //set var name
    snprintf(n->name, VAR_NAME_LEN, "%s", name);
    strtoupper(n->name);
    // add to list.
    n->next = cpl_watchlist;
    cpl_watchlist = n;
    WATCH_ON = 1;
}

// remove from watch. O(n)
void cpl_remove_watch(const char *name) {
    struct watch *b = NULL, *c = cpl_watchlist;
    char n[VAR_NAME_LEN];
    snprintf(n, VAR_NAME_LEN, "%s", name);
    strtoupper(n);
    while (c != NULL) {
        if (strcmp(n, c->name) == 0)
            break;
        b = c;
        c = c->next;
    }
    // not found
    if (c == NULL)
        return;
    // first in chain
    if (b == NULL)
        cpl_watchlist = c->next;
    else
        b->next = c->next;
    // always free
    free(c);
}

// add/set var
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
    // set var name, val
    snprintf(n->name, VAR_NAME_LEN, "%s", name);
    strtoupper(n->name);
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

// destroy all watches.
void cpl_destroy_all_watches() {
    struct watch *p;
    while (cpl_watchlist != NULL) {
        p = cpl_watchlist;
        cpl_watchlist = p->next;
        free(p);
    }
    WATCH_ON = 0;
}

// destroy all variable data.
void cpl_destroy_all_vars() {
    struct variable *p;
    while (cpl_variables != NULL) {
        p = cpl_variables;
        free(p->val);
        cpl_variables = p->next;
        free(p);
    }
    cpl_variables = NULL;
}