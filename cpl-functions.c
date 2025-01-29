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

void func_not_implemented(const char *name) {
    fprintf(stderr, "Function %s is not implemented.\n", name);
}

char *cpl_abbrev(const char *s) {

}

char *cpl_after(const char *s) {

    return NULL;
}

char *cpl_attrib() {

}

char *cpl_before() {

}

char *cpl_calc() {

}

char *cpl_date() {

}

char *cpl_dir() {

}

char *cpl_entryname() {

}

char *cpl_exists() {

}

char *cpl_get_var() {

}

char *cpl_gvpath() {
    return strdup("-OFF");
}

char *cpl_hex(const char *s) {

}

char *cpl_index(const char *s, const char *f) {

}

char *cpl_length(const char *s) {

}

char *cpl_mod(const char *s, const char *t) {

}

char *cpl_null(const char *s) {

}

char *cpl_octal(const char *s) {

}

char *cpl_open_file(const char *s) {

}

char *cpl_pathname(const char *s) {

}

char *cpl_query(const char *s) {

}

char *cpl_quote(const char *s) {

}

char *cpl_read_file(const char *s) {

}

char *cpl_rescan(const char *s) {

}

char *cpl_response(const char *s) {

}

char *cpl_resume(const char *s) {

}

char *cpl_search(const char *s) {

}

char *cpl_subst(const char *s) {

}

char *cpl_substr(const char *s) {

}

char *cpl_to_hex(const char *s) {

}

char *cpl_to_octal(const char *s) {

}

char *cpl_translate(const char *s) {

}

char *cpl_trim(const char *s) {

}

char *cpl_unquote(const char *s) {

}

char *cpl_verify(const char *s) {

}

char *cpl_wild(const char *s) {

}

char *cpl_write_file(const char *s) {

}

