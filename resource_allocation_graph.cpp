#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a structure to represent a node in the resource allocation graph
struct Node {
    int id;              // Node ID
    int num_resources;   // Number of resources this node is holding
    vector<int> edges;   // Adjacency list representing outgoing edges
};

// Function to detect deadlocks in the resource allocation graph
bool detectDeadlock(vector<Node>& graph) {
    // Create a queue of nodes that have no outgoing edges (i.e., they are not holding any resources)
    queue<int> q;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].edges.empty()) {
            q.push(i);
        }
    }
    
    // Keep track of nodes that are visited and marked for removal from the graph
    vector<bool> visited(graph.size(), false);
    vector<bool> marked_for_removal(graph.size(), false);
    
    // Process nodes in the queue
    while (!q.empty()) {
        int node_id = q.front();
        q.pop();
        
        // If the node is not marked for removal and has no outgoing edges, mark it for removal
        if (!marked_for_removal[node_id] && graph[node_id].edges.empty()) {
            marked_for_removal[node_id] = true;
            visited[node_id] = true;
            
            // Release the resources held by the node and update the resource count of its neighbors
            for (int neighbor_id : graph[node_id].edges) {
                graph[neighbor_id].num_resources++;
            }
            
            // Add the neighbors that now have no outgoing edges to the queue
            for (int neighbor_id : graph[node_id].edges) {
                if (!marked_for_removal[neighbor_id] && graph[neighbor_id].edges.empty()) {
                    q.push(neighbor_id);
                }
            }
        }
    }
    
    // Check if there are any nodes that are still holding resources
    for (int i = 0; i < graph.size(); i++) {
        if (!marked_for_removal[i] && graph[i].num_resources > 0) {
            return true;    // Deadlock detected
        }
    }
    
    return false;           // No deadlock detected
}

int main() {
    // Construct a sample resource allocation graph
    vector<Node> graph = {
        {0, 2, {1}},
        {1, 1, {2, 3}},
        {2, 1, {4}},
        {3, 1, {4}},
        {4, 0, {}}
    };
    
    // Detect deadlocks in the graph
    bool is_deadlock = detectDeadlock(graph);
    
    if (is_deadlock) {
        cout << "Deadlock detected!" << endl;
    } else {
        cout << "No deadlock detected." << endl;
    }
    
    return 0;
}
