/*
 * Cannot access the arary in constant time, instead O(n)
 *
 *
 *
 */

#include <stdio.h>

typedef struct Node Node;

struct Node
{
    int data;
    struct Node * next;
};

int main(){

    Node nodey;
    nodey.data = 10;

    return 0;
}
