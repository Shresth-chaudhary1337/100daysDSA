/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.\
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty())
        return NULL;

    int rootVal = preorder[0];
    Node* root = new Node(rootVal);

    int mid = 0;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == rootVal) {
            mid = i;
            break;
        }
    }

    vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
    vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

    vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftIn.size());
    vector<int> rightPre(preorder.begin() + 1 + leftIn.size(), preorder.end());

    root->left = buildTree(leftPre, leftIn);
    root->right = buildTree(rightPre, rightIn);

    return root;
}

void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);

    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    Node* root = buildTree(preorder, inorder);

    postorder(root);

    return 0;
}