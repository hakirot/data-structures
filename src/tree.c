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
 *   Therefore the height is  h = log2(n + 1) - 1  edges
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
 *   just essentially be following a linked list. To get the time advantages, the tree must be
 *   sorted and balanced.
 *   
 *   We can implement binary trees using
 *      - Dynamically created nodes
 *      - Array
 *          - For node at index i
 *              - left-child  = 2i + 1
 *              - right-child = 2i + 2
 *
 *   BST Array
 *      - Search O(n) - must scan list, possibly until end
 *      - Insert O(1) - random access
 *      - Remove O(n) - may have to shift n-1 elements in worst case
 *
 *  A Sorted Balanced BST will have a time of O(logn)
 *
 *              Array(unsorted)     Linked List     Array(Sorted)
 *  Search(x)   O(n)                O(n)            O(logn)
 *  Insert(x)   O(1)                O(1)            O(logn)
 *  Remove(x)   O(n)                O(n)            O(logn)
 *
 *  All binary search trees must have BST subtrees
 *      - values of all nodes in left subtrees are less than all values in right subtrees
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct BstNode BstNode;

 #define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data);
BstNode* Insert(BstNode* root, int data);
BstNode* Delete(BstNode* root, int data);
int Search(BstNode* root, int data);
int FindMin(BstNode* root);
int FindMax(BstNode* root);
int FindHeight(BstNode* root);
void BfsPrint(BstNode* root);
void DfsPrint(BstNode* root);
void PrintCurrentLevel(BstNode* root, int level);
int IsBST(BstNode* root);
int IsSubtreeLesser(BstNode* root, int data);
int IsSubtreeGreater(BstNode* root, int data);
int IsBST(BstNode* root);
int IsBSTPlus(BstNode* root);
int IsBstUtil(BstNode* root, int min, int max);
BstNode* FindMinNode(BstNode* root);

int main(int argc, char * argv[]){

    BstNode* root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 7);
    root = Insert(root, 20);
    root = Insert(root, 16);
    root = Insert(root, 3);
    root = Insert(root, 30);
    root = Insert(root, 33);
    root = Insert(root, 34);

    if(Search(root, 30)){
        printf("Data found\n");
    } else {
        printf("Data not found\n");
    }

    printf("min: %d\n", FindMin(root));
    printf("max: %d\n", FindMax(root));
    printf("height: %d\n", FindHeight(root));

    printf("BFS Print:\n");
    BfsPrint(root);

    printf("\nDFS Print:\n");
    DfsPrint(root);

    BstNode* NotBst = NULL;
    NotBst = Insert(NotBst, 15);
    NotBst = Insert(NotBst, 7);
    NotBst = Insert(NotBst, 20);
    NotBst->left->data = 20;
    NotBst->right->data = 7;

    printf("\nNot Bfs:");
    BfsPrint(NotBst);

    printf("\nIs NotBfs a BST?\n");
    if(IsBST(NotBst)) printf("yes\n");
    else printf("no\n");

    printf("Is the first tree a BST?\n");
    if(IsBST(root)) printf("yes\n");
    else printf("no\n");

    printf("Is NotBfs a BST (using better method)?\n");
    if(IsBSTPlus(NotBst)) printf("yes\n");
    else printf("no\n");

    printf("Is the first tree a BST (using better method)?\n");
    if(IsBSTPlus(root)) printf("yes\n");
    else printf("no\n");

    root = Delete(root, 20);
    root = Delete(root, 33);
    root = Delete(root, 3);

    printf("Tree after deletions\n");
    BfsPrint(root);

    printf("\n");
    return 0;
}

BstNode* GetNewNode(int data){
    BstNode* newNode = malloc(sizeof(BstNode));
    newNode->data = data;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){

    if(root == NULL){
        return GetNewNode(data);

    } else if (data <= root->data) {

        root->left = Insert(root->left, data);

    } else {

        root->right = Insert(root->right, data);
    }

    return root;
}

