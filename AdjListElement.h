/*
 * An Adjacency List Element contains the second vertex
 * of the (u,v) directed edge, and its weight
 */
class AdjListElement
{
public:
    AdjListElement(int vertex, int weight); // Create the element
    ~AdjListElement();                      // Destroy the element

    int getVertex();                        // The v vertex of the (u,v) Directed Edge
    int getWeight();                        // The weight of the (u,v) Directed Edge

private:
    int vertex;                             // The v vertex of the (u,v) Directed Edge
    int weight;                             // The weight of the (u,v) Directed Edge
};