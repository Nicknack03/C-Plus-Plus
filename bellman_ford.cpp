#include <iostream>
#include <conio.h>

using namespace std;

#define VERTICES 5
#define INFINITY 999

// Structure to store node information
struct Node
{
    int cost;      // Minimum cost from source
    int visited;   // Visited flag
    int parent;    // Previous node
} node[VERTICES];

// Function to add an edge
void addEdge(int graph[][VERTICES], int src, int dest, int cost)
{
    graph[src][dest] = cost;
}

// Dijkstra's Algorithm
void dijkstra(int graph[][VERTICES])
{
    int i, j, k;
    int count = 0;
    int current;

    // Initialize source node
    node[0].cost = 0;
    node[0].visited = 0;
    node[0].parent = 0;

    // Initialize remaining nodes
    for (i = 1; i < VERTICES; i++)
    {
        node[i].cost = INFINITY;
        node[i].visited = 0;
        node[i].parent = -1;
    }

    while (count < VERTICES)
    {
        int minimum = INFINITY;

        // Find the unvisited node with minimum cost
        for (i = 0; i < VERTICES; i++)
        {
            if (!node[i].visited && node[i].cost < minimum)
            {
                minimum = node[i].cost;
                current = i;
            }
        }

        // Update neighboring nodes
        for (k = 0; k < VERTICES; k++)
        {
            if (graph[current][k] != INFINITY &&
                node[current].cost + graph[current][k] < node[k].cost)
            {
                node[k].cost = node[current].cost + graph[current][k];
                node[k].parent = current;
            }
        }

        node[current].visited = 1;
        count++;
    }

    // Display result
    cout << "\nVertex\tCost\tParent\n";
    for (j = 0; j < VERTICES; j++)
    {
        cout << j << "\t"
             << node[j].cost << "\t"
             << node[j].parent << endl;
    }
}

int main()
{
    int graph[VERTICES][VERTICES];
    int src, dest, cost;

    // Initialize adjacency matrix
    for (int i = 0; i < VERTICES; i++)
    {
        for (int j = 0; j < VERTICES; j++)
        {
            graph[i][j] = INFINITY;
        }
    }

    cout << "Enter 8 edges (Source Destination Cost)\n";

    for (int i = 0; i < 8; i++)
    {
        cin >> src >> dest >> cost;
        addEdge(graph, src, dest, cost);
    }

    dijkstra(graph);

    getch();
    return 0;
}