#ifndef CPL_CPL_FUNCTIONS_H
#define CPL_CPL_FUNCTIONS_H

// struct for all functions.
typedef struct {
    const char *text;
} CPL_FUNC_UNK;

#define UNKOS() sorry_this_is_an_unknown_os

#ifdef _WIN32
#define DIR_SEP '\'
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

#endif //CPL_CPL_FUNCTIONS_H
