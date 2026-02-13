/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3 */
#include<iostream>
#include<vector>
int main(){
    int n;
    std::cout<<"enter the number of elements of array\n";
    std::cin>>n;

    std::vector<int> arr(n);
    std::cout<<"enter the elements of array in sorted manner\n";
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    if(n==0){
        std::cout<<"there is no element in the array\n";
        return 0;
    }

    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[j]){
            j++;
            arr[j]=arr[i];
        }
    }
    std::cout<<"required array\n";
    for(int i=0;i<=j;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}
