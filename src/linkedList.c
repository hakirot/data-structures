/*
 * Cannot access the array in constant time, instead O(n). Elements are not contiguous im memory.
 * Insert: O(1) - Create a new head and adjust the head pointer and next variable to old head
 * Insert at end: O(n) - Must traverse the list
 * Remove: O(n)
 *
 */

#include <stdio.h>
#include <stdlib.h> 

typedef struct Node Node;
Node * head;
void Insert(int x);
void Print();

struct Node
{
    int data;
    Node * next;
};

int main(int argc, char * argv[]){

    if(argc < 2){
        printf("Usage: %s [numNodes]\n" , argv[0]);
        exit(1);
    } else {
        printf("%d, %d\n", argc, atoi(argv[1]));
    }

    int numNodes = atoi(argv[1]);

    // in C++ 'new' keyword is recommended
    //Node * list = (Node*)malloc(sizeof(Node));

    for(int i = 0; i < numNodes; i++){
        Insert(i);
    }

    Print();

    return 0;
}

void Insert(int x){

    Node * temp = (Node *)malloc(sizeof(Node));

    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print(){

    Node * temp = head;

    while(temp != NULL){
        printf(" %d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
