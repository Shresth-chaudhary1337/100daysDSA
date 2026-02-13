#include<iostream>
class Solution {
public:
    int fib(int n) {
        if(n<=1)
        return n;
        
        int a=0,b=1,c;
        for (int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;

        }
        return c;
    }
    
};
int main(){
    int n;
    std::cout<<"enter the value of term of which value you want\n";
    std::cin>>n;

    Solution obj;
    std::cout<<"#"<<n<<" term = "<<obj.fib(n);
}