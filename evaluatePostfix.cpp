/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/
#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// push function
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// pop function
int pop() {
    if (top == NULL) {
        cout << "Stack Underflow";
        return -1;
    }
    
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    getline(cin, exp);

    stringstream ss(exp);
    string token;

    while (ss >> token) {

        // if operand
        if (isdigit(token[0])) {
            push(stoi(token));
        }
        else {
            int b = pop();
            int a = pop();
            int result;

            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/")
                result = a / b;

            push(result);
        }
    }

    cout << "Result = " << pop();

    return 0;
}