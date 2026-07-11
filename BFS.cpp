#include <iostream>

using namespace std;

const int MAX = 10;

int graph[MAX][MAX] = {0};
int queueArr[MAX];
bool visited[MAX] = {false};
bool inQueue[MAX] = {false};

int front = 0;
int rear = 0;

int main()
{
    int vertices, edges;
    int source, destination;
    int startVertex;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "\nEnter the edges (Source Destination):\n";

    // Create adjacency matrix
    for (int i = 0; i < edges; i++)
    {
        cin >> source >> destination;

        graph[source][destination] = 1;
        graph[destination][source] = 1;   // Remove this line for directed graph
    }

    cout << "\nEnter the starting vertex: ";
    cin >> startVertex;

    cout << "\nBFS Traversal: ";

    cout << startVertex << " ";
    visited[startVertex] = true;

    int count = 1;

    while (count < vertices)
    {
        // Add adjacent vertices to queue
        for (int i = 1; i <= vertices; i++)
        {
            if (graph[startVertex][i] &&
                !visited[i] &&
                !inQueue[i])
            {
                queueArr[rear++] = i;
                inQueue[i] = true;
            }
        }

        // Remove front element from queue
        startVertex = queueArr[front++];

        cout << startVertex << " ";

        visited[startVertex] = true;
        inQueue[startVertex] = false;

        count++;
    }

    return 0;
}