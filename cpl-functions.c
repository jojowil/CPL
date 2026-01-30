// struct for all functions.
typedef struct {
    const char *text;
} CPL_FUNC_UNK;

#define UNKOS() sorry_this_is_an_unknown_os

#ifdef _WIN32
#define DIR_SEP '\\'
#elif __linux__
#define DIR_SEP '/'
#elif __APPLE__
#define DIR_SEP '/'
#else
UNKOS();
#endif

typedef enum {
    CABBREV, CAFTER, CATTRIB, CBEFORE, CCALC, CCLOSE,
    CCND_INFO, CDATE, CDIR, CENTRYNAME, CEXISTS,
    CEXPAND_SEARCH_RULES, CGET_VAR, CGVPATH, CHEX, CINDEX,
    CKLMD, CKLMF, CKLMT, CLENGTH, CMOD,
    CNULL, COCTAL, COPEN_FILE, CPATHNAME, CQUERY,
    CQUOTE, CREAD_FILE, CRESCAN, CRESPONSE, CRESUME,
    CSEARCH, CSUBST, CSUBSTR, CTO_HEX, CTO_OCTAL,
    CTRANSLATE, CTRIM, CUNQUOTE, CVERIFY, CWILD,
    CWRITE_FILE
} CPL_FUNC;

int is_cpl_function(const char *dir);
void func_not_implemented(const char *name);
char *f_abbrev(const char *s);
char *f_after(const char *s, const char *f);
char *f_attrib();
char *f_before(const char *s, const char *f);
char *f_calc();
char *f_close(const char *fd);
char *f_date(const char *s);
char *f_dir(const char *s);
char *f_entryname(const char *s);
char *f_exists(const char *s, const char *t, int b);
char *f_get_var(const char *s);
char *f_gvpath();
char *f_hex(const char *s);
char *f_index(const char *s, const char *f);
char *f_length(const char *s);
char *f_mod(const char *s, const char *t);
char *f_null(const char *s);
char *f_octal(const char *s);
char *f_open_file(const char *f, const char *mode, const char *svar);
char *f_pathname(const char *s);
char *f_query(const char *s);
char *f_quote(const char *s);
char *f_read_file(const char *fd, const char *svar);
char *f_rescan(const char *s);
char *f_response(const char *s);
char *f_resume(const char *s);
char *f_search(const char *s, const char *chars);
char *f_subst(const char *s, const char *find, const char *replace);
char *f_substr(const char *s, const char *start, const char *len);
char *f_to_hex(const char *s);
char *f_to_octal(const char *s);
char *f_translate(const char *s);
char *f_trim(const char *s, const char *dir, char tc);
char *f_unquote(const char *s);
char *f_verify(const char *s);
char *f_wild(const char *s);
char *f_write_file(const char *data, const char *fd, const char *svar);

/* CLOSE is not a standard CPL function.
 * It was originally a Primos command, but added
 * for completeness of functionality.
 */

const char *TRUE = "TRUE";
const char *FALSE = "FALSE";

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

// converts string to new base. Caller must free result.
char *base_cvrt(const char *s, int fb, int tb) {
    char *fmt;
    if (!s) return NULL;
    char n[VAR_NAME_LEN];
    // from base
    long l = cpl_strtol(s, fb);
    if (errno) cpl_error_end(5, CPL_LINE_NO, s);
    // to base
    if (tb == 8)
        fmt = "%lo";
    else if (tb == 10)
        fmt = "%ld";
    else if (tb == 16)
        fmt = "%lX";
    snprintf(n, VAR_NAME_LEN, fmt, l);
    return strdup(n);
}

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

// get environment var from user space. Caller must free result.
char *f_abbrev(const char *s) {
    char *v = getenv(s);
    if (v)
        return strdup(v);
    return NULL;
}

// return string after f. Caller must free result.
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

// return string before f. Caller must free result.
char *f_before(const char *s, const char *f) {
    if (s == NULL || f == NULL) return NULL;
    // find location
    char *p = strstr(s, f);
    // get string before
    return (p) ? strndup(s, p - s) : NULL;
}

// this should also be the core expression eval function.
char *f_calc() {

    return NULL;
}

// close a file fd. no confirmation check. don't care right now.
char *f_close(const char *fd) {
    long f = cpl_strtol(fd, 10);
    cpl_file_close(f);
    return NULL;
}

