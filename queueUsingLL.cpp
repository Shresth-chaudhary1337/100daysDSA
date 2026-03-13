/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << -1 << endl;
            return;
        }

        Node* temp = front;
        cout << temp->data << endl;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }
};

int main() {
    int N;
    cin >> N;

    Queue q;

    while (N--) {
        string op;
        cin >> op;

        if (op == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if (op == "dequeue") {
            q.dequeue();
        }
    }

    return 0;
}