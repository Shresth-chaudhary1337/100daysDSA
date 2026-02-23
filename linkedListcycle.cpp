/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

 

Constraints:

    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.

 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

// Create linked list and optionally create a cycle
ListNode* createList(int n, int pos) {
    if (n == 0) return NULL;

    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* tail = head;
    ListNode* cycleNode = NULL;

    if (pos == 0)
        cycleNode = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;

        if (i == pos)
            cycleNode = tail;
    }

    // create cycle if pos != -1
    if (pos != -1)
        tail->next = cycleNode;

    return head;
}

// Detect cycle using Floyd’s Algorithm
bool hasCycle(ListNode* head) {
    if (head == NULL)
        return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    int n, pos;
    cin >> n >> pos;

    ListNode* head = createList(n, pos);

    if (hasCycle(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}