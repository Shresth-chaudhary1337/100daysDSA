#include<iostream>
#include<vector>
class missingArrayElement{
    public:
    int missingNumber(std::vector<int>&arr)
    {
        int size=arr.size();
        int expectedSum=0;
        int actualSum=0;
        for(int i=1;i<=size+1;i++){
            expectedSum+=i;
        }
        for(int i=0;i<size;i++){
            actualSum+=arr[i];
        }

        return (expectedSum-actualSum);
        
    }
};
int main(){
    int n;
    std::cout<<"enter the number of elements you wanna enter\n";
    std::cin>>n;
    std::vector<int> arr(n);

    std::cout<<"enter the elements: ";
    for(int i=0;i<n;i++)
    std::cin>>arr[i];

    missingArrayElement obj;
    int missing=obj.missingNumber(arr);

    std::cout<<"missing number= "<<missing<<std::endl;

    return 0;
}