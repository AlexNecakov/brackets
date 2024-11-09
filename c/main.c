#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int decided;
    char name[256];
    struct node *parent;
    struct node *child_left;
    struct node *child_right;
} node;

node *createNode(node *parent) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->decided = 0;
    newNode->parent = parent;
    return newNode;
}

void setName(node *n, char *name) { memcpy(n->name, name, strlen(name) + 1); }

int main(int argc, char *argv[]) {
    int numEntries = argc - 1;
    if (numEntries <= 0) {
        printf("no entries provided\n");
        return 1;
    }
    // number of leaves = argc - 1
    // numRounds = logb2numplayers (round up)
    // create 2posnumplayers round up nodes, resolve empty slots
    // continue resolving until parent node is null or current = root again

    node *root = createNode(NULL);
    node *current = root;
    // setName(root, argv[1]);
    printf("num leaves = %d\nnum rounds = %d", numEntries, (int)ceil(log2(numEntries)));

    for (int i = 0; i < argc; i++) {
    }
    return 0;
}
