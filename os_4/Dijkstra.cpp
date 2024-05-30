#include <iostream>
#include <limits.h>
#include <vector>
#include "dijkstra.h"
using namespace std;

int V; // Adjust this as needed for different graph sizes

// Function to find the vertex with minimum distance value
int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed distance array
void printSolution(const vector<int>& dist, int V) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << "\n";
}

// Implementation of Dijkstra's algorithm using adjacency matrix
void dijkstra(const vector<vector<int>>& graph, int src, int V){
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist, V);
}

void run_dijkstra() {
    int numVertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    if (numVertices <= 0) {
        cout << "Invalid input! Number of vertices must be a positive number." << endl;
        return;
    }

    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices, 0));

    cout << "Enter the adjacency matrix (0 for no edge, positive value for edge weight):" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j] < 0) {
                cout << "Invalid input! Edge weights cannot be negative." << endl;
                return;
            }
        }
    }

    dijkstra(adjMatrix, 0,V); // Assuming source vertex is 0, this can be taken as input as well

}
#ifndef TEST_DIJKSTRA
int main() {
    run_dijkstra();
    return 0;
}
#endif