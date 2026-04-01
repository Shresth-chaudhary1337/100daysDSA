/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// check CBT
bool isCBT(Node* root) {
    queue<Node*> q;
    q.push(root);
    
    bool nullSeen = false;
    
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL) {
            nullSeen = true;
        } else {
            if(nullSeen) return false;
            
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return true;
}

// check heap property
bool isMinHeap(Node* root) {
    if(root == NULL) return true;
    
    if(root->left) {
        if(root->data > root->left->data) return false;
    }
    
    if(root->right) {
        if(root->data > root->right->data) return false;
    }
    
    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    // build tree from level order
    vector<Node*> nodes(n);
    for(int i = 0; i < n; i++) {
        nodes[i] = new Node(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(2*i + 1 < n) nodes[i]->left = nodes[2*i + 1];
        if(2*i + 2 < n) nodes[i]->right = nodes[2*i + 2];
    }

    Node* root = nodes[0];

    if(isCBT(root) && isMinHeap(root)) cout << "YES";
    else cout << "NO";
}