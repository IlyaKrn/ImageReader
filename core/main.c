#include "include/file_core.h"

int main(int argc, char** argv){

    FILE* f = NULL;
    printf("%s\n", argv[1]);
    printf("o%d\n", open(argv[1], &f));
    unsigned char buff[4] = {10, 10, 10, 10};
    printf("w%d\n", write(f, 4, 4, buff, WRITE_APPEND));

//    unsigned int c = 0x99999999;
//    for(int i = 0; i < 1024*1024*256; i++){
//        fwrite(&c, 4, 1, f);
//    }
    close(f);

}
