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
        close(STDOUT_FILENO);
        open("./output/cpu-api-hw-4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

        /* char *myargs[2]; */
        /* myargs[0] = "/usr/bin/ls"; */
        /* myargs[1] = NULL; */
        /* execv(myargs[0], myargs); */

        execle("/usr/bin/ls", "/usr/bin/ls", "-l", NULL);
    } else {
        int rc_wait = wait(NULL);
    }
    return 0;
}