// NULL is OK. Caller must free result.
char *f_date(const char *s) {
    char *fmt, *t = strtoupper(strdup((s) ? s : ""));
    time_t tt = time(NULL);
    struct tm buf;
    char res[VAR_NAME_LEN];

    // fill buf through tt.
    localtime_r(&tt, &buf);
    // TODO: Make these timezone dependent?
    // s represents format specifier...
    if (strlen(t) == 0)
        fmt = "%y-%m-%d";
    else if (strcmp(t, "-FULL") == 0)
        fmt = "%y-%m-%d.%T.%a"; // 10/26/89.11:19:00.Tue
    else if (strcmp(t, "-USA") == 0)
        fmt = "%D"; // 10/26/89
    else if (strcmp(t, "-UFULL") == 0)
        fmt = "%D.%T.%a"; // 10/26/89.11:19:00.Tue
    else if (strcmp(t, "-VFULL") == 0)
        fmt = "%d %b %y %T %A"; // 26 Oct 89 11:19:00 Tuesday
    else if (strcmp(t, "-DAY") == 0)
        fmt = "%d";
    else if (strcmp(t, "-MONTH") == 0)
        fmt = "%B";
    else if (strcmp(t, "-YEAR") == 0)
        fmt = "%Y";
    else if (strcmp(t, "-VIS") == 0)
        fmt = "%d %b %y"; // 26 Oct 89
    else if (strcmp(t, "-TIME") == 0)
        fmt = "%T";
    else if (strcmp(t, "-AMPM") == 0)
        fmt = "%I:%M %p"; // 11:19 PM
    else if (strcmp(t, "-DOW") == 0)
        fmt = "%A";
    else if (strcmp(t, "-CAL") == 0)
        fmt = "%B %d, %Y"; // October 26, 1989
    else if (strcmp(t, "-TAG") == 0)
        fmt = "%y%m%d";
    else if (strcmp(t, "-FTAG") == 0)
        fmt = "%y%m%d.%H%M%S";

    strftime(res, VAR_NAME_LEN, fmt, &buf);
    free(t);
    return strdup(res);
}

// get dir of a pathname. returns quoted string.
char *f_dir(const char *s) {
    // need to find last pathname separator
    if (!s) return NULL;
    return NULL;
}

// get filename of a pathname
char *f_entryname(const char *s) {
    if (!s) return NULL;
    return NULL;
}

// determine if a pathname exists. Caller must free result.
char *f_exists(const char *s, const char *t, int b) {

    return strdup(FALSE);
}

// get var value. Caller must free result.
char *f_get_var(const char *s) {
    struct variable *p = cpl_find_var(s);
    return (p) ? strdup(p->val) : NULL;
}

// global var file not implemented. always return "-OFF"
char *f_gvpath() {
    return strdup("-OFF");
}

// convert hex string to base 10. Caller must free result.
char *f_hex(const char *s) {
    return base_cvrt(s, 16, 10);
}

// find index of f in s. this is 1 based. Caller must free result.
char *f_index(const char *s, const char *f) {
    if (!s || !f) return NULL;
    char n[VAR_NAME_LEN];
    // find location
    char *p = strstr(s, f);
    // convert number to string
    size_t l = (p) ? p - s + 1 : 0;
    snprintf(n, VAR_NAME_LEN, "%lu", l);
    return strdup(n);
}

// get length of string. Caller must free result.
char *f_length(const char *s) {
    char n[VAR_NAME_LEN];
    size_t l = (s) ? strlen(s) : 0;
    snprintf(n, VAR_NAME_LEN, "%lu", l);
    return strdup(n);
}

char *f_mod(const char *s, const char *t) {

    return NULL;
}

// check if NULL or zero length. Caller must free result.
// TODO: handle quoted string ''.
char *f_null(const char *s) {
    if (!s || !*s) return strdup(TRUE);
    return strdup(FALSE);
}

// convert octal string to base 10.
char *f_octal(const char *s) {
    return base_cvrt(s, 8, 10);
}

char *f_open_file(const char *f, const char *mode, const char *svar) {

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

char *f_read_file(const char *fd, const char *svar) {
    int f = (int)cpl_strtol(fd, 10);
    cpl_get_file(f);

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

char *f_search(const char *s, const char *chars) {

    return NULL;
}

char *f_subst(const char *s, const char *find, const char *replace) {

    return NULL;
}

char *f_substr(const char *s, const char *start, const char *len) {

    return NULL;
}

char *f_to_hex(const char *s) {
    return base_cvrt(s, 10, 16);
}

char *f_to_octal(const char *s) {
    return base_cvrt(s, 10, 8);
}

char *f_translate(const char *s) {

    return NULL;
}

char *f_trim(const char *s, const char *dir, char tc) {

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

char *f_write_file(const char *data, const char *fd, const char *svar) {

    return NULL;
}

#ifndef CPL_MAIN

int main (void) {
    return 0;
}

#endif
