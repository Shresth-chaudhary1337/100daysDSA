/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]
*/
#include<iostream>
#include<vector>
int main(){
    int n;
    std::cout<<"enter the number of elements\n";
    std::cin>>n;

    std::vector<int> nums(n);
    std::cout<<"enter the elements of array\n";
    for(int i=0;i<n;i++){
        std::cout<<"enter #"<<i+1<<" element of array\n";
        std::cin>>nums[i];
    }
    if(n==0)
    {
        std::cout<<"there is no element in the array\n";
        return 0;
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }
    }
    while(j<n){
        nums[j]=0;
        j++;
    }
    std::cout<<"required array\n";
    for(int i=0;i<n;i++){
        std::cout<<nums[i]<<" ";
    }

}