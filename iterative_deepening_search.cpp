#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj;

    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
};

bool depthLimitedSearch(Graph& graph, int src, int dest, int depthLimit) {
    if (src == dest) {
        cout << src << " ";
        return true;
    }

    if (depthLimit <= 0) {
        return false;
    }

    for (int neighbor : graph.adj[src]) {
        if (depthLimitedSearch(graph, neighbor, dest, depthLimit - 1)) {
            cout << src << " ";
            return true;
        }
    }

    return false;
}

bool iterativeDeepeningSearch(Graph& graph, int src, int dest, int maxDepth) {
    for (int depth = 0; depth <= maxDepth; ++depth) {
        if (depthLimitedSearch(graph, src, dest, depth)) {
            cout << src << " ";
            return true;
        }
    }

    return false;
}

int main() {
    int V = 7; // Number of vertices
    Graph graph(V);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    int src = 0;
    int dest = 6;
    int maxDepth = 3; // Maximum depth for iterative deepening

    if (iterativeDeepeningSearch(graph, src, dest, maxDepth)) {
        cout << "Path exists between " << src << " and " << dest << endl;
    } else {
        cout << "Path does not exist between " << src << " and " << dest << endl;
    }

    return 0;
}
