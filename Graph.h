#include <vector>
#include "AdjListElement.h"

using namespace std;

/*
 * Directed Weighted Graph implementation using Adjacency Lists
 * The adjacency lists are implemented as std::vectors
 * and they are all stored inside an outer std::vector.
 */
class Graph
{
public:
    Graph(int vertices);                                 // Create a Graph with n vertices and no edges
    ~Graph();                                            // Destroy the Graph

    int                    V();                          // Number of vertices in the Graph
    int                    E();                          // Number of edges in the Graph
    void                   AddEdge(int u, int v, int w); // Add edge (u,v) with w weight
    bool                   HasEdge(int u, int v);        // True if Graph has edge (u,v)
    int                    OutDegree(int u);             // The out-degree of a vertex
    vector<AdjListElement> GetAdjList(int u);            // The Adjacent vertices of the vertex u

private:
    int                            v;                    // Number of vertices in the Graph
    int                            e;                    // Number of edges in the Graph
    vector<vector<AdjListElement>> adjacencyLists;       // Each adjacency list is implemented as a vector
};