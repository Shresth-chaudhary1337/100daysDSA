/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(Node* &head, Node* &tail, int val) {
    Node* newNode = createNode(val);
    
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " ";
        }
        temp = temp->next;
    }
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n, val;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(head, tail, val);
    }
    
    printList(head);
    
    return 0;
}