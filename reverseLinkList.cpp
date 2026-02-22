/*Given the head of a singly linked list, reverse the list, and return the reversed list.*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};


ListNode* createList(int n) {
    ListNode *head = nullptr, *tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        ListNode* newNode = new ListNode();
        newNode->val = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head, *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    ListNode* head = createList(n);

    cout << "Original list: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}