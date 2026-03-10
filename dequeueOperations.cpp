/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/
#include <iostream>
#include <deque>
using namespace std;

int main() {

    deque<int> dq;
    int choice, value;

    while(true) {

        cout << "\nMenu\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at rear\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from rear\n";
        cout << "5. Show front element\n";
        cout << "6. Show rear element\n";
        cout << "7. Show size\n";
        cout << "8. Check if deque is empty\n";
        cout << "9. Display deque\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            dq.push_front(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            dq.push_back(value);
            break;

        case 3:
            if(!dq.empty()) {
                dq.pop_front();
                cout << "Element removed from front\n";
            }
            else
                cout << "Deque is empty\n";
            break;

        case 4:
            if(!dq.empty()) {
                dq.pop_back();
                cout << "Element removed from rear\n";
            }
            else
                cout << "Deque is empty\n";
            break;

        case 5:
            if(!dq.empty())
                cout << "Front element: " << dq.front() << endl;
            else
                cout << "Deque is empty\n";
            break;

        case 6:
            if(!dq.empty())
                cout << "Rear element: " << dq.back() << endl;
            else
                cout << "Deque is empty\n";
            break;

        case 7:
            cout << "Size of deque: " << dq.size() << endl;
            break;

        case 8:
            if(dq.empty())
                cout << "Deque is empty\n";
            else
                cout << "Deque is not empty\n";
            break;

        case 9:
            cout << "Elements in deque: ";
            for(int x : dq)
                cout << x << " ";
            cout << endl;
            break;

        case 0:
            cout << "Program ended\n";
            return 0;

        default:
            cout << "Wrong choice\n";
        }
    }
}