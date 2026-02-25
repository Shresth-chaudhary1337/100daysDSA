/*Linked List Cycle II
Medium
Topics
premium lock iconCompanies

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

 

Constraints:

    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.

 

Follow up: Can you solve it using O(1) (i.e. constant) memory
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

int main() {
    int n, pos;
    cin >> n;

    if (n == 0) {
        cout << "no cycle";
        return 0;
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* cycleNode = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* node = new ListNode();
        node->val = x;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        // Store node where cycle should start
        if (i == pos) {
            cycleNode = node;
        }
    }

    // Connect tail to cycle position
    cin >> pos;
    if (pos != -1) {
        tail->next = cycleNode;
    }

    // Floyd’s cycle detection
    ListNode* slow = head;
    ListNode* fast = head;
    bool hasCycle = false;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle) {
        cout << "no cycle";
        return 0;
    }

    // Find cycle starting node
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    cout << "tail connects to node with value " << slow->val;
    return 0;
}