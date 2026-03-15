/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to build tree from level order
Node* buildTree(vector<int> &arr) {

    if(arr.size() == 0 || arr[0] == -1)
        return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()) {

        Node* curr = q.front();
        q.pop();

        // Left child
        if(arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if(i >= arr.size())
            break;

        // Right child
        if(arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    int N;
    cin >> N;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    Node* root = buildTree(arr);

    inorder(root);

    return 0;
}