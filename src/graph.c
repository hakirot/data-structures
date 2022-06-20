/* Graph: The other non-linear data structure
 *  A graph G is an ordered pair of a set V vertices and a set of E edges
 *      G = (V, E)
 *
 *  V = {v1, v2, v3, ... etc}
 *
 *  E = {
 *          {v1, v2},
 *          {v2, v4},
 *          {v3, v6}
 *      }
 *
 *  A digraph is a directed graph, otherwise it is an undirected graph
 *  An ordered pair (a, b) is not equal to (b, a)
 *
 *  Undirected graph: social network
 *  Directed graph: hyperlinks
 *    - Web crawling is graph traversal
 *
 *  |V| - Number of Vertices
 *  |E| - Number of Edges
 *
 *  Weighted graphs have values associated with their edges, making working with graphs
 *  more difficult. Other interesting tidbits that may exist are self-loops(vertices with
 *  links to themselves) and multiedges (Two vertices that have more than one edge, like 
 *  multiple flights between cities)
 *
 *  We can represent links in a graph with adjacency lists or adjacency matrix
 *   - Matrix (used prevously) uses O(v^2) of space because we store NO CONNECTIONS as well (redundant)
 *   - Most of real-world graphs are sparse, in that vertices are connected to few other vertices
 *      - May want to use an array of linked lists (buckets)
 *          - Space complexity of this method is O(e)
 *          - However, time complexity for finding if two nodes are connected is, worst case, O(v)
 *              - Binary search would be log(v), but keeping an array sorted is costly
 *              - For an adjacency matrix, complexity would be O(1), since we would know the position of the connection
 *  Path (aka walk): a sequence of vertices where each adjacent pair is connected by an edge
 *  Simple Path: a path in which no vertices (and thus no edges) are repeated
 *  Trail: a walk in which no edges are repeated but vertices may be repeated
 *
 *  Strongly connected graphs: there is a path from any vertex to any other vertex, otherwise
 *  the graph is weakly connected, or just a connected graph
 *
 *  Acyclic graph: a graph with no cycle (like a tree)
 *  Directed acyclic graph (DAG): same but directed
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM_VERTICES 8

typedef struct Node Node;

char Names[NUM_VERTICES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

struct Node {
    int data; // represents the neighbor in the Array list
    Node* next; // Next neighbor
    //int weight; // Optional weight
};

void InitArray(Node** array);
Node* GetNewNode(int data);
void AddConnection(Node** array, char vertex, char neighbor);
int SearchConnection(Node** array, char vertex, char neighbor);
void PrintGraph(Node** array);
void RemoveConnection(Node** array, char vertex, char neighbor);

int main(int argc, char * argv[]){

    Node* Array[NUM_VERTICES];
    InitArray(Array);

    // Create relationships
    AddConnection(Array, 'A', 'B');
    AddConnection(Array, 'A', 'C');
    //AddConnection(Array, 'A', 'C'); // Error occurs correctly
    AddConnection(Array, 'A', 'D');
    AddConnection(Array, 'A', 'F');
    AddConnection(Array, 'B', 'C');
    AddConnection(Array, 'F', 'H');
    PrintGraph(Array);

    printf("---------------------------------\nAfter removals of A-D, A-F, F-H:\n--------------------------------- \n");
    RemoveConnection(Array, 'A', 'D');
    RemoveConnection(Array, 'A', 'F');
    RemoveConnection(Array, 'F', 'H');
    PrintGraph(Array);

    return 0;
}

Node* GetNewNode(int data){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void AddConnection(Node** array, char vertex, char neighbor){

    int a = vertex - 65;
    int b = neighbor - 65;
    if (a < 0 || a >= 0 + NUM_VERTICES ||
        b < 0 || b >= 0 + NUM_VERTICES ||
        a == b)
    {
        if(a == b){
            printf("Error: Duplicate vertex\n");
            return;
        } else {
            printf("Error: Vertex unknown\n");
            return;
        }
    }

    if(SearchConnection(array, vertex, neighbor)){
        printf("Error: %c already connected to %c\n", vertex, neighbor);
        return;
    }


    if(array[a] == NULL){
        array[a] = GetNewNode(b);

    } else {

        Node* temp = array[a];

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = GetNewNode(b);
    }

    // (if A -> B, then B also has connected to A)
    if(SearchConnection(array, neighbor, vertex)){
        printf("Error: %c already connected to %c\n", vertex, neighbor);
        return;
    }
    if(array[b] == NULL){
        array[b] = GetNewNode(a);
    } else {
        Node* temp = array[b];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = GetNewNode(a);
    }

    return;
}

int SearchConnection(Node** array, char vertex, char neighbor){

    //if connection exists return 1
    Node* temp = array[vertex - 65];

    if (temp == NULL){
        return 0;
    } else {
        while(temp != NULL){
            if(temp->data == neighbor - 65){
                return 1;
            }
            temp = temp->next;
        }
    }

    return 0;
}

void InitArray(Node** array){

    for(int i = 0; i < NUM_VERTICES; i++){
        array[i] = NULL;
    }
}

void PrintGraph(Node** array){
    for(int i = 0; i < NUM_VERTICES; i++){
        printf("%c: ", i + 65);
        Node* temp = array[i];
        while(temp != NULL){
            printf("%c ", temp->data + 65);
            temp = temp->next;
        }
        printf("\n");
    }

    return;
}

void RemoveConnection(Node** array, char vertex, char neighbor){

    int a = vertex - 65;
    int b = neighbor - 65;
    if (a < 0 || a >= 0 + NUM_VERTICES ||
        b < 0 || b >= 0 + NUM_VERTICES ||
        a == b)
    {
        if(a == b){
            printf("Error: Duplicate vertex\n");
            return;
        } else {
            printf("Error: Vertex unknown\n");
            return;
        }
    }

    if(!SearchConnection(array, vertex, neighbor)){
        printf("Error: %c is not connected to %c -- no deletion needed\n", vertex, neighbor);
        return;
    }


    Node* temp = array[a];
    if (temp->data == b){

        array[a] = temp->next;
        free(temp);
        temp = NULL;

    } else {

        while(temp->next != NULL){
            if(temp->next->data == b){

                Node* gbge = temp->next;
                temp->next = temp->next->next;
                free(gbge);
                gbge = NULL;
                break;
            }
            temp = temp->next;
        }
        if(1){
            printf("..paused\n");
            getchar();
        }
    }

    temp = array[b];
    if (temp->data == a){

        array[b] = temp->next;
        free(temp);
        temp = NULL;

    } else {
        while(temp->next != NULL){
            if(temp->next->data == a){

                Node* gbge = temp->next;
                temp->next = temp->next->next;
                free(gbge);
            }
            temp = temp->next;
        }
    }
}

/*
    if(1){
        printf("..paused\n");
        getchar();
    }
*/

