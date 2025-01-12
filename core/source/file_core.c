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
            int b = 1024*1024;
            fseek(file_ptr, 0, SEEK_END);
            long len = ftell(file_ptr);
            long pos = len;
            while (pos > offset){
                long read_size = pos - b > offset ?  b : pos - offset;
                pos -= read_size;
                unsigned char* bytes = malloc(sizeof (unsigned char) * read_size);
                fseek(file_ptr, pos, SEEK_SET);
                if(fread(bytes, sizeof(unsigned char), read_size, file_ptr) != read_size) return 2;
                fseek(file_ptr, pos + length, SEEK_SET);
                if(fwrite(bytes, sizeof(unsigned char), read_size, file_ptr) != read_size) return 2;
                free(bytes);
            }
            fseek(file_ptr, offset, SEEK_SET);
            return fwrite(buffer, sizeof(unsigned char), length, file_ptr) == length ? 0 : 2;
            break;
        default:
            return 3;
    }
}
