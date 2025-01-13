//
// Created by Bill Jojo on 1/12/25.
//

#include "cpl-include.h"

int main(int argc, char** argv) {

    char* file;
    if (argc != 2)
        cpl_usage();
    file = cpl_readAllBytes(argv[1]);

    if (file == NULL) {
        fprintf(stderr, "Unable to continue...\n");
        exit(1);
    }
}