#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Assume a graph is represented as an adjacency list
class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj;

    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
};

bool bidirectionalSearch(Graph& graph, int src, int dest) {
    // Create sets to track explored nodes from source and destination
    unordered_set<int> srcExplored, destExplored;
    // Create queues for BFS from source and destination
    queue<int> srcQueue, destQueue;

    srcQueue.push(src);
    destQueue.push(dest);
    srcExplored.insert(src);
    destExplored.insert(dest);

    while (!srcQueue.empty() && !destQueue.empty()) {
        // Expand search from the source end
        int srcNode = srcQueue.front();
        srcQueue.pop();

        for (int neighbor : graph.adj[srcNode]) {
            if (destExplored.count(neighbor) > 0) {
                cout << "Path found!" << endl;
                return true;
            }

            if (srcExplored.count(neighbor) == 0) {
                srcExplored.insert(neighbor);
                srcQueue.push(neighbor);
            }
        }

        // Expand search from the destination end
        int destNode = destQueue.front();
        destQueue.pop();

        for (int neighbor : graph.adj[destNode]) {
            if (srcExplored.count(neighbor) > 0) {
                cout << "Path found!" << endl;
                return true;
            }

            if (destExplored.count(neighbor) == 0) {
                destExplored.insert(neighbor);
                destQueue.push(neighbor);
            }
        }
    }

    return false;
}

int main() {
    int V = 7; // Number of vertices
    Graph graph(V);

    cout << graph.adj[0].size() << "\n";

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

    if (bidirectionalSearch(graph, src, dest)) {
        cout << "Path exists between " << src << " and " << dest << endl;
    } else {
        cout << "Path does not exist between " << src << " and " << dest << endl;
    }

    return 0;
}
