#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return st.top();
    }

    int getMin() {
        if (minSt.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minSt.top();
    }
};

int main() {
    MinStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Top element: " << s.top() << endl;
    cout << "Minimum element: " << s.getMin() << endl;

    s.pop();

    cout << "Top after pop: " << s.top() << endl;
    cout << "Minimum after pop: " << s.getMin() << endl;

    return 0;
}