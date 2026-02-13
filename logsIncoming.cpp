/*
Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include<iostream>
#include<vector>

int main(){
    int p,q;

    std::cout<<"enter the number of entries of log 1 \n";
    std::cin>>p;
    std::vector<int> log1(p);
    std::cout<<"enter the number of entries of log 2 \n";
    std::cin>>q;
    std::vector<int> log2(q);

    std::cout<<"enter the entries of log 1\n";
    for(int i=0;i<p;i++){
        std::cin>>log1[i];
    }
    std::cout<<"enter the entries of log 2\n";
    for(int i=0;i<q;i++){
        std::cin>>log2[i];
    }
    int i=0,j=0;
    
    //comparing both logs
    while(i<p && j<q){
            if(log1[i]<log2[j]){
            std::cout<<log1[i]<<" ";
            i++;
        }
        else{
            std::cout<<log2[j]<<" ";
            j++;
        }   
}
//printing remaining elements of log1
    while(i<p){
        std::cout<<log1[i]<<" ";
        i++;
    }
    while(j<q){
        std::cout<<log2[j]<<" ";
        j++;
    }
}
