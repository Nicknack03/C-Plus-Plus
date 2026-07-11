#include <iostream>

using namespace std;

const int MAX = 10;

int graph[MAX][MAX] = {0};
int stackArr[MAX];
bool visited[MAX] = {false};
bool inStack[MAX] = {false};

int top = 0;

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

    cout << "\nDFS Traversal: ";

    cout << startVertex << " ";
    visited[startVertex] = true;

    int count = 1;

    while (count < vertices)
    {
        // Push adjacent vertices onto the stack
        for (int i = vertices; i >= 1; i--)
        {
            if (graph[startVertex][i] &&
                !visited[i] &&
                !inStack[i])
            {
                stackArr[top++] = i;
                inStack[i] = true;
            }
        }

        // Pop the next vertex
        startVertex = stackArr[--top];

        cout << startVertex << " ";

        visited[startVertex] = true;
        inStack[startVertex] = false;

        count++;
    }

    return 0;
}