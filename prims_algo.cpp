#include <iostream>
#include <climits>

using namespace std;

const int V = 6;

// Function to find the vertex with the minimum key value
int findMinKey(int key[], bool visited[])
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to print the Minimum Spanning Tree
void printMST(int parent[], int graph[V][V])
{
    int totalCost = 0;

    cout << "\nEdge\tWeight\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "\nTotal Cost of MST = " << totalCost << endl;
}

// Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool visited[V];

    // Initialize arrays
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    // Start from vertex 0
    key[0] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinKey(key, visited);

        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V];

    cout << "Enter the adjacency matrix for a graph with "
         << V << " vertices:\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    primMST(graph);

    return 0;
}