// All operations on stack take constant time. Reversal function takes O(n)
// Space complexity is O(n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

char A[MAX_SIZE];
int top = -1;

void Push(char x){

    if(top == MAX_SIZE-1){
        printf("Error: Stack overflow\n");
        return;
    }

    A[++top] = x;
}

void Pop(){

    if(top == -1){
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}

int Top(){
    return A[top];
}

void Print(){

    printf("Stack: ");

    for(int i = top; i >= 0; i--){
        printf("%c", A[i]);
    }

    printf("\n");
}


int main(int argc, char * argv[]){

    char str[100];
    memset(str, '\0', sizeof(char));

    strcpy(str, "It\'s raining.\n");

    for(int i = 0; i < strlen(str); i++){
        Push(str[i]);
    }

    Print();

    return 0;
}
