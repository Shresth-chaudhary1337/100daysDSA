/*
Binary Tree Inorder Traversal
Easy
Topics
premium lock iconCompanies

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:

Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:

Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]*/
#include <iostream>
using namespace std;

// Structure for tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};

// Inorder Traversal Function
void inorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);   // Visit Left
    cout << root->val << " ";       // Visit Root
    inorderTraversal(root->right);  // Visit Right
}

int main() {

    // Creating the tree
    // Example: [1,null,2,3]

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);

    return 0;
}