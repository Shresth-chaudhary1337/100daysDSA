/*
Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/
#include<iostream>
class power{
    public:
    int raisePower(int a,int b)
    {
        if(b==0){
            return 1;
        }
        else{
            return a*raisePower(a,b-1);
        }

    }
};
int main(){
    int a,b;
    std::cout<<"enter number and power respectively to which it is raise\n";
    std::cin>>a>>b;

    power obj;
    std::cout<<a<<"^"<<b<<"= "<<obj.raisePower(a,b);
}