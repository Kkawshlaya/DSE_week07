#include <iostream>
#include <list>
using namespace std;

// Structure representing a node in the graph
struct Node {
    int label;
    list<int> neighbours;
};

// Structure representing the graph
struct Graph {
    int n = 8;
    Node *nodes = new Node[n];

    // Initializes the nodes with labels
    void intializenodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i + 1;
        }
    }

    // Adds an edge between two nodes in the graph
    void addedge(int u, int v) {
        // Check if edge (u, v) or (v, u) is already present
        for (int neighbour : nodes[u - 1].neighbours) {
            if (neighbour == v) {
                return;
            }
        }
        for (int neighbour : nodes[v - 1].neighbours) {
            if (neighbour == u) {
                return;
            }
        }
        // If edge is not already present, add it
        nodes[u - 1].neighbours.push_back(v);
        nodes[v - 1].neighbours.push_back(u);
    }

    // Prints the adjacency list representation of the graph
    void print() {
        for (int i = 0; i < n; i++) {
            cout << nodes[i].label << " : ";
            for (int neighbour : nodes[i].neighbours) {
                cout << "--> " << neighbour;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph *g = new Graph;
    g->intializenodes();

    // Add edges for the graph (undirected)
    g->addedge(1, 2);
    g->addedge(1, 3);
    g->addedge(1, 4);
    g->addedge(1, 5);
    g->addedge(2, 3);
    g->addedge(2, 6);
    g->addedge(4, 6);
    g->addedge(4, 7);
    g->addedge(4, 8);
    g->addedge(5, 6);
    g->addedge(5, 7);
    g->addedge(5, 8);

    // Print the graph adjacency list
    g->print();

    delete g;
    return 0;
}
