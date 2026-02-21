/*
Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
*/
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int main(){
        int n,value;
        Node *head=NULL,*temp=NULL,*newNode=NULL;
        cout<<"enter the number of nodes\n";
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"enter value\n";
            cin>>value;
            newNode= new Node;
            newNode->data=value;
            newNode->next=NULL;

            if(head==NULL){
                head=newNode;
                temp=head;
            }
            else{
                temp->next=newNode;
                temp=newNode;
            }
        }
        //traversing and printing the linked list
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        return 0;
        
}