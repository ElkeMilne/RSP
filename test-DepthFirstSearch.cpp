#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#include "DepthFirstSearch.h"

void first_touch(int node){
    cout << node << "->";
}

void last_touch(int node){
    cout << endl;
}


int main(){
    vector<vector<int>> nodes = {{1,2},{2,3},{2,4}, {4,5}, {5,6},{5,7}, {3,10}, {3,11}, {3,12}};

    AdjacencyList* graph = new AdjacencyList(nodes);

    DFS dfs(graph, 1, &first_touch, &last_touch);


    return 0;
}