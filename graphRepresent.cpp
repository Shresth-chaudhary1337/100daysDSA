/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Node*> adj(n, NULL);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // add v to u's list
        Node* newNode1 = new Node(v);
        newNode1->next = adj[u];
        adj[u] = newNode1;

        // add u to v's list (undirected)
        Node* newNode2 = new Node(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    // print adjacency list
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        Node* temp = adj[i];
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}