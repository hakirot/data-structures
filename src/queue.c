/* FIFO - First In First Out
 *
 * Enqueue aka Push()
 * Dequeue aka Pop()
 * Front aka Peek()
 * IsEmpty()
 *
 * All operations of a circular linked list run in constant time
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int A[MAX_SIZE];

int rear = -1;
int front = -1;

void Enqueue(int x);
int Dequeue();
int Front();
void Print();
int IsEmpty();
int IsFull();

int main(int argc, char * argv[]){

    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Dequeue();
    Enqueue(4);

    Print();

    return 0;
}


void Enqueue(int x){

    if(IsFull()) {
        return;

    } else if (IsEmpty()){
        front = rear = 0;

    } else {
        rear = (rear + 1) % MAX_SIZE;
    }

    A[rear] = x;
}

int Dequeue(){

    if(IsEmpty()){
        printf("Error, queue is empty!\n");
        return 0;

    } else if (front == rear) {

        front = rear = -1;

    } else {
        front = (front + 1) % MAX_SIZE;
    }

}

int Front(){
    return A[front];
}

int IsEmpty(){
    if(front == -1 && rear == -1) return 1;
    return 0;
}

int IsFull(){
    if ((rear + 1) % MAX_SIZE == front) return 1;
    return 0;
}

void Print(){
    printf("Queue: ");
    for(int i = front; i <= rear; i++){
        printf(" %d", A[i]);
    }
        printf("\n");
}
