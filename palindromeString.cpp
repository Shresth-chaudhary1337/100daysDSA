/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include<iostream>
#include<string>
class palindromeCheck{
    public:

    bool isPalindrome(std::string s){
        int left=0;
        int right=s.length()-1;
        while(left<right){
            if(s[left]!=s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

};
int main(){
    std::string s;
    std::cout<<"enter the string\n";
    std::cin>>s;

    palindromeCheck obj;
    if(obj.isPalindrome(s))
    std::cout<<"yes";
    else
    std::cout<<"no";
}