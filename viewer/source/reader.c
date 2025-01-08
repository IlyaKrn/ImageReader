#include "../include/reader.h"

int open(char *file_path, FILE **file_ptr) {
    *file_ptr = fopen(file_path, "r");
    if (!*file_ptr)
        return 1;
    return 0;
}

int close(FILE *file_ptr) {
    if (!file_ptr)
        return 1;
    fclose(file_ptr);
    return 0;
}

int length(FILE *file_ptr, long *length) {
    if (!file_ptr)
        return 1;
    fseek(file_ptr, 0, SEEK_END);
    *length = ftell(file_ptr);
    return 0;
}

int read(FILE *file_ptr, int offset, int length, unsigned char *buffer) {
    if (!file_ptr)
        return 1;
    fseek(file_ptr, offset, SEEK_SET);
    return fread(buffer, sizeof(unsigned char ), length, file_ptr) == length;
}
