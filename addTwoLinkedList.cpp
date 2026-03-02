/*Add Two Numbers II
Medium
Topics
premium lock iconCompanies

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]

 */
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* createNode(int x) {
    ListNode* node = new ListNode();
    node->val = x;
    node->next = NULL;
    return node;
}

void insertEnd(ListNode*& head, int x) {
    ListNode* node = createNode(x);

    if (head == NULL) {
        head = node;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;

    while (l1 != NULL) {
        s1.push(l1->val);
        l1 = l1->next;
    }

    while (l2 != NULL) {
        s2.push(l2->val);
        l2 = l2->next;
    }

    int carry = 0;
    ListNode* head = NULL;

    while (!s1.empty() || !s2.empty() || carry) {
        int sum = carry;

        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }

        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }

        carry = sum / 10;
        ListNode* node = createNode(sum % 10);
        node->next = head;
        head = node;
    }

    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
}

int main() {
    int n, m;
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertEnd(l1, x);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        insertEnd(l2, x);
    }

    ListNode* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}