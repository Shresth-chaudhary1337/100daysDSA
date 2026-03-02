/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.
*/
#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

Node* createNode(int c, int e) {
    Node* node = new Node();
    node->coeff = c;
    node->exp = e;
    node->next = NULL;
    return node;
}

void insertEnd(Node*& head, int c, int e) {
    Node* node = createNode(c, e);

    if (head == NULL) {
        head = node;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void printPolynomial(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->coeff;

        if (temp->exp > 0) {
            cout << "x";
            if (temp->exp > 1) {
                cout << "^" << temp->exp;
            }
        }

        if (temp->next != NULL) {
            cout << " + ";
        }

        temp = temp->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        cin >> c >> e;
        insertEnd(head, c, e);
    }

    printPolynomial(head);
    return 0;
}