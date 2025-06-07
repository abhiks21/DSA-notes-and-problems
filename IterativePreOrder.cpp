/*
🔷 Problem: Preorder Traversal of Binary Tree (Iterative)

📘 Definition:
Preorder traversal visits nodes in the order:
→ root → left → right

This solution avoids recursion and uses a stack to simulate the traversal.

----------------------------------------

🔧 Approach: Iterative using Stack

🛠️ Steps:
1. Initialize a stack and push the root node.
2. While the stack is not empty:
   - Pop the top node, process it (add to result).
   - Push right child (if any), then left child (if any).
     This ensures that the left child is processed before the right child (since stack is LIFO).

✅ Advantage:
- Handles deep trees without recursion stack overflow.
- Efficient and easy to follow for interview settings.

----------------------------------------

✅ Code with Inline Comments:
*/

class Solution {
public:
    // Helper function to perform iterative preorder traversal
    void solve(TreeNode* root, vector<int>& ans) {
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curNode = st.top();
            st.pop();

            ans.push_back(curNode->val); // Visit current node

            // Push right child first so that left is processed first
            if (curNode->right) st.push(curNode->right);
            if (curNode->left) st.push(curNode->left);
        }
    }

    // Main function to be called
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};  // Handle empty tree
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

/*
----------------------------------------

🕒 Time Complexity: O(N)
- N = number of nodes in the tree
- Every node is visited exactly once

📦 Space Complexity: O(H)
- H = height of the tree
- Stack may hold up to H nodes at a time

📘 Notes:
- This is a non-recursive approach.
- Useful in production-level code where recursion depth can be an issue.

*/
