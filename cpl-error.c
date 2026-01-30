

// struct for all errors.
typedef struct {
    int error;
    const char *text;
} CPL_ERROR;

const char *get_cpl_error(int err);

void cpl_error_end(int err, int line, const char *subst);

const char *UNK_ERROR = "Unknown error.";

CPL_ERROR cpl_errors[] = {
        {1,    "An error was encountered while attempting to read the source text of the procedure."},
        {2,    "The token %s was found where the keyword &THEN was expected. All &IF directives must contain a &THEN clause."},
        {3,    "The keyword \"&THEN\" may only be used in the \"&IF\" directive."},
        {4,    "The \"&ELSE\" directive may only be used as the directive immediately following an \"&IF\" directive."},
        {5,    "The value %s is not a number, but is used where a number is expected."},
        {6,    "This \"&END\" directive could not be matched with a corresponding \"&DO\", \"&DATA\", or \"&SELECT\" directive."},
        {7,    "Internal CPL error: the value of the loop control variable %s for this iterative \"&DO\" loop could not be retrieved. Please contact your system administrator ."},
        {8,    "The value %s is not Boolean (true/false), but is used where a Boolean value was expected."},
        {9,    "The value %s is not a legal variable name, but is used where one is expected."},
        {10,   "The value %s is not a valid statement label, or else a &GOTO directive has been used to transfer control to this routine."},
        {11,   "A syntax error was found in this &ARGS directive."},
        {13,   "Internal CPL error: the semantic stack has been overpopped. Please contact your system administrator."},
        {14,   "The value of the &WHILE expression %s in this &DO loop is not Boolean (true/false) as expected."},
        {15,   "An unexpected problem was encountered while attempting to access the value of the variable %s in this statement. Possible internal CPL error; please contact your system administrator."},
        {16,   "A syntax error was found in a command function reference in this statement."},
        {17,   "Internal CPL error: an unexpected error occurred while attempting to set the value of variable %s in this statement. Please contact your system administrator."},
        {18,   "The numeric value %s used in this directive exceeds the value range limits of that directive."},
        {19,   "The token %s was found where the keyword \"&ROUTINE\" was expected."},
        {20,   "The procedure has referenced the global variable %s, but global variables have not been enabled in this process ."},
        {21,   "An unexpected error occurred while attempting to set or get the value of the global variable %s. Check the global variables file for possible damage, accidental deletion, or lack of Write access."},
        {22,   "The token %s is unrecognized or appears in this iterative \"&DO\" directive in an unexpected place. This directive contains one or more illegal, duplicate, or out-of-order clauses."},
        {23,   "The value %s is not a valid routine name, or is a statement label used where a routine name was expected. A label may not be used as a condition, severity, or check routine."},
        {24,   "Flow of control has dropped into the routine %s. Control may be transferred to a routine only by means of a condition, severity, or check routine invocation."},
        {25,   "The CPL expression %s contains a non-numeric value where a numeric value was required, or an illegal combination of operators and/or values."},
        {26,   "This directive ends before the appearance of one or more required clauses."},
        {27,   "The text %s follows the logical end of this statement."},
        {28,   "The token %s was found where one of the keywords &ERROR, &WARNING, &ROUTINE, &FAIL, or &IGNORE was expected."},
        {29,   "The value of the check expression of the currently enabled check routine is %s, which is not Boolean (true/false) as expected."},
        {30,   "The token %s was found where the keyword \":=\" was expected."},
        {31,   "The &DATA directive may not be nested."},
        {32,   "An unexpected error was encountered while operating on the temporary file containing the data from this &DATA block. Check for insufficient access rights, disk full or offline, or the use of \"CLOSE ALL\" in the procedure."},
        {33,   "Unable to create or open a temporary file with which to process this &DATA block. Check for insufficient access on the current directory."},
        {34,   "A Primos command statement is required as an argument to the &DATA directive."},
        {35,   "The Primos command invoked by this &DATA block has read all supplied input data and is requesting more. To suppress this message and continue execution using terminal input, use the &TTY directive."},
        {37,   "The token %s was found where the keyword \"&MESSAGE\" was expected."},
        {38,   "An illegal option keyword has been found in this &DEBUG directive."},
        {39,   "Insufficient storage was available to complete processing of this statement. Reduce the depth of nesting of the CPL program, or the length and/or number of local variables ."},
        {40,   "A reference to the undefined variable %s has been found in this statement."},
        {41,   "The text following %s in this statement contains a syntax error in a variable reference ."},
        {42,   "The end of the CPL procedure file was reached before the logical end of the procedure. One or more &DO, &SELECT, or &DATA directives does not have a matching &END statement."},
        {43,   "The initial-value, &TO or &BY expression in this numeric \"&DO\" directive has a non-numeric value."},
        {44,   "Local command variables are not available at command level."},
        {45,   "This line contains a command function reference, but the command function was not successfully invoked."},
        {46,   "The token %s was found where either &WHEN or &OTHERWISE was expected."},
        {47,   "The keyword \"&WHEN\" may only be used in the \"&SELECT\" directive."},
        {48,   "The keyword \"&OTHERWISE\" may only be used as the directive immediately following the last \"&WHEN\" of a \"&SELECT\" directive."},
        {49,   "This command may only be invoked as a command function ."},
        {50,   "The token %s was found in the options field of this \"&SIGNAL\" directive. The only option supported is \"&NO_RETURN\"."},
        {51,   "The token %s has been found in the options field of this \"&EXPAND\" directive. The only options supported are \"ON\" and \"OFF\"."},
        {52,   "%s is not a directive recognized by CPL."},
        {53,   "Abbreviation expansion is enabled for this statement, but the expansion could not be successfully performed."},
        {54,   "Too many variables have been placed on the watchlist."},
        {55,   "The &RESULT directive may only be executed in a CPL program invoked as a command function."},
        {56,   "The label or routine name %s could not be found in this CPL procedure. It was used as the target of a &GOTO, &CALL, or &ROUTINE directive elsewhere in the procedure."},
        {1001, "A null argument (two successive semicolons) was found in this &ARGS directive."},
        {1002, "This &ARGS directive contains a syntax error which most likely is an invalid or missing delimiter character."},
        {1003, "An illegal option argument name (keyword) has been found in this &ARGS directive."},
        {1004, "Repeat counts (indicated by *) are not presently implemented in the &ARGS directive."},
        {1005, "An unrecognized data type name has been found in this &ARGS directive."},
        {1006, "Internal CPL error: a bad state was encountered during parse of this &ARGS directive. Please contact your system administrator."},
        {1007, "A word or token in this &ARGS directive exceeds the implementation maximum limit of 1024 characters."},
        {1008, "In this &ARGS directive, an object argument specifier appears to the right of one or more option argument (keyword) specifiers. All object arguments must appear to the left of the first option argument."},
        {1014, "The default value specified for an argument in this &ARGS directive is not the correct data type."},
        {1015, "In this &ARGS directive, a default value has been specified for a data type for which default values are not supported."},
        {1017, "In this &ARGS directive, a default value expression contains an undefined variable reference, or a syntax error in a variable reference."},
        {1018, "In this &ARGS directive, the data type UNCL has been specified more than once or for an option (keyword) argument. The UNCL data type may be used only for a single object argument."},
        {1019, "This &ARGS directive contains a global variable name (a name starting with \".\"). Only local variable names may appear in an &ARGS directive."},
        {1020, "This &ARGS directive contains an illegal variable name."},
        {1021, "The &ARGS directive does not accept numeric option arguments. Option arguments must contain at least one alphabetic character."}
};

#define NUM_ERRORS sizeof(cpl_errors)/sizeof(cpl_errors[0])

// get the error string from the struct.
const char *get_cpl_error(int err) {
    for (int x = 0; x < NUM_ERRORS; x++)
        if (cpl_errors[x].error == err)
            return cpl_errors[x].text;
    return UNK_ERROR;
}

// given the error code, line number, and substitution, print a formatted error.
void cpl_error_end(int err, int line, const char *subst) {
    fprintf(stderr, "CPL ERROR %d", err);
    if (line > 0)
        fprintf(stderr, " ON LINE %d", line);
    fprintf(stderr, ".\n");
    const char *estr = get_cpl_error(err);
    // get lengths and get temp storage.
    size_t length = strlen(estr) + (subst ? strlen(subst) : 0) + 1;
    char *s = malloc(length);
    // might have an %s in the error string
    snprintf(s, length, estr, subst);
    fprintf(stderr, "%s\n", s);
    free(s);
    cpl_shut_it_down();
    exit(1);
}

#ifndef CPL_MAIN

int main (void) {
    return 0;
}

#endif