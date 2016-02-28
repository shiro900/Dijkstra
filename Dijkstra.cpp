#include "Dijkstra.h"
#include <float.h>
#include <set>
#include <iostream>
#include <bits/stl_algo.h>

Dijkstra::Dijkstra(Graph *G, int s)
    : PQ([this](int u, int v)
         { return distTo[u] > distTo[v]; })
{
    this->s = s;                         // starting vertex s
    int V = G->V();                      // the number of vertices
    distTo = vector<float>(V, FLT_MAX);  // initialize the distances to a large value
    distTo[s] = 0;                       // set distance of s->s path to 0
    previousVertex = vector<int>(V - 1);

    PQ.push(s);                // add s to the PQ
    set<int> visitedVertices;  // the visited vertices
    visitedVertices.insert(s); // mark s as visited

    // While our priority queue is not empty
    while (!PQ.empty())
    {
        int u = PQ.top();
        PQ.pop();

        // For every neighbor vertex of the vertex u
        for (AdjListElement &element : G->GetAdjList(u))
        {
            int v = element.getVertex();
            int w = element.getWeight();

            // Relax the edge (u,v)
            if (distTo[u] + w < distTo[v])
            {
                // Update the shortest path tree
                distTo[v]         = distTo[u] + w;
                previousVertex[v] = u;
            }

            // If we haven't visited vertex v yet
            if (visitedVertices.find(v) == visitedVertices.end())
            {
                PQ.push(v);                // add v to the PQ
                visitedVertices.insert(v); // mark v as visited
            }
        }
    }
}

Dijkstra::~Dijkstra()
{

}

void Dijkstra::printShortestPath(int u)
{
    string shortestPath;

    if (u == s)
    {
        shortestPath = to_string(s);
    }
    else
    {
        shortestPath = to_string(u);

        int prev = u;
        // Keep setting u to previous vertex of the shortest path
        // until we reach the starting vertex s
        while (true)
        {
            if (prev == s)
                break;

            prev = previousVertex[prev];
            shortestPath += " >- ";
            shortestPath += to_string(prev);
        }
    }

    // Reverse the string
    shortestPath = string(shortestPath.rbegin(), shortestPath.rend());
    cout << "Shortest " << s << "->" << u << " path is: { " << shortestPath << " }" << endl;
}
