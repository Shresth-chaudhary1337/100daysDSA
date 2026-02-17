/*
53. Maximum Subarray
Medium
Topics
premium lock iconCompanies

Given an integer array nums, find the with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104

 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/
#include<iostream>
#include<vector>
class Solution{
    public:
    int maxSubArray(std::vector<int> &arr,int &start,int &end ){

        int currentSum=0;
        int maxSum=arr[0];

        int tempstart=0;
        start=0;
        end=0;
        
        for(int i=0;i<arr.size();i++){
            currentSum+=arr[i];

            if(currentSum>maxSum){
                maxSum=currentSum;
                start=tempstart;
                end=i;
            }
            if(currentSum<0){
                currentSum=0;
                tempstart=i+1;
            }

        }
        return maxSum;
    }

};

int main(){
    int n;
    std::cout<<"enter the number of elements of array\n";
    std::cin>>n;
    std::vector<int> arr(n);

    std::cout<<"enter the elements of the array\n";
    for(int i=0;i<n;i++){
        std::cout<<"enter #"<<i+1<<" element\n";
        std::cin>>arr[i];
    }
    int start;
    int end;

    Solution obj;
    int maxSum=obj.maxSubArray(arr,start,end);
    std::cout<<"Maximum Sum of subarray= "<<maxSum;
    std::cout<<"Subarray: \n";

    for(int i=start;i<=end;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    return 0;
}