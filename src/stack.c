// LIFO data structure with push(), pop(), top(), isEmpty()
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int data;
    Node* next;
};

void Print(Node* head);
Node* GetNewNode(int data);
Node* Push(Node* head, int data);
Node* Pop(Node* head, int* value);
int Top(Node* head);
int isEmpty(Node* head); // 0 for false and 1 for true


int main(int argc, char * argv[]){

    Node* stack = NULL;

    stack = Push(stack, 1);
    stack = Push(stack, 2);
    stack = Push(stack, 3);
    stack = Push(stack, 4);
    stack = Push(stack, 5);

    printf("Init after push: ");
    Print(stack);

    int a = 0;
    stack = Pop(stack, &a);
    stack = Pop(stack, &a);

    printf("Stack after two pops: ");
    Print(stack);

    printf("Value of most recent pop: %d\n", a);
    printf("Value of current top: %d\n", Top(stack));

    printf("Is the stack empty?");
    if(isEmpty(stack)){
        printf("\nyes\n");
    } else {
        printf("\nno\n");
    }

    stack = Pop(stack, &a);
    stack = Pop(stack, &a);
    stack = Pop(stack, &a);

    printf("How about after 3 more pops?");
    if(isEmpty(stack)){
        printf("\nyes\n");
    } else {
        printf("\nno\n");
    }

    printf("Value of most recent pop: %d\n", a);

    return 0;
}

Node* GetNewNode(int data){

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void Print(Node* head){

    Node * temp = head;

    while(temp != NULL){
        printf(" %d", temp->data);
        temp=temp->next;
    }

    printf("\n");
}

Node* Push(Node* head, int data){

    Node* newNode = GetNewNode(data);
    newNode->next = head;

    return newNode;
}

Node* Pop(Node* head, int* value){

    if(head == NULL) return NULL;

    *value = head->data;

    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

int Top(Node* head){
    return head->data;
}

int isEmpty(Node* head){

    if(head == NULL) return 1;
    return 0;
}
