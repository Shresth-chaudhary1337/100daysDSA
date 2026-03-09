/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int pq[100];
    int size = 0;
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if(op == "insert") {
            int x;
            cin >> x;
            pq[size] = x;
            size++;
        }

        else if(op == "delete") {
            if(size == 0) {
                cout << -1 << endl;
                continue;
            }

            int minIndex = 0;
            for(int j = 1; j < size; j++) {
                if(pq[j] < pq[minIndex]) {
                    minIndex = j;
                }
            }

            cout << pq[minIndex] << endl;

            for(int j = minIndex; j < size - 1; j++) {
                pq[j] = pq[j + 1];
            }

            size--;
        }

        else if(op == "peek") {
            if(size == 0) {
                cout << -1 << endl;
                continue;
            }

            int minValue = pq[0];
            for(int j = 1; j < size; j++) {
                if(pq[j] < minValue) {
                    minValue = pq[j];
                }
            }

            cout << minValue << endl;
        }
    }

    return 0;
}