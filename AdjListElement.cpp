#include "AdjListElement.h"

AdjListElement::AdjListElement(int vertex, int weight)
{
    this->vertex = vertex;
    this->weight = weight;
}

AdjListElement::~AdjListElement()
{

}

int AdjListElement::getVertex()
{
    return vertex;
}

int AdjListElement::getWeight()
{
    return weight;
}
