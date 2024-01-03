#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#include "BredthFirstSearch.h"

void discovered(int node){
    cout << node << " ";
}

void visited(int node){
    cout << endl << node << ":";
}


int main(){
    vector<vector<int>> nodes = {{1,2},{2,3},{2,4}, {4,5}, {5,6},{5,7}, {3,10}, {3,11}, {3,12}};

    AdjacencyList* graph = new AdjacencyList(nodes);

    BFS bfs(graph, 1, &discovered, &visited);


    return 0;
}