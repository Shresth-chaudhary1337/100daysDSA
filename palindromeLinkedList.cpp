/*Given the head of a singly linked list, return true if it is a or false otherwise.

 

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

 

Constraints:

    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

 
Follow up: Could you do it in O(n) time and O(1) space?*/
#include <iostream>
using namespace std;

// Definition of node
struct ListNode {
    int val;
    ListNode* next;
};

// Create new node
ListNode* createNode(int val) {
    ListNode* newNode = new ListNode();
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Reverse linked list
ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head;

    while (curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Check palindrome
bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    // Find middle
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* secondHalf = reverseList(slow);

    // Compare both halves
    ListNode* firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    int n, x;
    cin >> n;

    ListNode *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;
        ListNode* node = createNode(x);

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    if (isPalindrome(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}