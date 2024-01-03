#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#include "BinaryTree.h"


int main(){

    BinaryTree B1 = BinaryTree();

    B1.insert(11);

    for (int i = 0; i < 20; i += 2){
        B1.insert(i);
    }

    B1.printTree();

    B1.remove(200000000);

    B1.printTree();



    return 0;
}