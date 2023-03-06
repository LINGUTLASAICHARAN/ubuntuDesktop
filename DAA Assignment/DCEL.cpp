#include <bits/stdc++.h>
using namespace std;

class Edge;
class Face;
class Vertex
{
public:
    double x, y;
    vector<Edge *> outgoingEdges; // outgoing edges
    Vertex(int a, int b)
    {
        x = a;
        y = b;
    }
};

class Edge
{

public:
    Vertex *origin; // e.destination = e.twin.origin
    Edge *twin;
    Face *left;
    Edge* nextEdge, *previousEdge; // in counter clockwise wrt to face
};

class Face
{

public:
    Edge *incidet; // anti-clock wise
};

class DCEL
{
public:
    vector<Vertex *> v; // vertices

    vector<Edge *> e; // edges

    vector<Face *> f; // faces

    // add edge
    void addVertex(int x, int y);
    // add  edge
    void addEdge(int x1, int y1, int x2, int y2);
    // add face
};

void DCEL ::addVertex(int x, int y)
{
    Vertex *vnew = new Vertex(x, y);
    v.push_back(vnew);
}
void DCEL::addEdge(int x1, int y1, int x2, int y2)
{
    Edge *e1 = new Edge();
    Edge *e2 = new Edge();

    e.push_back(e1);
    e.push_back(e2);

    Vertex *v1, *v2;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->x == x1 && v[i]->y == y1)
        {
            v1 = v[i];
        }
        if (v[i]->x == x2 && v[i]->y == y2)
        {
            v2 = v[i];
        }
    }

    e1->twin = e2;
    e2->twin = e1;

    e1->origin = v1;
    e2->origin = v2;



}

int main()
{
    DCEL fig = DCEL();
    for (int i = 0; i < 5; i++)
    {
        fig.addVertex(i, i + 1);
    }
    cout << fig.v.size() << endl;
    fig.addEdge(1, 2, 2, 3);
    return 0;
}