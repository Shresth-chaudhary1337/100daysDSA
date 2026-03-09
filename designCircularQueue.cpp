/*Design Circular Deque
Medium
Topics
premium lock iconCompanies

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

    MyCircularDeque(int k) Initializes the deque with a maximum size of k.
    boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
    int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
    int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
    boolean isEmpty() Returns true if the deque is empty, or false otherwise.
    boolean isFull() Returns true if the deque is full, or false otherwise.

 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4*/
#include <iostream>
using namespace std;

class MyCircularDeque {
    int *arr;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        arr = new int[k];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + capacity) % capacity;

        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % capacity;

        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        if (size == 1)
            front = rear = -1;
        else
            front = (front + 1) % capacity;

        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (size == 1)
            front = rear = -1;
        else
            rear = (rear - 1 + capacity) % capacity;

        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularDeque dq(3);

    cout << dq.insertLast(1) << endl;
    cout << dq.insertLast(2) << endl;
    cout << dq.insertFront(3) << endl;
    cout << dq.insertFront(4) << endl;
    cout << dq.getRear() << endl;
    cout << dq.isFull() << endl;
    cout << dq.deleteLast() << endl;
    cout << dq.insertFront(4) << endl;
    cout << dq.getFront() << endl;

    return 0;
}