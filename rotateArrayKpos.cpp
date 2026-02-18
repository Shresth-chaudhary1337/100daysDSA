/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/
#include<iostream>
#include<vector>
int main(){
    int n;
    std::cout<<"enter the number of elements of array\n";
    std::cin>>n;
    std::vector<int> arr(n);
    std::cout<<"enter the elements of the array\n";
    for(int i=0;i<n;i++)
    std::cin>>arr[i];

    int k;
    std::cout<<"enter the value by how much you want to rotate the array\n";
    std::cin>>k;
    k=k%n;
    std::vector<int> temp(n);
    for(int i=0;i<n;i++){
        temp[(i+k)%n]=arr[i];
    }
    std::cout<<"rotated array: \n";
    for(int i=0;i<n;i++)
    std::cout<<temp[i]<<" ";
}