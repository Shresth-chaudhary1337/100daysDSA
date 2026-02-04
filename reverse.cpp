#include<iostream>
#include<vector>

class solution{
    public:
    void reverseArray(std::vector<int> &nums){
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            right--;
            left++;
        }
    }
};

int main(){
        int n;
        std::cout<<"enter number of elements of an array\n";
        std::cin>>n;

        std::vector<int> nums(n);
        std::cout<<"enter the elements of array\n";
        for(int i=0;i<nums.size();i++){
            std::cin>>nums[i];
        }
        solution obj;
        obj.reverseArray(nums);
        std::cout<<"reversed array\n";
        for(int i=0;i<nums.size();i++){
            std::cout<<nums[i]<<" ";
        }

}