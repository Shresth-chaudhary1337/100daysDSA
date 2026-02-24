/*
Remove Linked List Elements
Easy
Topics
premium lock iconCompanies

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

 

Constraints:

    The number of nodes in the list is in the range [0, 104].
    1 <= Node.val <= 50
    0 <= val <= 50

*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertAtEnd(ListNode* head, int val) {
    ListNode* node = new ListNode(val);

    if (head == NULL)
        return node;

    ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    return head;
}

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* curr = &dummy;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    int n, value, val;
    ListNode* head = NULL;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertAtEnd(head, value);
    }

    cin >> val;

    head = removeElements(head, val);
    printList(head);

    return 0;
}