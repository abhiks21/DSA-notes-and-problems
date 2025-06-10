/* 
-----------------------------------
🟩 Problem:
Given the `root` of a binary tree, return the maximum width of the given tree.

The **maximum width** of a level is defined as the length between the end-nodes 
(the leftmost and rightmost non-null nodes), even if there are null nodes in between.

-----------------------------------
🧠 Example:
Input: 
        1
       / \
      3   2
     /     \ 
    5       9
   /         \
  6           7

Output: 8

Explanation:
The last level has width = 2^3 = 8 due to complete binary tree indexing.

-----------------------------------
🛠️ Approach 1: Using BFS with Index Normalization (Optimal)

🔹 Assign an index to each node based on complete binary tree rules:
    - root = 0
    - left child = 2 * idx + 1
    - right child = 2 * idx + 2

🔹 At each level:
    - Store the first and last node's index (after normalization by subtracting min index)
    - Width = last - first + 1
    - Track max width over all levels

🔹 Normalize indices every level to avoid overflow.

-----------------------------------
⚠️ Mistakes to Avoid:
- Not normalizing indices → may cause overflow in deep trees.
- Using signed int for indices → can cause incorrect width.

-----------------------------------
🕒 Time Complexity: O(n)
Each node is visited once in level-order traversal.

📦 Space Complexity: O(n)
Queue stores at most one level's nodes.

-----------------------------------
✅ Code with Inline Comments:
*/

class Solution {
public:
    typedef unsigned long long ll;

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        ll maxWidth = 0;

        // Queue stores pair of node and its index
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            ll minIdx = q.front().second; // to normalize indices
            ll first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front(); q.pop();
                idx -= minIdx; // normalize to prevent overflow

                if (i == 0) first = idx; // first index of this level
                if (i == size - 1) last = idx; // last index of this level

                if (node->left) q.push({node->left, 2 * idx + 1});
                if (node->right) q.push({node->right, 2 * idx + 2});
            }

            maxWidth = max(maxWidth, last - first + 1); // update max width
        }

        return maxWidth;
    }
};

