#include<iostream>
#include<vector>
int main(){
    int n;
    std::cout<<"enter number of elements you want to enter in an array\n";
    std::cin>>n;
    std::vector<int> arr(n);
    std::cout<<"enter elements of array\n";

    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int key;
    std::cout<<"enter key to search in the array\n";
    std::cin>>key;
    
    int comparisons=0;

    int pos=-1;

    for(int i=0;i<n;i++){
        comparisons++;

        if(arr[i]==key)
        {
            pos=i;
            break;
        }
    }
    if(pos!=-1)
        std::cout<<"Found at index "<<pos<<'\n';
    else
    std::cout<<"not found\n";

    std::cout<<"comprisons "<<comparisons;
}