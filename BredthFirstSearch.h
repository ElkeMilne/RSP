#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

#include "AdjacencyList.h"

class BFS {
private:
    set<int> visited;     // Set to store the visited nodes.
    queue<int> discovered; // Queue to manage the nodes discovered but not yet visited.

public:
    // Constructor for the BFS class, which performs the BFS algorithm.
    BFS(AdjacencyList* graph, int startingNode, function<void(int)> discovered_touch, function<void(int)> visited_touch){
        // Start by pushing the starting node into the discovered queue.
        discovered.push(startingNode);

        // Continue the loop as long as there are nodes in the discovered queue.
        while (discovered.size() > 0){
            // Get the front node from the discovered queue.
            int node = discovered.front();
            discovered.pop(); // Remove the node from the queue.

            // Check if the node has already been visited.
            if (visited.find(node) != visited.end()){
                continue; // Skip to the next iteration if the node has been visited.
            }

            // Mark the node as visited and process it using the visited_touch function.
            visited.insert(node);
            visited_touch(node); // This can be any function that processes visited nodes.

            // Iterate over all adjacent nodes of the current node.
            for (auto i : graph->adjacencylist[node]){
                // Add each adjacent node to the discovered queue.
                discovered.push(i);
                discovered_touch(i); // Process each discovered node using the discovered_touch function.
            }
        }
    }
};
