#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class QuickSort{
    static void my_swap(int* num1, int* num2){
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
        return;
    }
    static void recQuickSort(vector<int> &nums, int L, int R){
        int i, j, mid, pivot;
        i = L;
        j = R;
        mid = L + (R-L)/2;
        pivot = nums[mid];
        while (i < R || j > L) {
            while (nums[i] < pivot){
                i++;
            }
            while (nums[j] > pivot){
                j--;
            }

            if (i <= j){
                my_swap(&nums[i], &nums[j]);
                i++;
                j--;
            } else {
                if (i < R){
                    recQuickSort(nums, i, R);
                }
                if (j > L){
                    recQuickSort(nums,L,j);
                }
                for (auto num : nums){
                    cout << num << ",";
                }
                cout << endl;
                return;
            }
        }

    }
public:
    static void sort(vector<int> &nums){
        recQuickSort(nums, 0, nums.size()-1);
        return;
    }

};