#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child pid \t%d\n", getpid());
        int rc_wait = wait(NULL);
        printf("waiting return \t%d\n", rc_wait);
        // What happens if you use wait() in the child?
        // error returns -1, because on child process?

    } else {
        printf("parent pid \t%d\n", getpid());
        // What does wait() return? What happens if you use wait() in the child?
        // the wait returns the child process id
    }
    return 0;
}
