#include "cpl-include.h"

/* CLOSE is not a standard CPL function.
 * It was originally a Primos command, but added
 * for completeness of functionality.
 */

const char *cpl_functions[] = {
        "ABBREV|AB", "AFTER", "ATTRIB", "BEFORE", "CALC", "CLOSE",
        "CND_INFO", "DATE", "DIR", "ENTRYNAME", "EXISTS",
        "EXPAND_SEARCH_RULES", "GET_VAR", "GVPATH", "HEX", "INDEX",
        "KLMD", "KLMF", "KLMT", "LENGTH", "MOD",
        "NULL", "OCTAL", "OPEN_FILE", "PATHNAME", "QUERY",
        "QUOTE", "READ_FILE", "RESCAN", "RESPONSE", "RESUME",
        "SEARCH", "SUBST", "SUBSTR", "TO_HEX", "TO_OCTAL",
        "TRANSLATE", "TRIM", "UNQUOTE", "VERIFY", "WILD",
        "WRITE_FILE"
};

#define NUM_FUNC sizeof(cpl_functions)/sizeof(cpl_functions[0])

// is this a function?
int is_cpl_function(const char *dir) {
    for (int x = 0; x < NUM_FUNC; x++)
        if (strcmp(cpl_functions[x], dir) == 0)
            return 1;
    return 0;
}

// note that a function is note implemented. non-fatal at this point.
void func_not_implemented(const char *name) {
    fprintf(stderr, "Function %s is not implemented.\n", name);
}

// get environment var from user space
char *f_abbrev(const char *s) {
    char *v = getenv(s);
    if (v)
        return strdup(v);
    return NULL;
}

char *f_after(const char *s, const char *f) {
    if (s == NULL || f == NULL) return NULL;
    // find location
    size_t flen = strlen(f);
    char *p = strstr(s, f);
    // get string after
    return (p) ? strndup(s, strlen(p + flen) + 1) : NULL;
}

char *f_attrib() {

    return NULL;
}

char *f_before(const char *s, const char *f) {
    if (s == NULL || f == NULL) return NULL;
    // find location
    char *p = strstr(s, f);
    // get string before
    return (p) ? strndup(s, p - s) : NULL;
}

char *f_calc() {

    return NULL;
}

char *f_date(const char *s) {
    // s represents format specifier...
    return NULL;
}

// get dir of a pathname
char *f_dir(const char *s) {
    // need to f
    return NULL;
}

// get filename of a pathname
char *f_entryname(const char *s) {

    return NULL;
}

// determine if a pathname exists
char *f_exists(const char *s, const char *t, int b) {

    return strdup("FALSE");
}

// get var value
char *f_get_var(const char *s) {
    struct variable *p = cpl_find_var(s);
    return (p) ? strdup(p->val) : NULL;
}

// global var file not implemented. always return "-OFF"
char *f_gvpath() {
    return strdup("-OFF");
}

char *f_hex(const char *s) {

    return NULL;
}

// find index of f in s. this is 1 based.
char *f_index(const char *s, const char *f) {
    if (s == NULL || f == NULL) return NULL;
    char n[VAR_NAME_LEN];
    // find location
    char *p = strstr(s, f);
    // convert number to string
    long l = (p) ? p - s + 1 : 0;
    snprintf(n, VAR_NAME_LEN, "%ld", l);
    return NULL;
}

char *f_length(const char *s) {

    return NULL;
}

char *f_mod(const char *s, const char *t) {

    return NULL;
}

char *f_null(const char *s) {

    return NULL;
}

char *f_octal(const char *s) {

    return NULL;
}

char *f_open_file(const char *s) {

    return NULL;
}

char *f_pathname(const char *s) {

    return NULL;
}

char *f_query(const char *s) {

    return NULL;
}

char *f_quote(const char *s) {

    return NULL;
}

char *f_read_file(const char *s) {

    return NULL;
}

char *f_rescan(const char *s) {

    return NULL;
}

char *f_response(const char *s) {

    return NULL;
}

char *f_resume(const char *s) {

    return NULL;
}

char *f_search(const char *s) {

    return NULL;
}

char *f_subst(const char *s) {

    return NULL;
}

char *f_substr(const char *s) {

    return NULL;
}

char *f_to_hex(const char *s) {

    return NULL;
}

char *f_to_octal(const char *s) {

    return NULL;
}

char *f_translate(const char *s) {

    return NULL;
}

char *f_trim(const char *s) {

    return NULL;
}

char *f_unquote(const char *s) {

    return NULL;
}

char *f_verify(const char *s) {

    return NULL;
}

char *f_wild(const char *s) {

    return NULL;
}

char *f_write_file(const char *s) {

    return NULL;
}

