#include<iostream>
#include<vector>
#include<string>
class reverseCharArray {
public:
    void reverseString(std::vector<char>& s) {
        
        int start=0;
        int end=s.size()-1;
        char temp;
        while(start<end){
            temp=s[start];
            s[start]=s[end];
            s[end]=temp;
            start++;
            end--;
        }
    }
};
int main(){
    std::string string;
    std::cout<<"enter string\n";
    std::cin>>string;

    std::vector<char> s(string.length());
    /* function based conversion- \convert
     string → vector<char>
    vector<char> s(input.begin(), input.end());
    */
    for(int i=0;i<string.length();i++){
        s[i]=string[i];
    }

    reverseCharArray obj;
    obj.reverseString(s);
    std::cout<<"reverse:-\n";
    for(int i=0;i<s.size();i++)
    std::cout<<s[i];

}