int Search(BstNode* root, int data){

    if(root == NULL) return 0;
    if(root->data == data) return 1;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

int FindMin(BstNode* root){
    if (root == NULL){
        printf("Error, tree is empty\n");
        return -1;
    }
    if (root->left == NULL) return root->data;
    return FindMin(root->left);
}

int FindMax(BstNode* root){
    if (root == NULL){
        printf("Error, tree is empty\n");
        return -1;
    }
    if (root->right == NULL) return root->data;
    return FindMax(root->right);
}

// O(n)
int FindHeight(BstNode* root){

    if (root == NULL){
        return -1;
    }

    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

/* Level-order
 * O(n) - must traverse to all nodes
 * Space-complexity @ worst case: O(n)
 */
void BfsPrint(BstNode* root){

    if(root == NULL) return;

    int height = FindHeight(root);

    for(int i = 1; i <= height + 1; i++){
        PrintCurrentLevel(root, i);
    }
}

void PrintCurrentLevel(BstNode* root, int level){

    if(root == NULL) return;
    if(level == 1) {
        printf(" %d", root->data);
    } else if (level > 1){
        PrintCurrentLevel(root->left, level - 1);
        PrintCurrentLevel(root->right, level - 1);
    }
}

/* Preorder: Data, Left, Right
 * Inorder: Left, Data, Right
 * Postorder: Left, Right, Data
 *
 * Complexity: all O(n)
 * Space complexity: O(h) where h is height
 */
void DfsPrint(BstNode* root){

    if(root == NULL) return;

    /* Preorder
    printf(" %d", root->data);
    DfsPrint(root->left);
    DfsPrint(root->right);
    */

    /* Inorder
    DfsPrint(root->left);
    printf(" %d", root->data);
    DfsPrint(root->right);
    */

    /* Postorder */
    DfsPrint(root->left);
    DfsPrint(root->right);
    printf(" %d", root->data);
}

// These are expensive operations, multiple nodes are being compared more than once. O(n^2)
int IsBST(BstNode* root){
    // All BST must have BST subtree
    if(root == NULL) return 1;
    if(IsSubtreeLesser(root->left, root->data)
        && IsSubtreeGreater(root->right, root->data)
        && IsBST(root->left)
        && IsBST(root->right)) return 1;
    else return 0;
}

int IsSubtreeLesser(BstNode* root, int data){
    if(root == NULL) return 1;
    if(root->data <= data
        && IsSubtreeLesser(root->left, data)
        && IsSubtreeLesser(root->right, data)) return 1;
    else return 0;
}

int IsSubtreeGreater(BstNode* root, int data){
    if(root == NULL) return 1;
    if(root->data > data
        && IsSubtreeGreater(root->left, data)
        && IsSubtreeGreater(root->right, data)) return 1;
    else return 0;
}

// This method is both shorter and more effiecient at O(n)
int IsBSTPlus(BstNode* root){
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

int IsBstUtil(BstNode* root, int min, int max){
    if(root == NULL) return 1;
    if(root->data >= min && root->data < max
        && IsBstUtil(root->left, min, root->data)
        && IsBstUtil(root->right, root->data, max)) return 1;
    else return 0;
}

/* 1. Find the min in right subtree
 * 2. Copy the value in the targetted node
 * 3. Delete the duplicate from the right subtree
 */
BstNode* Delete(BstNode* root, int data){

    if(root == NULL) return NULL;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else // Found you, prepare to be ended
    {
        // No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }

        // One child
        else if (root->left == NULL){
            BstNode* temp = root;
            root = root->right;
            free(temp);
        }

        else if (root->right == NULL){
            BstNode* temp = root;
            root = root->left;
            free(temp);
        }

        // Two children
        else {
            BstNode* temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }

    return root;
}

BstNode* FindMinNode(BstNode* root){
    if (root == NULL){
        printf("Error, tree is empty\n");
        return NULL;
    }
    if (root->left == NULL){
        printf("Min node: %d\n", root->data);
        return root;
    }
    return FindMinNode(root->left);
}
