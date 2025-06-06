/*
🔷 Problem: Zigzag (Spiral) Level Order Traversal of Binary Tree

📘 Description:
- Traverse the binary tree level-by-level, but alternate the direction:
  → First level: Left to Right
  → Second level: Right to Left
  → Third level: Left to Right, and so on...

----------------------------------------

🔧 Approach: Two Stack Method

🛠️ Logic:
- Use two stacks: `s1` for left-to-right, `s2` for right-to-left.
- Process all nodes in `s1`, pushing their children into `s2` in **left-to-right** order.
- Then process all nodes in `s2`, pushing their children into `s1` in **right-to-left** order.
- This alternates traversal direction naturally across levels.

----------------------------------------

✅ Code:
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        stack<TreeNode*> s1; // For left to right
        stack<TreeNode*> s2; // For right to left
        vector<vector<int>> ans;

        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            vector<int> temp;

            // Left to Right
            while (!s1.empty()) {
                TreeNode* cur = s1.top();
                s1.pop();
                temp.push_back(cur->val);
                if (cur->left) s2.push(cur->left);
                if (cur->right) s2.push(cur->right);
            }
            if (!temp.empty()) ans.push_back(temp);

            temp.clear();

            // Right to Left
            while (!s2.empty()) {
                TreeNode* cur = s2.top();
                s2.pop();
                temp.push_back(cur->val);
                if (cur->right) s1.push(cur->right);
                if (cur->left) s1.push(cur->left);
            }
            if (!temp.empty()) ans.push_back(temp);
        }

        return ans;
    }
};

/*
----------------------------------------

🧠 Example:

      1
     / \
    2   3
   / \   \
  4   5   6

→ Output: [[1], [3,2], [4,5,6]]

----------------------------------------

🕒 Time Complexity: O(N)
- Every node is visited once.

📦 Space Complexity: O(N)
- For stacks and result storage.

📘 Notes:
- Stack order determines the zigzag pattern.
- Efficient alternative to using a queue + direction toggle.

*/
