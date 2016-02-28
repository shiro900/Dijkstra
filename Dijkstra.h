#include <queue>
#include <functional>
#include "Graph.h"

/*
 * Dijkstra's algorithm for computing the shortest path tree from
 * a starting vertex s. We assume that all weights are non-negative.
 * This class maintains information about the shortest path tree.
 * We are using the std::priority_queue with a custom compare function
 * that when popped, it will return the u vertex with the smallest distTo[u] value
 */
class Dijkstra
{
public:
    Dijkstra(Graph *G, int s);            // Runs the algorithm on graph G from starting vertex s
    ~Dijkstra();                          // Destroys the shortest path tree information

    void printShortestPath(int u);        // Prints the shortest path s->u to console

private:
    using DijkstraPriorityQueue = priority_queue<int, vector<int>, function<bool(int, int)>>;

    int                   s;              // The starting vertex s
    vector<float>         distTo;         // distTo[u] is the distance of the shortest s->u path
    vector<int>           previousVertex; // previousVertex[u] is the vertex before u in the shortest s->u path
    DijkstraPriorityQueue PQ;             // Min-Priority Queue, implemented for Dijkstra
};