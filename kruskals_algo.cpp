#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int V = 4;   // Number of vertices

// Structure to represent an edge
struct Edge
{
    int source;
    int destination;
    int weight;
};

// Parent array for Disjoint Set
int parent[V];

// Find operation with Path Compression
int findParent(int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] = findParent(parent[vertex]);
}

// Union operation
void unionSet(int u, int v)
{
    int rootU = findParent(u);
    int rootV = findParent(v);

    parent[rootU] = rootV;
}

// Kruskal's Algorithm
void kruskal(vector<Edge> &edges)
{
    // Sort edges by weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    int totalCost = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (Edge edge : edges)
    {
        int u = edge.source;
        int v = edge.destination;

        if (findParent(u) != findParent(v))
        {
            cout << u << " - " << v
                 << " : " << edge.weight << endl;

            totalCost += edge.weight;
            unionSet(u, v);
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;
}

int main()
{
    // Initialize parent array
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    vector<Edge> edges =
    {
        {0, 1, 10},
        {1, 2, 18},
        {2, 3, 13},
        {0, 2, 21},
        {1, 3, 22}
    };

    kruskal(edges);

    return 0;
}