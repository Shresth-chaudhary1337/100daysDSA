/*
Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right*/

#include<iostream>
int main(){
    int n; //to store size of the array
    std::cout<<"enter number of elements you want to enter in an array\n";
    std::cin>>n;
    int array[n+1];
    for(int i=0;i<n;i++){
        std::cout<<"enter #"<<i+1<<" elements of array\n";
        std::cin>>array[i];
    }
    int pos,element; //pos for positon,elements to store element
    std::cout<<"enter element you want to enter \n";
    std::cin>>element;
    std::cout<<"enter position at which you want to enter the given element\n";
    std::cin>>pos;

    //for to shift elements 
    for(int i=n+1;i>=pos;i--){
        array[i]=array[i-1];
    }
    array[pos-1]=element;//positioning element at the given position

    std::cout<<"modified array:-\n";
    for(int i=0;i<n+1;i++){
        std::cout<<array[i]<<" ";
    }
}