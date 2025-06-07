/*
🔷 Problem: Postorder Traversal of Binary Tree (Iterative)

📘 Definition:
Postorder traversal visits nodes in the order:
→ left → right → root

This iterative solution avoids recursion and uses a **single stack** with a clever trick:
→ Do a modified preorder traversal (root → right → left), then reverse the result.

----------------------------------------

🔧 Approach: Modified Preorder + Reverse

🛠️ Steps:
1. Use a stack and perform traversal in the order: root → right → left.
2. Push the current node's value to the result vector.
3. At the end, reverse the result to get: left → right → root (i.e., postorder).

✅ Advantage:
- Efficient and uses only one stack.
- Avoids complex state tracking or two-stack solutions.

----------------------------------------

✅ Code with Inline Comments:
*/

class Solution {
  public:
    // Helper function to perform modified preorder traversal
    void solve(Node* root, vector<int>& ans) {
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();

            ans.push_back(cur->data);  // Process current node

            // Push left first, so right is processed first
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
    }

    // Main function to return postorder traversal
    vector<int> postOrder(Node* root) {
        if (!root) return {};

        vector<int> ans;
        solve(root, ans);

        // Reverse the modified preorder result to get postorder
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
----------------------------------------

🕒 Time Complexity: O(N)
- Each node is visited once.

📦 Space Complexity: O(H)
- H = height of the tree (stack usage).

📌 Notes:
- This is a clever variant of iterative postorder.
- Much simpler than the standard 2-stack or visited-flag solutions.
- Easy to implement and remember for interviews.

*/
