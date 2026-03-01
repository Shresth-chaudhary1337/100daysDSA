/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int val){
    Node* node=new Node;
    node->data=val;
    node->next=NULL;
    return node;
}
Node* rotateRight(Node* head,int k){
    if(head==NULL||head->next==NULL||k==0)
    return head;

    int len=1;
    Node* tail=head;

    while(tail->next!=NULL){
        len++;
        tail=tail->next;
    }
    k=k%len;

    if(k==0)
    return head;

    //making list circular
    tail->next=head;

    //find new tail(len-k)th node
    Node* newTail=head;

    for(int i=1;i<len-k;i++){
        newTail=newTail->next;
    }
    Node* newHead=newTail->next;
    newTail->next=NULL;

    return newHead;
}
void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    int n;
    cout<<"enter the number of nodes you want\n";
    cin>>n;
    Node* head=NULL;
    Node* tail=NULL;
    for(int i=0;i<n;i++){
        int x;
        cout<<"enter the data\n";
        cin>>x;
        Node* node=createNode(x);

        if(head==NULL){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }
    cout<<"enter number of rotations\n";
    int k;
    cin>>k;
    head=rotateRight(head,k);
    printList(head);
    return 0;
}