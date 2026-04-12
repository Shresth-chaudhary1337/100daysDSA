/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    vector<int> table;
    int m;

public:
    HashTable(int size) {
        m = size;
        table.assign(m, -1);
    }

    void insert(int key) {
        int h = key % m;

        for (int i = 0; i < m; i++) {
            int idx = (h + i * i) % m;

            if (table[idx] == -1) {
                table[idx] = key;
                return;
            }
        }
    }

    bool search(int key) {
        int h = key % m;

        for (int i = 0; i < m; i++) {
            int idx = (h + i * i) % m;

            if (table[idx] == -1)
                return false;

            if (table[idx] == key)
                return true;
        }
        return false;
    }
};

int main() {
    int m, q;
    cin >> m >> q;

    HashTable ht(m);

    while (q--) {
        string op;
        int key;
        cin >> op >> key;

        if (op == "INSERT") {
            ht.insert(key);
        } else if (op == "SEARCH") {
            if (ht.search(key))
                cout << "FOUND\n";
            else
                cout << "NOT FOUND\n";
        }
    }
}