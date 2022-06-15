/* All operations here take constant time
 */

#include <stdio.h>
#include <stdlib.h> 

typedef struct Node Node;

Node* front = NULL;
Node* rear = NULL;

struct Node
{
    int data;
    Node* next;
};

void Enqueue(int x);
void Dequeue();
void Print();
int Front();
Node* GetNewNode(int data);

int main(int argc, char * argv[]){

    Node* queue;
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Dequeue();
    Dequeue();
    Enqueue(4);
    Enqueue(5);

    Print();
    return 0;
}

Node* GetNewNode(int data){

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void Enqueue(int x){

    Node* temp = GetNewNode(x);

    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void Dequeue(){

    Node* temp = front;

    if(front == NULL) return;
    if(front == rear){

        front = rear = NULL;

    } else {
        front = front->next;
    }

    free(temp);
}

void Print(){

    Node* temp = front;
    printf("\nQueue: ");

    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int Front(){
    return front->data;
}
