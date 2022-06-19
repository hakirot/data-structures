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
 *   - Matrix (used prevously) uses O(v^2) of space
 *
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
#include <string.h>
#define MAX_SIZE 101

typedef struct Edge Edge;

struct Edge {
    int startVertex; // integers for vertex can represent positions of names in an array
    int endVertex;
    int weight;
};

char* name_list[MAX_SIZE];
Edge edge_list[MAX_SIZE];

int main(int argc, char * argv[]){

    int array[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++){
        printf(" %d", array[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++){
        array[i] = i*2;
    }

    for (int i = 0; i < 5; i++){
        printf(" %d", array[i]);
    }
    printf("\n");

    int* ptr = array;
    for (int i = 0; i < 5; i++){
        printf(" %d", *ptr);
        ptr++;
    }

    int* ptrArray[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            ptrArray[i][j] = malloc(sizeof(int));
            *ptrArray[i][j] = i + j;
        }
    }
    printf("\n\n");

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf(" %d", *ptrArray[i][j]);
        }
        printf(" \n");
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            free(ptrArray[i][j]);
        }
    }

    printf("\n");
    return 0;
}
