/*
d Two Numbers
Medium
Topics
premium lock iconCompanies

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* node = new Node;
    node->data = val;
    node->next = NULL;
    return node;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = createNode(0);
    Node* curr = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = createNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n, m;
    
    cout << "enter number of nodes in first list\n";
    cin >> n;

    Node* l1 = NULL;
    Node* tail1 = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "enter digit\n";
        cin >> x;

        Node* node = createNode(x);
        if (l1 == NULL) {
            l1 = node;
            tail1 = node;
        } else {
            tail1->next = node;
            tail1 = node;
        }
    }

    cout << "enter number of nodes in second list\n";
    cin >> m;

    Node* l2 = NULL;
    Node* tail2 = NULL;

    for (int i = 0; i < m; i++) {
        int x;
        cout << "enter digit\n";
        cin >> x;

        Node* node = createNode(x);
        if (l2 == NULL) {
            l2 = node;
            tail2 = node;
        } else {
            tail2->next = node;
            tail2 = node;
        }
    }

    Node* result = addTwoNumbers(l1, l2);

    cout << "sum list\n";
    printList(result);

    return 0;
}