#include <iostream>
using namespace std;

#define INF 99999  // Representation of infinity (large value)
#define MAX 10     // Maximum number of vertices

class Graph {
private:
    int n;               // Number of vertices
    int adjMatrix[MAX][MAX]; // Adjacency matrix

public:
    // Constructor to initialize the graph
    Graph(int vertices) {
        n = vertices;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    adjMatrix[i][j] = 0; // Distance to itself is 0
                else
                    adjMatrix[i][j] = INF; // Set initial distance to infinity
            }
        }
    }

    // Function to add an edge with a weight
    void addEdge(int u, int v, int weight) {
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adjMatrix[u][v] = weight; // Set weight for directed graph
        } else {
            cout << "Invalid edge! Enter valid vertex numbers.\n";
        }
    }

    // Function to display the adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j] == INF)
                    cout << "INF ";
                else
                    cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Floyd Warshall Algorithm to find shortest paths
    void floydWarshall() {
        int dist[MAX][MAX];

        // Initialize distance matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = adjMatrix[i][j];
            }
        }

        // Applying Floyd Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        if (dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }

        // Display shortest path matrix
        cout << "\nShortest Path Matrix (Floyd Warshall Algorithm):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    int vertices, edges, u, v, weight;

    cout << "Enter number of vertices: ";
    cin >> vertices;
    Graph g(vertices); // Create Graph object

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "\nEnter edges (u v weight):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    g.displayMatrix();  // Display initial adjacency matrix

    g.floydWarshall();  // Find shortest paths using Floyd Warshall

    return 0;
}
