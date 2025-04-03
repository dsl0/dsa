#include <iostream>

using namespace std;

class Graph {
private:
    int n;                    // Number of vertices
    int adjMatrix[10][10];     // Adjacency matrix
    int visited[10];           // Visited array for BFS
    int visited1[10];          // Visited array for DFS
    int queue[10], front, rear;// Queue for BFS
    int stack[10], top;        // Stack for DFS

public:
    // Constructor to initialize the graph
    Graph(int vertices) {
        n = vertices;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0; // Initialize adjacency matrix
            }
            visited[i] = 0;
            visited1[i] = 0;
        }
        front = rear = 0; // Initialize queue
        top = -1;         // Initialize stack
    }

    // Function to add an edge
    void addEdge(int u, int v) {
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // Undirected graph
        } else {
            cout << "Invalid edge! Enter valid vertex numbers.\n";
        }
    }

    // Function to display adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // BFS using an array-based queue
    void BFS(int start) {
        if (start < 0 || start >= n) {
            cout << "Invalid start vertex for BFS!\n";
            return;
        }

        // Reset visited array
        for (int i = 0; i < n; i++) visited[i] = 0;

        cout << "\nBFS Traversal: ";
        queue[rear++] = start;
        visited[start] = 1;

        while (front < rear) {
            int v = queue[front++];
            cout << v << " ";

            for (int i = 0; i < n; i++) {
                if (adjMatrix[v][i] == 1 && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
        }
        cout << endl;
    }

    // DFS using an array-based stack
    void DFS(int start) {
        if (start < 0 || start >= n) {
            cout << "Invalid start vertex for DFS!\n";
            return;
        }

        // Reset visited array
        for (int i = 0; i < n; i++) visited1[i] = 0;

        cout << "\nDFS Traversal: ";
        stack[++top] = start;
        visited1[start] = 1;

        while (top != -1) {
            int v = stack[top--];
            cout << v << " ";

            for (int i = n - 1; i >= 0; i--) {
                if (adjMatrix[v][i] == 1 && visited1[i] == 0) {
                    stack[++top] = i;
                    visited1[i] = 1;
                }
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    int vertices, edges, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> vertices;
    Graph g(vertices); // Create Graph object

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "\nEnter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayMatrix();

    cout << "Enter starting vertex for BFS: ";
    cin >> start;
    g.BFS(start);

    cout << "Enter starting vertex for DFS: ";
    cin >> start;
    g.DFS(start);

    return 0;
}
