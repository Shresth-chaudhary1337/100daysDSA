/* Search in a Binary Search Tree
Easy
Topics
premium lock iconCompanies

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:

Input: root = [4,2,7,1,3], val = 5
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [1, 5000].
    1 <= Node.val <= 107
    root is a binary search tree.
    1 <= val <= 107

*/
#include <iostream>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST (to build tree)
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// Inorder traversal (to print subtree)
void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;
    int n, x, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Enter value to search: ";
    cin >> val;

    TreeNode* result = searchBST(root, val);

    if (result == NULL) {
        cout << "Value not found (NULL)" << endl;
    } else {
        cout << "Subtree (inorder): ";
        inorder(result);
        cout << endl;
    }

    return 0;
}