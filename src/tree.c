/* Define tree: A collection of entites, called nodes, linked together to simulate a heirarchy
 *   Nodes have children, each arrow in a tree is a link from parent to child node
 *   Nodes on the same level as others are sibling nodes, but they must have the same parent
 *   Nodes on the same level, not the same parent, but same grandparent, can be cousins
 *   Nodes without children are leaf nodes
 *
 *   If we can traverse the tree from A to B, then A is the ancestor of B, and B is descendant of A
 *
 *   Trees are recursive data structures. The root contains the link to all the subtrees.
 *   A tree with N nodes will have exactly N-1 edges
 *
 *   Depth of x node is length of path from root to x, or number of edges from root to x
 *
 *   Height of x node is number of edges in longest path from x to leaf
 *   Height of a tree is the height of the root node
 *
 *   Binary trees have at most two children
 *      - data
 *      - left child
 *      - right child
 *
 *   Maximum number of nodes in a BST at level i is 2^i
 *   A perfect BST that is completely filled will have  n =  2^(h+1) -1  nodes
 *   Therefor the height is  h = log2(n + 1) - 1  edges
 *
 *   A complete binary tree has all levels except possible the last completely filled and all 
 *   nodes are as far left as possible
 *
 *   Tree examples
 *     - Network routing applications
 *     - Computer file systems
 *     - Quick searche algorithms
 *
 *   Cost of operations on a Binary Tree is proportional to to the height of the tree, we 
 *   therefore would like the tree to be as close to complete as possible, otherwise we could
 *   just essentially be following a linked list
 *   
 *   We can implement binary trees using
 *      - Dynamically created nodes
 *      - Array
 *          - For node at index i
 *              - left-child  = 2i + 1
 *              - right-child = 2i + 2
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int main(int argc, char * argv[]){

    return 0;
}
