#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int *x = malloc(10 * sizeof(int));

    printf("print as pointer %p\n", x);
    printf("same as 0x%lx\n", x);

    printf("%ld\n", sizeof(x));

    *x = -22;
    printf("%d\n", *x);

    *(x + 1) = -23;
    printf("%d\n", *(x+1));

    int y[10];
    printf("%ld\n", sizeof(y));
    printf("print as pointer %p\n", y);

    y[0] = -2;
    printf("%d\n", y[0]);
    // Forgetting To Allocate Memory

    char *src = "hello world";
    char *dst = malloc(strlen(src) + 1);
    strcpy(dst, src);

    printf("%s\n", dst);

    char *src_1 = "hello world";
    char *dst_1;
    dst_1 = strdup(src_1);

    printf("~~~ %s\n", dst_1);

    char *src_2 = "hello world";
    printf("~~~~ %p\n", src_2);
    printf("~~~~ %s\n", src_2);

    return 0;
}
