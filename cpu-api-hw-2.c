#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int file_desciptor = open("./output/cpu-api-hw-2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        exit(1);
    } else if (rc == 0) { // child
        /* printf("in child %d\n", file_desciptor); */
        write(file_desciptor, "child\n", 6);
    } else { // parent
        /* printf("in parent %d\n", file_desciptor); */
        write(file_desciptor, "parent\n", 7);
    }
    return 0;
}

// Can both the child and parent access the file descriptor returned by open()?
// Yes
//  What happens when they are writing to the file concurrently, i.e., at the same time?
//  both are writting to the file
