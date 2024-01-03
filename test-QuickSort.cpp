#include <iostream>
using namespace std;

#include "QuickSort.h"

int main(){
    vector<int> nums = {2,7,1,1,8,9,4,3,1,4,52,6,32,3,1};
    QuickSort::sort(nums);
    cout << endl << "Sorted Vector" << endl;
    for (auto num : nums){
        cout << num << " ";
    }
    cout << endl;
}