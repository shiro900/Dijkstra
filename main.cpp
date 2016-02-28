#include <iostream>
#include "Dijkstra.h"

using namespace std;

int main()
{
    Graph *G = new Graph(9);
    G->AddEdge(1, 2, 20);
    G->AddEdge(1, 4, 80);
    G->AddEdge(1, 7, 90);

    G->AddEdge(2, 6, 10);

    G->AddEdge(3, 4, 10);
    G->AddEdge(3, 6, 50);
    G->AddEdge(3, 8, 20);

    G->AddEdge(4, 3, 10);
    G->AddEdge(4, 7, 20);

    G->AddEdge(5, 2, 50);
    G->AddEdge(5, 7, 30);

    G->AddEdge(6, 3, 10);
    G->AddEdge(6, 4, 40);

    G->AddEdge(7, 1, 20);

    Dijkstra *d = new Dijkstra(G, 1); // run algorithm from a starting vertex s
    d->printShortestPath(6);          // print shortest path s->u

    cout << "END" << endl;
    delete d;
    //char c = getchar();

    return 0;
}