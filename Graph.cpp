#include "Graph.h"
#include <algorithm>

using namespace std;

Graph::Graph(int vertices)
{
    v              = vertices;
    e              = 0;
    adjacencyLists = vector<vector<AdjListElement>>(vertices);
}

Graph::~Graph()
{

}

int Graph::V()
{
    return v;
}

int Graph::E()
{
    return e;
}

void Graph::AddEdge(int u, int v, int w)
{
    adjacencyLists[u].push_back(AdjListElement(v, w));
}

bool Graph::HasEdge(int u, int v)
{
    // Check if the adjacency list of vertex u contains value v
    return find_if(adjacencyLists[u].begin(),
                   adjacencyLists[u].end(),
                   [=](AdjListElement &element)
                   {
                       return element.getVertex() == v;
                   })
           != adjacencyLists[u].end();
}

int Graph::OutDegree(int u)
{
    return adjacencyLists[u].size();
}

vector<AdjListElement> Graph::GetAdjList(int u)
{
    return adjacencyLists[u];
}


