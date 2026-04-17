/*Clone Graph
Medium
Topics
premium lock icon
Companies
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int _val) {
        val = _val;
    }
};

unordered_map<Node*, Node*> mp;

Node* dfs(Node* node) {
    if (mp.find(node) != mp.end())
        return mp[node];

    Node* copy = new Node(node->val);
    mp[node] = copy;

    for (auto nbr : node->neighbors) {
        copy->neighbors.push_back(dfs(nbr));
    }

    return copy;
}

Node* cloneGraph(Node* node) {
    if (node == NULL) return NULL;
    return dfs(node);
}

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes(n + 1);

    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    cin.ignore();

    // input adjacency list
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        int x;
        while (ss >> x) {
            nodes[i]->neighbors.push_back(nodes[x]);
        }
    }

    Node* cloned = cloneGraph(nodes[1]);

    // print cloned graph
    unordered_set<int> vis;
    queue<Node*> q;
    q.push(cloned);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (vis.count(curr->val)) continue;
        vis.insert(curr->val);

        cout << curr->val << ": ";
        for (auto nbr : curr->neighbors) {
            cout << nbr->val << " ";
            q.push(nbr);
        }
        cout << endl;
    }

    return 0;
}