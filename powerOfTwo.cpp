#include<iostream>
class powerOfTwo{
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        return false;
        return (n & (n-1))==0;
    }
};
int main()
{
    int n;
    std::cout<<"enter the number \n";
    std::cin>>n;

    powerOfTwo obj;
    std::cout<<(obj.isPowerOfTwo(n)?"true":"false");

}