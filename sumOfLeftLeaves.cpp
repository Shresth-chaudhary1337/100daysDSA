/*Sum of Left Leaves
Easy
Topics
premium lock iconCompanies

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:

Input: root = [1]
Output: 0

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    -1000 <= Node.val <= 1000

*/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// build tree from level order (-1 = NULL)
TreeNode* build(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (i < n) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < n && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// sum of left leaves
int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    if (root->left) {
        // if left child is a leaf
        if (root->left->left == NULL && root->left->right == NULL)
            sum += root->left->val;
        else
            sum += sumOfLeftLeaves(root->left);
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = build(arr, n);

    cout << sumOfLeftLeaves(root);

    return 0;
}