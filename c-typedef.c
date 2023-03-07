#include <stdio.h>
#include <stdlib.h>

typedef long long lltest;

typedef struct __node_t {
    int size;
    struct __node_t *next;

} node_t;

struct node_t_new {
    int size;
    struct node_t_new *next;
};

int main(int argc, char *argv[]) {
    lltest var = 20;
    printf("%lld\n", var);

    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(long int));

    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));

    node_t test_node = {10, NULL};
    printf("test_node size %d\n", test_node.size);
    test_node.size = 15;
    printf("test_node size %d\n", test_node.size);


    struct node_t_new node_t_new_var = {20, NULL};
    printf("node_t_new size %d\n", node_t_new_var.size);




    return 0;
}
