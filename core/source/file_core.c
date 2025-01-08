#include <malloc.h>
#include "../include/file_core.h"

int open(char *file_path, FILE **file_ptr) {
    *file_ptr = fopen(file_path, "r+");
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
    return fread(buffer, sizeof(unsigned char ), length, file_ptr) == length ? 0 : 2;
}

int write(FILE *file_ptr, int offset, int length, unsigned char *buffer, int write_flag) {
    if (!file_ptr)
        return 1;
    switch(write_flag){
        case WRITE_OVERRIDE:
            fseek(file_ptr, offset, SEEK_SET);
            return fwrite(buffer, sizeof(unsigned char), length, file_ptr) == length ? 0 : 2;
            break;
        case WRITE_APPEND:
            fseek(file_ptr, 0, SEEK_END);
            long override = ftell(file_ptr);
            while (override >= offset){
                long l = override - offset > 1024*1024 ? 1024*1024 : override - offset;
                unsigned char* bytes = malloc(sizeof (unsigned char) * l);
                fseek(file_ptr, override - l, SEEK_SET);
                fread(bytes, sizeof(unsigned char), l, file_ptr);
                fseek(file_ptr, override + offset, SEEK_SET);
                fwrite(bytes, sizeof(unsigned char), l, file_ptr);
                override -= 1024*1024;
                free(bytes);
            }
            fseek(file_ptr, offset, SEEK_SET);
            return fwrite(buffer, sizeof(unsigned char), length, file_ptr) == length ? 0 : 2;
            break;
        default:
            return 3;
    }
}
