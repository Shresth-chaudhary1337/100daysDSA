/*Sliding Window Maximum
Hard
Topics
premium lock iconCompanies
Hint

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    deque<int> dq;
    vector<int> result;

    for(int i = 0; i < nums.size(); i++) {

        // remove elements which are outside the window
        if(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // remove smaller elements from back
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        // store result when first window is complete
        if(i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {

    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter window size k: ";
    cin >> k;

    vector<int> ans = maxSlidingWindow(nums, k);

    cout << "Sliding window maximums: ";

    for(int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}