#include<unordered_map>
#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        std::unordered_map<int,int> count;
        vector<int> result;

        for(int i=0;i<nums1.size();i++){
            count[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            if(count[ nums2[i]]>0)
            {
                result.push_back(nums2[i]);
                count[nums2[i]]--;
            }
        }
        return result;
        
    }
};
int main(){
    int a,b;
    std::cout<<"enter the number of elements of both array respectively\n";
    std::cin>>a>>b;
    vector<int> nums1(a);
    vector<int> nums2(b);

    std::cout<<"enter the elements of array 1\n";
    for(int i=0;i<a;i++)
    std::cin>>nums1[i];
    std::cout<<"enter the elements of array 2\n";
    for(int i=0;i<b;i++)
    std::cin>>nums2[i];

    Solution obj;
    std::cout<<"required array:-";
    std::vector<int> result=obj.intersect(nums1,nums2);
    for(int i=0;i<result.size();i++)
    std::cout<<result[i]<<" ";
}