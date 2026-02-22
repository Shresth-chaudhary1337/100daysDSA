/*
Problem: Count Nodes in Linked List

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
struct Node{
    int data;
    Node *next;
};
Node* createList(int n){
    Node *head=NULL,*temp=NULL,*newNode=NULL;
    //newNode=(struct Node*)malloc(sizeof(struct Node)); used in c
    Node* newNode=new Node;
    int value;
    for(int i=0;i<n;i++){
        std::cout<<"enter  the value\n";
        std::cin>>value;

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
    return head;
}
int countNodes(Node* head){
    int count=0;
    Node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;

}
int main(){
    int n;
    std::cout<<"enter the value of n\n";
    std::cin>>n;
    Node* head=createList(n);
    int result=countNodes(head);
    std::cout<<"number of node= "<<result;
}