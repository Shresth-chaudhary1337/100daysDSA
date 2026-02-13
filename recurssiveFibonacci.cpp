/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6*/
#include<iostream>
class fibonacci{
    public:
    int fibonacciNumber(int n){
        if(n==0)
        return 0;
        if(n==1)
        return 1;

        else{
            return fibonacciNumber(n-1)+fibonacciNumber(n-2);
        }
    }
};
int main(){
    int n;
    std::cout<<"enter the value of term of which value you want\n";
    std::cin>>n;

    fibonacci obj;
    std::cout<<"#"<<n<<" term= "<<obj.fibonacciNumber(n);


}