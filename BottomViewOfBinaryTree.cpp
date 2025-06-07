// 🔰 Problem: Bottom View of Binary Tree

/*
Given a binary tree, return the bottom view of the tree from left to right.

The bottom view contains the nodes that are visible when the tree is viewed from the bottom.
For each horizontal distance (column), only the **last (bottom-most)** node is considered.
*/

// ✅ Approach:

/*
1. Use **Level Order Traversal (BFS)** to traverse the tree.
2. For each node, track its **column index** (horizontal distance from root).
3. Use a **map<int, int> colToValue** to store the bottom-most node at each column.
   - Since we use BFS, the last node seen at each column will naturally be the bottom one.
4. Traverse left child with column - 1, right child with column + 1.
5. After traversal, extract values from the map in sorted order of column.
*/

// ✅ Code:

class Solution {
  public:
    void solve(Node* root, map<int, int>& mp) {
        if (!root) return;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
            
            // Update value at current column
            mp[col] = node->data;
            
            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }
    }

    vector<int> bottomView(Node* root) {
        map<int, int> mp;              // column -> value
        vector<int> ans;
        
        solve(root, mp);
        
        for (auto& [col, val] : mp) {
            ans.push_back(val);
        }
        
        return ans;
    }
};



// ⏱️ Time Complexity: O(N)
// - Each node is visited once during BFS

// 📦 Space Complexity: O(N)
// - Map to store column to node values
// - Queue for level order traversal

// 🚫 Common Mistakes:
// - Using DFS (won’t guarantee bottom-most node unless depth is tracked)
// - Including duplicate values for the same column
// - Not traversing in level order

