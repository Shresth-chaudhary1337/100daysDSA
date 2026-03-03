/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/
#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    stackArr[top] = value;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << stackArr[top] << endl;
    top--;
}

void display() {
    if (top == -1) {
        return;
    }
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int type;
        cin >> type;

        if (type == 1) {
            int value;
            cin >> value;
            push(value);
        }
        else if (type == 2) {
            pop();
        }
        else if (type == 3) {
            display();
        }
    }

    return 0;
}