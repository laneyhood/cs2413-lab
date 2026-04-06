#include "graph.h"

// Description

// Check whether the graph contains a triangle. A triangle is a set of three nodes that are all connected to each other. 
// The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.

int has_triangle(Graph* g) {
    // TODO: implement
    // return -1;

    // Initialize matrices for multiplication
    int A2[MAX_NODES][MAX_NODES] = {0};
    int A3[MAX_NODES][MAX_NODES] = {0};

    // Calculate A2
    for(int i = 0; i < MAX_NODES; i++)
    {
        for(int j = 0; j < MAX_NODES; j++)
        {
            for(int k = 0; k < MAX_NODES; k++)
            {
                A2[i][j] += g->adj[i][k] * g->adj[k][j];
            }
        }
    }

    // Calculate A3
    for(int i = 0; i < MAX_NODES; i++)
    {
        for(int j = 0; j < MAX_NODES; j++)
        {
            for(int k = 0; k < MAX_NODES; k++)
            {
                A3[i][j] += g->adj[i][k] * A2[k][j];
            }
        }
    }


    // Number of triangles is (trace of A3) / 6
    int triangles = 0;

    // Calculate trace of A3
    for(int i = 0; i < MAX_NODES; i++)
    {
        // Sum up diagonal elements
        triangles += A3[i][i];
    }
    triangles /= 6;

    if(triangles == 0) return 0;
    return 1;
}
