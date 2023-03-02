#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc0 = fork();
    int rc1 = fork();
    if (rc0 < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc0 == 0) {
        printf("child first pid \t%d\n", getpid());
    } else if (rc1 == 0) {
        printf("child second pid \t%d\n", getpid());
    } else {
        printf("parent pid \t%d\n", getpid());
        int rc0_wait = waitpid(rc1, NULL, 0);
        printf("waiting for %d return \t%d\n", rc0, rc0_wait);
        // waitpid will be useful to wait for a specific child?
    }
    return 0;
}
