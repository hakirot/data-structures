
/* Infix   <operand><operator><operand>
 *
 *   4 + 6 * 2 = x
 *   Solve multiplication first, then addition
 *   
 * Prefix  <operand><operator><operand>
 *
 *   2 + 3 will instead be written as + 2 3
 *   p - q would be - p q
 *   a + b * c would then become + a * b c
 *
 * Postfix <operand><operand><operator>
 *
 *   This method is easiest programmatically and easiest on resources
 *
 *   2 + 3 would be 2 3 +
 *   p - q would be pq-
 *   a + b * c is then abc*+
 */

/* EvaluatePostfix(expression)
 *  Create a stack S
 *  for i <-- 0 to length(exp) - 1
 *    if(exp[i] is operand)
 *      push(exp[i])
 *    else if(exp[i] is operator)
 *      OP2 <-- Pop()
 *      OP1 <-- Pop()
 *      res <-- Perform(exp[i], OP1, OP2)
 *      push(res)
 *  return top()
 */

/* InfixToPostfix(expression)
 * Create stack S
 * res <--- empty result string
 * for i <-- 0 to length(exp) - 1
 *   if exp[i] is operand
 *     res <-- res + exp[i]
 *   else if exp[i] is operator{
 *     while (!S.empty() && HasHigherPrecidence(S.top(), exp[i])){
 *       res <-- res + s.Top()
 *       S.Pop()
 *     }
 *     S.Push(exp[i])
 *   }
 * while(!S.empty()){
 *   res <-- res + S.top()
 *   S.Pop()
 * }
 * return res
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int x){

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

    for(int i = 0; i <= top; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

}

int main(int argc, char * argv[]){

    char * expression = "8 + 4 * (4 - 2) / 2";

    const char letter = 5 + '0';
    printf("%c", letter);

    return 0;
}
