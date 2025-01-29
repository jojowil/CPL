#include "cpl-include.h"

int main(int argc, char **argv) {

    char *file;

    if (argc != 2)
        cpl_usage();
    file = cpl_readallbytes(argv[1]);

    if (file == NULL)
        cpl_error_end(1, 0, NULL);

    cpl_run(file);
}