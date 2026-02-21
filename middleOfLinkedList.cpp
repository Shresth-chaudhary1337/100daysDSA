/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/
#include<iostream>
struct Node{
    int data;
    Node* next;
};

Node* createList(int n){
    Node *head=NULL,*temp=NULL,*newNode=NULL;
    int value;
    
    for(int i=0;i<n;i++){
        std::cout<<"enter the value\n";
        std::cin>>value;

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
    return head;
}
//function to return the middle node
Node* findNode(Node* head){
        Node* slow=head;
        Node* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
}
int main(){
    int n;
    std::cout<<"enter the number of node\n";
    std::cin>>n;

    Node* head=createList(n);
    Node* middle =findNode(head);
    std::cout<<"middle node= "<<middle->data;
    std::cout<<"Node from Middle node data:- ";
    while(middle!=NULL){     
    std::cout<<middle->data<<" ";
    middle=middle->next;
    
}
return 0;
}