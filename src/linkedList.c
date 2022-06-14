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
Node* Insert(Node* head, int x);
void Print(Node* head);

struct Node
{
    int data;
    Node* next;
};

int main(int argc, char * argv[]){

    if(argc < 2){
        printf("Usage: %s [numNodes]\n" , argv[0]);
        exit(1);
    } else {
        printf("%d, %d\n", argc, atoi(argv[1]));
    }

    int numNodes = atoi(argv[1]);

    Node * head = NULL;

    for(int i = 0; i < numNodes; i++){
        head = Insert(head, i);
    }

    Print(head);

    return 0;
}

Node* Insert(Node * head, int x){

    Node * temp = (Node *)malloc(sizeof(Node));

    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

void Print(Node* head){

    Node * temp = head;

    while(temp != NULL){
        printf(" %d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
