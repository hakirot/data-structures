/*
 * A dynamic list (array)
 *
 *  Access: O(1) - We know an array is a contiguous block of memory, so A[i] = &A + sizeof(i)
 *  Insert O(n) - Needed to shift the list
 *  Remove O(n)
 *  Add O(n)
 *  Resize O(n)
 *
 *  Notes: 
 *      Not great at utlizing memory if there are unused spots in an array, a better list ADT
 *      for space usage would be a linked list
 */

#include <stdio.h>

int main(){

    int array[10];

    return 0;
}
