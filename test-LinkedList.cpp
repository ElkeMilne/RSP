#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(){
    LinkedList l1 = LinkedList();
    for (int i = 0; i < 10; i++){
        l1.insert(i);
    }
    
    for (auto node = l1.head; node != nullptr; node = node->next){
        cout << node->value << " ";
    }

    cout << endl;
    cout << l1.size << endl;

    for (int i = 0; i < 10; i += 2){
        l1.remove(i);
    }

    for (auto node = l1.head; node != nullptr; node = node->next){
        cout << node->value << " ";
    }
    cout << endl;
    cout <<  l1.size <<endl;

    return 0; 
}