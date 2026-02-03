#include<iostream>
int main(){
    int n; //to store number of elements of array
    std::cout<<"enter number of elements you want to enter in an array\n";
    std::cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        std::cout<<"enter #"<<i+1<<" element\n";
        std::cin>>array[i];
    }
    std::cout<<"enter the target \n";
    int target;
    std::cin>>target;
    //loop to find index positions
    int found = 0;

for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++)
    {
        if(array[i]+array[j]==target){
            std::cout<<"indices are "<<i<<" "<<j;
            found = 1;
            break;
        }
    }
    if(found) break;
}

if(found==0)
    std::cout<<"entered target cannot be acquired from the sum of any two elements in the array";

}