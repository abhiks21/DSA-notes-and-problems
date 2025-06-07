/*
🟩 Problem: Vertical Order Traversal of a Binary Tree (Leetcode 987)

🔸 Description:
Given a binary tree, return the vertical order traversal of its nodes' values.
Nodes that are in the same row and column should be ordered first by row, then by value.

--------------------------------------------------

🧠 Approach: DFS + (col → vector of (row, val)) + sorting

1. Do DFS traversal of the tree.
2. For each node, track:
   - its `row` (depth)
   - its `col` (horizontal position)
3. Use a `map<int, vector<pair<int, int>>>`:
   - key → column number
   - value → list of (row, val) pairs
4. After DFS traversal:
   - For each column:
     - Sort the vector of pairs by: row first, then value.
     - Extract values to build the final answer.

--------------------------------------------------

❌ Common Mistakes:
- Only tracking column and ignoring row (fails when multiple nodes are at same position).
- Not sorting nodes within the same position by value.
- Using just a map of column → vector<val> (won’t work when multiple nodes share the same row and col).

--------------------------------------------------

✅ Code:*/
class Solution {
public:
    void solve(TreeNode* root, int row, int col, map<int, vector<pair<int,int>>> &colmp){
        if(!root) return;

        colmp[col].push_back({row, root->val});
        solve(root->left, row+1, col-1, colmp);
        solve(root->right, row+1, col+1, colmp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> colmp;
        solve(root, 0, 0, colmp);

        vector<vector<int>> ans;
        for(auto &[col, pairs] : colmp){
            sort(pairs.begin(), pairs.end()); // sort by row, then val
            vector<int> colVals;
            for(auto &[row, val] : pairs){
                colVals.push_back(val);
            }
            ans.push_back(colVals);
        }
        return ans;
    }
};
/*
--------------------------------------------------

⏱️ Time Complexity:
- DFS traversal: O(n)
- Sorting each column: O(k log k) where k = number of nodes in that column
- Overall: O(n log n) in worst case

📦 Space Complexity:
- O(n) for storing all nodes in the map
- O(h) for recursion stack (h = height of tree)

--------------------------------------------------

📌 Notes:
- This is a clean and optimal solution for the problem.
- Works well within constraints (n ≤ 10⁴).
- Can be replaced with BFS + multiset/min-heap for a queue-based level-order version.

*/
