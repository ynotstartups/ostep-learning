#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x = 1, y = 2, z[10];
    int *p;
    printf("address of variable p: %p\n", &p);

    p = &x;

    printf("value of variable pointed by p: %d\n",  *p);
    printf("address of pointed by p: %p\n",  p);
    printf("address of variable x: %p\n",  &x);

    y = *p;
    printf("value of variable y: %d\n",  y);

    y = 3;
    printf("value of variable y: %d\n",  y);
    printf("value of variable x: %d\n",  x); // x is still 1 not changed

    *p = 0;
    printf("value of variable x: %d\n",  x); // x is changed to 0

    p = &z[0] // p now points to z[0]

    return 0;
}
