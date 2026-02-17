/*
Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1
*/
#include<iostream>
#include<vector>
int main(){
    int n;
    std::cout<<"enter the number of element of array\n";
    std::cin>>n;
    std::vector<int> arr(n);
    std::cout<<"enter the elements of array\n";
    for(int i=0;i<n;i++){
        std::cout<<"enter #"<<i+1<<" element of array\n";
        std::cin>>arr[i];
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
        max=arr[i];
        if(arr[i]<min)
        min=arr[i];
    }
    std::cout<<"Max: "<<max;
    std::cout<<"Min: "<<min;
}