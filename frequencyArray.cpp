/*
Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    int n;
    std::cout<<"enter the number of elements of the array\n";
    cin>>n;
    unordered_map<int,int> freq;
    vector<int> order;
    cout<<"enter the elements of the array\n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        if(freq[x]==0)
        order.push_back(x);
        freq[x]++;
    }
    for(int x:order){
        cout<<x<<":"<<freq[x]<<" ";
    }

}