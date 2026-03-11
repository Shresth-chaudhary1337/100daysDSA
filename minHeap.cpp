/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

public:

    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;

        // Heapify Up
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    int peek() {
        if (heap.empty())
            return -1;
        return heap[0];
    }

    int extractMin() {
        if (heap.empty())
            return -1;

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;
        int size = heap.size();

        // Heapify Down
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int smallest = i;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;

            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else {
                break;
            }
        }

        return minVal;
    }
};

int main() {
    int N;
    cin >> N;

    MinHeap h;

    while (N--) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            h.insert(x);
        }
        else if (op == "peek") {
            cout << h.peek() << endl;
        }
        else if (op == "extractMin") {
            cout << h.extractMin() << endl;
        }
    }

    return 0;
}
