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
    newNode->child_left = NULL;
    newNode->child_right = NULL;
    return newNode;
}

void setName(node *n, char *name) { memcpy(n->name, name, strlen(name) + 1); }

int main(int argc, char *argv[]) {
    int numEntries = argc - 1;
    if (numEntries <= 0) {
        printf("no entries provided\n");
        return 1;
    }
    int numRounds = (int)ceil(log2(numEntries));
    int numLeaves = (int)ceil(pow(2, numRounds));

    node *root = createNode(NULL);
    node *current = root;

    int currLeaves = 0;
    int currDepth = 0;
    // make the btree
    while (currLeaves < numLeaves) {
        // leaf
        if (currDepth == numRounds) {
            if (currLeaves < numEntries) {
                setName(current, argv[1 + currLeaves]);
                printf("set leaf %i name to %s\n", currLeaves, current->name);
            }
            currLeaves++;
            current->decided = 1;
            current = current->parent;
            currDepth--;
        }
        // too deep
        else if (currDepth > numRounds) {
            printf("delved too deep. crashing\n");
            return 1;
        } else if (currDepth < 0) {
            printf("flew too close to the sun. crashing\n");
            return 1;
        }
        // non leaf
        else {
            if (current->child_left == NULL) {
                node *newNode = createNode(current);
                current->child_left = newNode;
                current = newNode;
                currDepth++;
            } else if (current->child_right == NULL) {
                node *newNode = createNode(current);
                current->child_right = newNode;
                current = newNode;
                currDepth++;
            } else {
                current = current->parent;
                currDepth--;
            }
        }
    }

    // sorting loop
    current = root;
    while (!root->decided) {
        if (!current->child_left->decided) {
            current = current->child_left;
        } else if (!current->child_right->decided) {
            current = current->child_right;
        } else {
            printf("A %s vs B %s\n", current->child_left->name, current->child_right->name);
            char choice = 0;
            while (choice != 'a' && choice != 'b' && choice != 'j' && choice != 'k') {
                choice = getchar();
            }
            if (choice == 'a' || choice == 'j') {
                setName(current, current->child_left->name);
            } else if (choice == 'b' || choice == 'k') {
                setName(current, current->child_right->name);
            }
            current->decided = 1;
            printf("round winner: %s\n", current->name);
            current = current->parent;
        }
    }

    // printing loop
    printf("grand winner %s\n", root->name);

    return 0;
}
