#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        exit(1);
    } else if (rc == 0) { // child
        printf("child\n");
    } else { // parent
        wait(NULL);
        printf("parent\n");
    }
    return 0;
}

// Can both the child and parent access the file descriptor returned by open()?
// Yes
//  What happens when they are writing to the file concurrently, i.e., at the same time?
//  both are writting to the file
