/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, 
the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and
 [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.
*/
#include <bits/stdc++.h>
#include<vector>
int main(){
    int n;
    std::cout<<"enter the number of elements of array\n";
    std::cin>>n;
    std::vector<int> arr(n);

    std::cout<<"enter the elements of the array\n";
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::unordered_map<long long,int> freq;
    long long sum=0;
    long long count=0;
    freq[0]=1;

    for(int x:arr){
        sum+=x;
        
        if(freq.find(sum)!=freq.end()){
            count+=freq[sum];
        }
        freq[sum]++;
    }
    std::cout<<count<<"\n";
    return 0;

}