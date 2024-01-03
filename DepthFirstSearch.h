#include <iostream>
#include <functional>
#include <set>

using namespace std;

#include "AdjacencyList.h"

class DFS {
private:
    set<int> visited; // Set to store the visited nodes.
    bool finished; // Flag to indicate if the DFS is finished.

    // Private method for performing DFS recursively.
    void do_DFS(AdjacencyList* graph, int node, function<void(int)> first_touch, function<void(int)> last_touch){
        // Mark the current node as visited.
        visited.insert(node);
        // Call the first_touch function, which can perform an action the first time a node is encountered.
        first_touch(node);

        // Iterate over all adjacent nodes of the current node.
        for (auto adjNode : graph->adjacencylist[node]){
            // If the adjacent node has not been visited, recursively perform DFS on it.
            if (visited.find(adjNode) == visited.end()){
                do_DFS(graph, adjNode, first_touch, last_touch);
            }
        }

        // After exploring all adjacent nodes, call the last_touch function.
        // This can perform actions after all descendants of the node have been processed.
        last_touch(node);
    }

public:
    // Constructor for the DFS class, which starts the DFS algorithm.
    DFS(AdjacencyList* graph, int startingNode, function<void(int)> first_touch, function<void(int)> last_touch){
        finished = false; // Initialize finished as false.
        
        // Start the DFS from the given starting node.
        do_DFS(graph, startingNode, first_touch, last_touch);
    }
};
