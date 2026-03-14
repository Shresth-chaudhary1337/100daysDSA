/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n, x;
    cin >> n;

    queue<int> q;
    stack<int> s;

    // Input queue elements
    for(int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    // Step 1: Move queue elements to stack
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Move stack elements back to queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Print reversed queue
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}