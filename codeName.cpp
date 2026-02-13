/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/
#include<iostream>
#include<string>
class codeName{
    public:
    std::string mirrorOperation(std::string &code){

        int start=0;
        int end=code.length()-1;
        while(start<end){
            char temp;
            temp=code[start];
            code[start]=code[end];
            code[end]=temp;
            start++;
            end--;
        }
        return code;
    }
};
int main(){
    std::string code;
    std::cout<<"enter the name\n";
    std::getline(std::cin,code);

    codeName obj;
    std::cout<<"codename = "<<obj.mirrorOperation(code);
}