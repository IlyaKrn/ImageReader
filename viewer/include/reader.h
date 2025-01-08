#pragma once
#include <stdio.h>

int open(char* file_path, FILE** file_ptr);
int close(FILE* file_ptr);
int length(FILE* file_ptr, long* length);
int read(FILE* file_ptr, int offset, int length, unsigned char* buffer);
