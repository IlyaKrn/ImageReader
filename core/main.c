#include "include/file_core.h"

int main(int argc, char** argv){

    FILE* f = NULL;
    printf("%s\n", argv[1]);
    printf("o%d\n", open(argv[1], &f));
    unsigned char buff[4] = {11, 11, 11, 11};
    printf("w%d\n", write(f, 4, 4, buff, WRITE_APPEND));


}
