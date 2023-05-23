#include <iostream>
#include <climits>

#define V 6

// Function to find the vertex with minimum key value
int findMinKey(int key[], bool mstSet[]) {
    int minKey = INT_MAX, minIndex;
    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    std::cout << "MST Order: ";
    for (int i = 1; i < V; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i) {
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

// Function to construct and print the MST using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store the constructed MST
    int key[V]; // Key values used to pick minimum weight edge
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; ++i) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0; // Make key 0 so that this vertex is picked first
    parent[0] = -1; // First node is always the root of MST

    // Construct MST with V vertices
    for (int count = 0; count < V - 1; ++count) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = findMinKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    // Example adjacency matrix (6x6) for the graph
    int graph[V][V] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    // Run Prim's MST algorithm on the graph
    primMST(graph);

    return 0;
}