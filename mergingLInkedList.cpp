/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

#include <iostream>
using namespace std;

// Definition of linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Inserting node at end
ListNode* insertEnd(ListNode* head, int val) {
    ListNode* node = new ListNode(val);

    if (head == NULL)
        return node;

    ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    return head;
}

// Merging two sorted lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);

    ListNode* tail = &dummy;//to avoid dummy we can use the following code
    /*if (head == NULL) {
    head = temp;
    tail = temp;
} else {
    tail->next = temp;
    tail = temp;
}*/

    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    int n, m, x;
    ListNode* list1 = NULL;
    ListNode* list2 = NULL;

    // Input first list
    cout<<"enter the nodes of the first list\n";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        list1 = insertEnd(list1, x);
    }

    cout<<"enter the number of nodes of second list\n";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        list2 = insertEnd(list2, x);
    }

    ListNode* merged = mergeTwoLists(list1, list2);

    printList(merged);

    return 0;
}
