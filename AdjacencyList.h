#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// Structure representing an edge in a graph.
struct Edge {
    int x, y;  // The vertices that the edge connects.

    // Constructor to initialize an Edge with vertices x and y.
    Edge(int x, int y){
        this->x = x; 
        this->y = y;
    }
};

// Class representing a graph using an adjacency list.
class AdjacencyList {
public:
    // Map where each key is a vertex and the associated value is a set of vertices
    // that are adjacent to the key vertex. The set ensures each adjacent vertex is unique.
    map<int, set<int>> adjacencylist;

    // Default constructor for an empty adjacency list.
    AdjacencyList() {

    }

    // Constructor that builds the adjacency list from a vector of Edge objects.
    AdjacencyList(vector<Edge> edges){
        for (auto edge : edges){
            // For each edge, add the vertices to each other's adjacency list.
            // This is for an undirected graph where each edge is bidirectional.
            adjacencylist[edge.x].insert(edge.y);
            adjacencylist[edge.y].insert(edge.x);
        }
    }

    // Constructor that builds the adjacency list from a 2D vector,
    // where each sub-vector represents an edge with two vertices.
    AdjacencyList(vector<vector<int>> edges){
        // This is a type specifier that instructs the compiler to automatically 
        //deduce the type of the variable edge from the elements of edges. 
        //It's a way to write type-agnostic code, especially when the type of the elements
        // is either complex or obvious from the context. In this case, it means the type of edge 
        //will be whatever type is stored in the edges container.

        //It means that for each Edge object in edges, the program will insert edge.y 
        //into the set that is mapped to edge.x in your adjacency list. This process will repeat
        // for every Edge object in edges, effectively building the adjacency list for your graph.
        for (auto edge : edges){
            // Similar to the above constructor, adds each vertex in the edge
            // to the other's adjacency list.
            adjacencylist[edge[0]].insert(edge[1]);
            adjacencylist[edge[1]].insert(edge[0]);
        }
    }
    
    // Method to insert an edge into the graph.
    void insert_edge(Edge edge){
        // Inserts the edge into the adjacency list, ensuring each vertex
        // appears in the other's list. This is for undirected graphs.
        adjacencylist.at(edge.x).insert(edge.y);
        adjacencylist.at(edge.y).insert(edge.x);
    }

    // Method to remove an edge from the graph.
    void remove_edge(Edge edge){
        // Erases the edge from the adjacency list by removing each vertex
        // from the other's list.
        adjacencylist.at(edge.x).erase(edge.y);
        adjacencylist.at(edge.y).erase(edge.x);
    }

    // Method to print the adjacency list representation of the graph.
    void print_graph(){
        cout << "printing" << endl;
        // Iterates over each vertex and its adjacency list.
        for (auto i : this->adjacencylist){
            cout << i.first << ": ";
            // Prints each vertex connected to the current vertex.
            for (auto j : i.second){
                cout << j << " ";
            }
            cout << endl; // New line after printing each adjacency list.
        }
    }

};
