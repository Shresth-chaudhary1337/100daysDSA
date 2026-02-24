/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
*/
#include<iostream>
struct listNode{
    int data;
    struct listNode* next;
};

listNode* createNode(int n){
    listNode* newNode=new listNode();
    newNode->data=n;
    newNode->next=NULL;
    return newNode;
}
listNode* insertAtEnd(listNode* head,int data){
    listNode* newNode=createNode(data);

    if(head==NULL){
        return newNode;
    }
    listNode* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

listNode* deleteFirstOccurence(listNode *head,int key){
    if(head==NULL){
        return head;
    }

    if(head->data==key){
        listNode* temp=head;
        head=head->next;
        delete temp;
        return head;
        
    }
    listNode* curr =head;
    while(curr->next!=NULL && curr->next->data!=key){
        curr=curr->next;
    }
    if(curr->next!=NULL){
        listNode* temp=curr->next;
        curr->next=temp->next;
        delete temp;
    }
    return head;
}
void printList(listNode* head){
    listNode* temp=head;

    while(temp!=NULL){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    int n,value,key;
    listNode* head=NULL;
    std::cout<<"enter the number of nodes\n";
    std::cin>>n;

    for(int i=0;i<n;i++){
        std::cout<<"enter value\n";
        std::cin>>value;
        head=insertAtEnd(head,value);
    }

    std::cout<<"enter the key\n";
    std::cin>>key;

    head=deleteFirstOccurence(head,key);
    printList(head);
    return 0;
}
