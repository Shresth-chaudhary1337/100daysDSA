/*Lowest Common Ancestor of a Binary Search Tree
Medium
Topics
premium lock iconCompanies

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2

 

Constraints:

    The number of nodes in the tree is in the range [2, 105].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
    p and q will exist in the BST.

*/
#include <iostream>
using namespace std;

// Tree Node
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

// Insert into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (p < root->val && q < root->val)
        return lowestCommonAncestor(root->left, p, q);

    if (p > root->val && q > root->val)
        return lowestCommonAncestor(root->right, p, q);

    return root; // split point
}

int main() {
    TreeNode* root = NULL;
    int n, x, p, q;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Enter p and q: ";
    cin >> p >> q;

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        cout << "LCA: " << lca->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}
/*iterative version
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    while (root) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}*/