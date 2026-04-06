#include "graph.h"
// Description

// Write a function that counts how many nodes are isolated.
// A node is isolated if it has no edges connected to it.
// // The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.




int count_isolated(Graph* g) {
    // TODO: implement
    // return -1;

    int isolated = 0;

    // Traverse the adjacency matrix and determine whether the whole row is 0
    for(int i = 0; i < MAX_NODES; i++)
    {
        for(int j = 0; j < MAX_NODES; j++)
        {
            // If there's a 1 in the row, that node is not isolated--jump to next row
            if(g->adj[i][j] == 1)
            {
                goto jump_to_next_row;
            }
        }
        // If entire row was 0's, increment isolated
        isolated++;

        jump_to_next_row:
    }
    return isolated;
}















// Tip: In the adjacency matrix, that means the entire row for that node contains only 0s.
