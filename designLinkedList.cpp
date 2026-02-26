/*Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

    MyLinkedList() Initializes the MyLinkedList object.
    int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
    void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    void addAtTail(int val) Append a node of value val as the last element of the linked list.
    void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
    void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3

 

Constraints:

    0 <= index, val <= 1000
    Please do not use the built-in LinkedList library.
    At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

*/
#include <iostream>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* head;

public:
    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        Node* temp = head;
        int count = 0;

        while (temp != NULL) {
            if (count == index)
                return temp->val;
            temp = temp->next;
            count++;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        int count = 0;

        while (temp != NULL && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
            return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (head == NULL)
            return;

        if (index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        Node* temp = head;
        int count = 0;

        while (temp->next != NULL && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
            return;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Helper function to print list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    MyLinkedList list;

    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);   // 1 -> 2 -> 3
    list.printList();

    cout << "Value at index 1: " << list.get(1) << endl;

    list.deleteAtIndex(1);  // 1 -> 3
    list.printList();

    cout << "Value at index 1: " << list.get(1) << endl;

    return 0;
}