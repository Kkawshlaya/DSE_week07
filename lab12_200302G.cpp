#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // pair of node and distance

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    distances[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distances[node])
            continue;

        // Iterate over the neighbors of the current node
        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (graph[node][neighbor] != 0) {
                int new_dist = dist + graph[node][neighbor];
                if (new_dist < distances[neighbor]) {
                    distances[neighbor] = new_dist;
                    pq.push({new_dist, neighbor});
                }
            }
        }
    }

    return distances;
}

int main() {
    // Weighted adjacency matrix for the graph
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int numCities = graph.size();

    int source;
    cout << "Enter the source city: ";
    cin >> source;

    // Perform Dijkstra's algorithm for the given source city
    vector<int> distances = dijkstra(graph, source);

    // Output the shortest distances from the source city to all other cities
    cout << "Shortest distances from City " << source << ":\n";
    for (int i = 0; i < numCities; ++i) {
        if (i != source) {
            cout << "City " << source << " to City " << i << ": ";
            if (distances[i] != INT_MAX)
                cout << distances[i] << " units\n";
            else
                cout << "No path\n";
        }
    }

    return 0;
}
