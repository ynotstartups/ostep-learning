#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int x;
    x = 100;

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("in child %d\n", x);
        x = 300;
        printf("in child %d\n", x);
    } else {
        wait(NULL);
        printf("in parent %d\n", x);
        x = 200;
        printf("in parent %d\n", x);
    }
    return 0;
}

/* What happens to the variable when both the child and parent change */
/* the value of x? */
/* they both changes*/

