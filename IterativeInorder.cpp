/*
🔷 Problem: Inorder Traversal of Binary Tree (Iterative with Visit State)

📘 Definition:
Inorder traversal visits nodes in the order:
→ left → root → right

This solution simulates recursion using two stacks:
- One stack stores the node.
- Another parallel stack stores the "visit state" of the node.

----------------------------------------

🔧 Approach: Iterative with Explicit Visit State Tracking

🛠️ Steps:
1. Use two stacks:
   - `st`: holds TreeNode pointers
   - `vis`: holds visit flags (0 for first time, 1 after left child processed)
2. When a node is visited for the first time (`state == 0`):
   - Push its right child with state 0
   - Re-push itself with state 1
   - Push its left child with state 0
3. When visited again (`state == 1`):
   - Process the node (i.e., add its value to `ans`)

✅ Benefit:
- This simulates the exact behavior of recursive calls.
- Can be generalized easily to other traversals (preorder, postorder).

----------------------------------------

✅ Code with Inline Comments:
*/

class Solution {
public:
    // Helper function to simulate recursive inorder using visit state
    void solve(TreeNode* root, vector<int>& ans) {
        stack<TreeNode*> st;  // Stack for nodes
        stack<int> vis;       // Stack for visit state: 0 = first time, 1 = process node

        st.push(root);
        vis.push(0);

        while (!st.empty()) {
            TreeNode* curNode = st.top(); st.pop();
            int state = vis.top(); vis.pop();

            if (state == 0) {
                // First time visiting this node

                // Push right child first (processed after root)
                if (curNode->right) {
                    st.push(curNode->right);
                    vis.push(0);
                }

                // Push current node again with updated state (to be processed after left)
                st.push(curNode);
                vis.push(1);

                // Push left child next (to be processed first)
                if (curNode->left) {
                    st.push(curNode->left);
                    vis.push(0);
                }
            }
            else if (state == 1) {
                // Second time → process the current node
                ans.push_back(curNode->val);
            }
        }
    }

    // Main function
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

/*
----------------------------------------

🕒 Time Complexity: O(N)
- Each node is visited exactly once.

📦 Space Complexity: O(H)
- H = height of the tree (due to stack usage)

📘 Notes:
- While standard inorder can be done with one stack, this approach is excellent for:
  → Simulating recursion manually
  → Interview questions that test stack-based recursion simulation

*/
