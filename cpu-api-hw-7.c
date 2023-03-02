#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc0 = fork();
    if (rc0 < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc0 == 0) {
        close(STDOUT_FILENO);
        printf("child first pid \t%d\n", getpid());
        // What happens if the child calls printf() to print some output after closing the descriptor?
        // nothing gets print out in the child, but the parent can still print after the wait so the file descriptor is not closed for parent!
    } else {
        printf("parent pid \t%d\n", getpid());
        int rc0_wait = wait(NULL);
        printf("waiting return \t%d\n", rc0_wait);
    }
    return 0;
}
