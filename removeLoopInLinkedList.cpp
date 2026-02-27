/*Remove loop in Linked List
Difficulty: MediumAccuracy: 27.66%Submissions: 550K+Points: 4Average Time: 45m

Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's 
next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes
 the index of the node where the cycle starts, but it is not passed as a parameter.
 The terminal will print true if a cycle is removed otherwise, it will print false.*/
 #include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    void removeLoop(Node* head) {
        if (head == NULL || head->next == NULL)
            return;

        Node* slow = head;
        Node* fast = head;

        // Detect loop
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No loop
        if (slow != fast)
            return;

        // Find start of loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove loop
        Node* temp = slow;
        while (temp->next != slow) {
            temp = temp->next;
        }
        temp->next = NULL;
    }
};

// Helper function to print list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Creating list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Creating loop: 4 -> 2
    head->next->next->next->next = head->next;

    Solution obj;
    obj.removeLoop(head);

    // Print after removing loop
    printList(head);

    return 0;
}