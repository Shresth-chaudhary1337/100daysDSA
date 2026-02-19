/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
int main(){
    int n;
    std::cout<<"enter the number of elements of the array\n";
    std::cin>>n;
    std::vector<int> arr(n);
    std::cout<<"enter the elements of the array\n";
    for(int i=0;i<n;i++){
        std::cout<<"enter #"<<i+1<<" element\n";
        std::cin>>arr[i];
    }
    std::sort(arr.begin(),arr.end());
    int minSum=INT_MAX;
    int x=0,y=0;
    int left=0,right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(abs(sum)<abs(minSum)){
            minSum=sum;
            x=arr[left];
            y=arr[right];
        }
        if(sum<0)
        left++;
        else
        right--;
    }
    std::cout<<"Pair:-\n";

    std::cout<<x<<" "<<y;
}