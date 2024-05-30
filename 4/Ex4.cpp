#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib> // Include the cstdlib header for exit()

using namespace std;

// Function prototypes
vector<vector<int>> createGraph(int V);
int minDistance(const vector<int>& dist, const vector<bool>& sptSet);
void dijkstra(const vector<vector<int>>& graph, int src, vector<int>& dist);

int main(int argc, char* argv[]) {
    if (argc > 1) {
        // Parse the number of vertices
        int V = atoi(argv[1]);
        if (V <= 0) {
            cerr << "Number of vertices must be a positive integer." << endl;
            exit(1);
        }

        // Create the graph and get the edge weights from the input
        vector<vector<int>> graph = createGraph(V);

        vector<int> dist;
        dijkstra(graph, 0, dist);

        // Output the distance vector
        for (int i = 0; i < V; i++) {
            cout << "Distance from node 0 to node " << i << ": " << dist[i] << endl;
        }
    } else {
        cerr << "Usage: " << argv[0] << " <number_of_vertices>" << endl;
        exit(1);
    }
    return 0;
}

vector<vector<int>> createGraph(int V) {
    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter the adjacency matrix (use 0 for no edge):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int weight;
            cin >> weight;
            // Perform validation checks
            if (!cin) {
                cerr << "Invalid input. Please enter integers only." << endl;
                exit(1);
            }
            if (weight < 0) {
                cerr << "Negative weights are not allowed in Dijkstra's algorithm." << endl;
                exit(1);
            }

            graph[i][j] = weight;
        }
    }

    // Perform additional validation checks as described in the image
    for (int i = 0; i < V; i++) {
        int rowSum = 0;
        for (int j = 0; j < V; j++) {
            rowSum += graph[i][j];
        }
    }

    for (int j = 0; j < V; j++) {
        int colSum = 0;
        for (int i = 0; i < V; i++) {
            colSum += graph[i][j];
        }
    }
            return graph;}



int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = INT_MAX;
    size_t min_index = static_cast<size_t>(-1); // Use size_t to match the vector size
    for (size_t v = 0; v < dist.size(); v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return static_cast<int>(min_index); // Cast back to int for compatibility with other parts of the code
}

void dijkstra(const vector<vector<int>>& graph, int src, vector<int>& dist) {
    size_t V = graph.size();
    vector<bool> sptSet(V, false);
    dist.resize(V, INT_MAX);
    dist[src] = 0;

    for (size_t count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        if (u == -1) break;  // No more reachable vertices
        sptSet[u] = true;

        for (size_t v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

//lcov --capture --directory . --output-file coverage.info
//genhtml coverage.info --output-directory out
//orel@orel-VirtualBox:~/OS_course/Ex4$ ./Ex4 2
// Enter the adjacency matrix (use 0 for no edge):
// A@
// Invalid input. Please enter integers only.
// orel@orel-VirtualBox:~/OS_course/Ex4$ ./Ex4 0
// Number of vertices must be a positive integer.
// orel@orel-VirtualBox:~/OS_course/Ex4$ ./Ex4
// Usage: ./Ex4 <number_of_vertices>
// orel@orel-VirtualBox:~/OS_course/Ex4$ ./Ex4 -2
// Number of vertices must be a positive integer.
// orel@orel-VirtualBox:~/OS_course/Ex4$ ./Ex4 5
// Enter the adjacency matrix (use 0 for no edge):
// -2
// Negative weights are not allowed in Dijkstra's algorithm.
// orel@orel-VirtualBox:~/OS_course/Ex4$ ./Ex4 5
// Enter the adjacency matrix (use 0 for no edge):
// @a
// Invalid input. Please enter integers only.
// orel@orel-VirtualBox:~/OS_course/Ex4$ ./Ex4 3
// Enter the adjacency matrix (use 0 for no edge):
// 1
// 2
// 4
// 5
// 6
// 7
// 8
// 9
// 1
// Distance from node 0 to node 0: 0
// Distance from node 0 to node 1: 2
// Distance from node 0 to node 2: 4