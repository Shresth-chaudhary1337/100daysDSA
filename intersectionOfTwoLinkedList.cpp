/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/
#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// create new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert at end
void insertEnd(Node*& head, Node* node) {
    if (head == NULL) {
        head = node;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
}

// find node by value (to create intersection)
Node* findNode(Node* head, int val) {
    while (head) {
        if (head->data == val)
            return head;
        head = head->next;
    }
    return NULL;
}

// find length
int length(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// find intersection point
Node* intersectionPoint(Node* head1, Node* head2) {
    int l1 = length(head1);
    int l2 = length(head2);

    int diff = abs(l1 - l2);

    if (l1 > l2)
        while (diff--) head1 = head1->next;
    else
        while (diff--) head2 = head2->next;

    while (head1 && head2) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    Node *head1 = NULL, *head2 = NULL;

    // first list
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head1, createNode(x));
    }

    // second list
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        Node* common = findNode(head1, x);
        if (common) {
            insertEnd(head2, common); // create intersection
            break;
        } else {
            insertEnd(head2, createNode(x));
        }
    }

    Node* result = intersectionPoint(head1, head2);

    if (result)
        cout << result->data;
    else
        cout << "No Intersection";

    return 0;
}