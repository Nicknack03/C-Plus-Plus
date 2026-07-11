#include <iostream>
#include <climits>

using namespace std;

const int V = 6;

// Function to find the vertex with minimum distance
int findMinDistance(int distance[], bool visited[])
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && distance[i] < min)
        {
            min = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V], int source)
{
    int distance[V];
    bool visited[V];

    // Initialize arrays
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int current = findMinDistance(distance, visited);
        visited[current] = true;

        // Update distances of adjacent vertices
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] &&
                graph[current][i] != 0 &&
                distance[current] != INT_MAX &&
                distance[current] + graph[current][i] < distance[i])
            {
                distance[i] = distance[current] + graph[current][i];
            }
        }
    }

    // Display shortest distances
    cout << "\nVertex\tDistance from Source\n";

    for (int i = 0; i < V; i++)
    {
        cout << char('A' + i) << "\t" << distance[i] << endl;
    }
}

int main()
{
    int graph[V][V] =
    {
        {0, 10, 20, 0, 0, 0},
        {10, 0, 0, 50, 10, 0},
        {20, 0, 0, 20, 33, 0},
        {0, 50, 20, 0, 20, 2},
        {0, 10, 33, 20, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };

    dijkstra(graph, 0);

    return 0;
}