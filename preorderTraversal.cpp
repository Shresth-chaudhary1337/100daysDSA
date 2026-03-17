/*
Binary Tree Preorder Traversal
Easy
Topics
premium lock iconCompanies

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:

Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:

Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

 

Follow up: Recursive solution is trivial, could you do it iteratively?
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

// build tree from level order
TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        TreeNode* curr = q.front();
        q.pop();

        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i >= n) break;

        if (arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// custom stack
class Stack {
public:
    TreeNode* arr[100];
    int top;

    Stack() {
        top = -1;
    }

    void push(TreeNode* x) {
        arr[++top] = x;
    }

    void pop() {
        if (top >= 0) top--;
    }

    TreeNode* peek() {
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};

// preorder traversal (iterative)
void preorder(TreeNode* root) {
    if (!root) return;

    Stack st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* curr = st.peek();
        st.pop();

        cout << curr->val << " ";

        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    TreeNode* root = buildTree(arr, n);

    preorder(root);

    return 0;
}