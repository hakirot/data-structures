
#include <stdio.h>
#include <stdlib.h> 

typedef struct Node Node;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* GetNewNode(int data);
Node* InsertAtHead(Node* head, int data);
void InsertAtTail(Node* head, int data);
void Print(Node* head);
void ReversePrint(Node* tail);

int main(int argc, char * argv[]){

    if(argc < 2){
        printf("Usage: %s [numNodes]\n" , argv[0]);
        exit(1);
    } else {
        printf("%d, %d\n", argc, atoi(argv[1]));
    }

    //int numNodes = 10;
    int numNodes = atoi(argv[1]);

    Node* head = NULL;

    head = InsertAtHead(head, 3);
    head = InsertAtHead(head, 2);
    head = InsertAtHead(head, 1);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);

    printf("List:");
    Print(head);
    printf("Reverse List:");
    ReversePrint(head);

    return 0;
}

Node* GetNewNode(int data){

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    return newNode;
}

Node* InsertAtHead(Node* head, int data){

    Node* newNode = GetNewNode(data);

    newNode->next = head;
    if(head != NULL) head->prev = newNode;
    return newNode;
}

void InsertAtTail(Node* head, int data){

    Node* newNode = GetNewNode(data);

    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void Print(Node* head){

    Node * temp = head;

    while(temp != NULL){
        printf(" %d", temp->data);
        temp=temp->next;
    }

    printf("\n");
}

void ReversePrint(Node* head){

    Node * temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}
