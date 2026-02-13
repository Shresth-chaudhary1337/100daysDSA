#include<iostream>
#include<vector>
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        while(j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main(){
    std::vector<int> nums1={1,2,3,0,0,0};
    std::vector<int> nums2={2,5,6};
    int m=3;
    int n=3;
    Solution obj;
    obj.merge(nums1,m,nums2,n);
    
    for(int i=0;i<m+n;i++){
        std::cout<<nums1[i]<<" ";
    }

}