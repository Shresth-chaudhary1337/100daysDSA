/*
Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left*/
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> deleteAtPosition(std::vector<int>& nums, int pos) {

        int n = nums.size();
        int index = pos - 1;

        if(index < 0 || index >= n)
            return nums;

        for(int i = index; i < n - 1; i++)
            nums[i] = nums[i + 1];

        nums.pop_back();

        return nums;
    }
};

int main() {
    int n;
    std::cout<<"enter number of elements\n";
    std::cin >> n;

    std::vector<int> nums(n);

    // input array
    for(int i = 0; i < n; i++){
        std::cout<<"enter #"<<i+1<<" element of array\n";
        std::cin >> nums[i];
    }
    int pos;
    std::cout<<"enter the element position you want to delete\n";
    std::cin >> pos;

    Solution obj;

    // call function
    std::vector<int> result = obj.deleteAtPosition(nums, pos);

    // print result
    for(int x : result)
        std::cout << x << " ";

    return 0;
}
