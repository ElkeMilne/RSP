#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#include "AdjacencyList.h"



int main(){
    vector<vector<int>> nodes = {{1,5},{1,2},{2,5},{2,4},{2,3},{3,4},{4,5}};

    AdjacencyList al1(nodes);

    al1.print_graph();

}