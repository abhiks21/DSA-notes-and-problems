/*
🔹 Problem:
Given the root of a binary tree, return all root-to-leaf paths as separate lists.

🔹 Example:
Input:
        1
       / \
      2   3
         /
        4
Output:
[
  [1, 2],
  [1, 3, 4]
]

🔹 Approach:
- Use DFS traversal (preorder) with a temporary path vector.
- Add node's value to current path.
- If it's a leaf, push current path into the answer.
- After exploring, backtrack by popping the last element.

🔹 Mistakes to Avoid:
- Not backtracking after recursive calls.
- Adding the path before confirming it's a leaf node.
- Not checking if root is NULL.

🔹 Time & Space Complexity:
Time: O(N) — visiting each node once.
Space:
  - O(H) recursion stack space where H = height of tree.
  - O(N * L) for storing result (N = nodes, L = path length).

🔹 Code:
*/

class Solution {
  public:
    // Helper function to perform DFS and record paths
    void solve(Node* root, vector<vector<int>>& ans, vector<int>& temp) {
        temp.push_back(root->data); // add current node to path

        // If leaf node, path is complete — add it to answer
        if (!root->left && !root->right) {
            ans.push_back(temp);
        } else {
            // Explore left subtree
            if (root->left) solve(root->left, ans, temp);

            // Explore right subtree
            if (root->right) solve(root->right, ans, temp);
        }

        temp.pop_back(); // backtrack to previous state
    }

    // Main function to be called with the tree root
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans; // final list of paths
        vector<int> temp; // temporary path
        if (root) solve(root, ans, temp); // trigger DFS if tree is not empty
        return ans;
    }
};
