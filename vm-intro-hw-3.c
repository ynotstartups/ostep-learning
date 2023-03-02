#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // this program take one commandline argument
    // the number of megabytes of memory it will use

    if (argc != 3) {
        printf("Please provide the number of megabytes of memory\n"
                "and number seconds this program runs for\n");
        return -1;
    }

    printf("process id is %d \n", getpid());

    int number_of_megabytes = atoi(argv[1]);
    int number_of_second = atoi(argv[2]);

    printf("malloc %d megabytes \n", number_of_megabytes);

    unsigned int array_length = 1024 * 1024 * number_of_megabytes / sizeof(int);

    printf("array_length %u \n", array_length);

    int *array; // integer array
    array = malloc(array_length * sizeof(int));

    time_t start, end;
    time(&start);
    do {
        time(&end);
        /* printf("time %ld\n", end); */
        /* printf("difftime %f\n", difftime(end, start)); */
        for (int i = 0; i < array_length; i++)
            array[i] = i;
    }
    while (difftime(end, start) <= number_of_second);

    assert(array != NULL);

    return 0;
}
