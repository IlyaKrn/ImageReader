#include <malloc.h>
#include "include/reader.h"

int main(int argc, char** argv){

    FILE* f = NULL;
    printf("%s\n", argv[1]);
    printf("o%d\n", open(argv[1], &f));
    long s;
    printf("l%d\n", length(f, &s));
    unsigned char buff[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    printf("r%d\n", read(f, 3, 10, buff));
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", buff[i]);
    }


}
