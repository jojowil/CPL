#include "cpl-include.h"

const char *cpl_functions[] = {"ABBREV", "AFTER", "ATTRIB", "BEFORE", "CALC",
                               "CND_INFO", "DATE", "DIR", "ENTRYNAME", "EXISTS",
                               "EXPAND_SEARCH_RULES", "GET_VAR", "GVPATH", "HEX", "INDEX",
                               "KLMD", "KLMF", "KLMT", "LENGTH", "MOD",
                               "NULL", "OCTAL", "OPEN_FILE", "PATHNAME", "QUERY",
                               "QUOTE", "READ_FILE", "RESCAN", "RESPONSE", "RESUME",
                               "SEARCH", "SUBST", "SUBSTR", "TO_HEX", "TO_OCTAL",
                               "TRANSLATE", "TRIM", "UNQUOTE", "VERIFY", "WILD",
                               "WRITE", "FILE"};

#define NUM_FUNC sizeof(cpl_functions)/sizeof(cpl_functions[0])

// is this a function?
int is_cpl_function(const char *dir) {
    for (int x = 0; x < NUM_FUNC; x++)
        if (strcmp(cpl_functions[x], dir) == 0)
            return 1;
    return 0;
}

char *after(const char *s) {

    return NULL;
}