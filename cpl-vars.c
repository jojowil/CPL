#include <stddef.h>
#include <stdlib.h>

typedef enum {
    INT
} vartype;

typedef struct variable {
    char name[32];
    vartype type;
    char *val;
    variable *next;
} variable_node;


#include "cpl-vars.h"
