//
// Created by Bill Jojo on 1/12/25.
//

#include "cpl-include.h"

/**
 * reads all bytes from a given filename
 * @param fname string filename
 * @return pointer to bytes or NULL
 */
char *cpl_readAllBytes(const char *fname) {
    FILE *file;
    long fileSize;
    char *buffer;
    size_t bytesRead;

    // open file
    file = fopen(fname, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // get size
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    // get the mem
    buffer = (char *) malloc(fileSize * sizeof(char) + 1);

    // Read the entire file into the buffer
    bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Error reading file");
        fclose(file);
        free(buffer);
        return NULL;
    }
    // add the terminator
    buffer[fileSize] = '\0';
    return buffer;
}

/**
 * Simple usage message.
 */
void cpl_usage() {
    printf("Usage:\tcpl filename.cpl\n");
    exit(255);
}