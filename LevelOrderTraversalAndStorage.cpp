/*
🔷 Problem:
Perform Level Order Traversal of a Binary Tree — return a 2D vector where each inner vector represents one level of the tree.

📥 Input:
      1
     / \
    2   3
   / \
  4   5

📤 Output:
[
  [1],
  [2, 3],
  [4, 5]
]

----------------------------------------

🔧 Approach (Breadth-First Search - BFS):
1. Use a queue to traverse nodes level by level.
2. For each level:
   - Get the number of nodes (queue size).
   - Process all nodes at that level.
   - Push their children (left & right) into the queue.
3. Store values level-wise into a result vector.

----------------------------------------

✅ Code:
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;  // Edge case: empty tree

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();           // Number of nodes at current level
            ans.emplace_back();          // Create empty vector for this level

            while (sz--) {
                Node* curr = q.front(); 
                q.pop();

                ans.back().push_back(curr->data);  // Add current node to level

                if (curr->left) q.push(curr->left);    // Left child
                if (curr->right) q.push(curr->right);  // Right child
            }
        }

        return ans;
    }
};

/*
🕒 Time Complexity: O(N)
- Every node is visited exactly once.

📦 Space Complexity: O(W)
- W = maximum width of the tree (queue and output storage).
*/
