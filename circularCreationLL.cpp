/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/
#include<iostream>

struct Node{
    int data;
    Node* next;
};
int main() {
    int n,value;
    Node *head=NULL,*temp=NULL,*newNode=NULL;
    std::cout<<"enter the number of nodes you want\n";
    std::cin>>n;

    for(int i=0;i<n;i++){
        std::cout<<"enter the value\n";
        std::cin>>value;

        newNode=new Node();
        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else{
            temp->next=newNode;//jha prr temp hai wha prr naye node ka address store krna
            temp=newNode;//fir temp ko traverse krna
        }
    }
    //make the list circular
    temp->next=head;

    //traversing circular linked list
    temp=head;
    if(head!=NULL){
        do{
            std::cout<<temp->data<<" ";
            temp=temp->next;

        }while(temp!=head);
    }
    return 0;

}