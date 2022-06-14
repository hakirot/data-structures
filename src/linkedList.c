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

struct Node
{
    int data;
    Node* next;
};

Node* Insert(Node* head, int x);
Node* InsertAt(int position, int data, Node* head);
Node* DeleteAt(int position, Node* head);
Node* Reverse(Node* head);
void Print(Node* head);
void RecursivePrint(Node* head);
Node* RecursiveReverse(Node* node);

int main(int argc, char * argv[]){

    if(argc < 2){
        printf("Usage: %s [numNodes]\n" , argv[0]);
        exit(1);
    } else {
        printf("%d, %d\n", argc, atoi(argv[1]));
    }

    //int numNodes = 10;
    int numNodes = atoi(argv[1]);

    Node * head = NULL;

    for(int i = 0; i < numNodes; i++){
        head = Insert(head, i);
    }

    printf("Init:\n");
    Print(head);

    head = InsertAt(1, 100, head);
    head = InsertAt(5, 50, head);
    head = InsertAt(12, 20, head);

    printf("After inserts:\n");
    Print(head);

    head = DeleteAt(10, head);
    head = DeleteAt(3, head);
    head = DeleteAt(7, head);
    head = DeleteAt(1, head);

    printf("After deletes:\n");
    Print(head);

    head = Reverse(head);

    printf("After reversal:\n");
    Print(head);

    printf("Recursive print:\n");
    RecursivePrint(head);

    printf("\nRecursive reverse:\n");
    head = RecursiveReverse(head);
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

Node* InsertAt(int position, int data, Node* head){

    Node* temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if(position == 1){
        temp->next = head;
        head = temp;
        return head;
    } 

    Node * temp2 = head;

    for(int i = 0; i <= position-2; i++ ){
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;

    return head;
}

Node* DeleteAt(int position, Node* head){

    Node* temp = head;

    if(position == 1){
        head = temp->next;
        free(temp);
        return head;
    }

    for(int i = 0; i < position-2; i++ ){
        temp = temp->next;
    }

    Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2); // In c++: delete temp2;

    return head;
}

Node* Reverse(Node* head){

    if(head == NULL) return NULL;

    Node* temp = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (temp != NULL){

        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    head = prev;
    return head;
}

// Not as efficient as iterative print, due to using a lot of memory on the stack
void RecursivePrint(Node* p){

    if(p == NULL) return;

    RecursivePrint(p->next);
    printf(" %d", p->data);
}

Node* RecursiveReverse(Node* node){

    Node* head = NULL;

    // Go deep, find the NULL, make head and return up the call stack
    if(node->next == NULL){
        head = node;
        return head;
    }

    head = RecursiveReverse(node->next);

    Node* q = node->next;
    q->next = node;
    node->next = NULL;

    return head;
}
