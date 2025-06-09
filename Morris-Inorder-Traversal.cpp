/*
🔰 Problem:
Perform inorder traversal (Left → Root → Right) of a binary tree
without using recursion or an explicit stack.

🤔 Why Use Morris Traversal?
- Traditional inorder traversal uses either recursion (implicit stack) or a manual stack.
- Both approaches use **O(h)** space, where h = height of the tree.
- Morris Traversal allows **O(1) space traversal**, which is optimal.

🧠 How Morris Traversal Optimizes Tree Traversal:
- Uses the concept of a **Threaded Binary Tree**.
- It modifies the tree temporarily by connecting the **inorder predecessor** of each node
  to the current node.
- This avoids the need for a stack or recursion, and the original tree is restored afterward.

✅ Approach Summary:
1. If left child is NULL → visit node, move to right.
2. If left child exists:
   a. Find the rightmost node in left subtree (inorder predecessor).
   b. If pred->right == NULL → make it point to root (create thread), move to left child.
   c. If pred->right == root → thread already exists, remove it, visit root, move to right.

*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        while (root) {
            if (!root->left) {
                ans.push_back(root->val);      // Visit node with no left child
                root = root->right;
            } else {
                TreeNode* pred = root->left;

                // Find inorder predecessor
                while (pred->right && pred->right != root) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    // Create a thread back to the root
                    pred->right = root;
                    root = root->left;
                } else {
                    // Thread exists → remove it and visit node
                    pred->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }

        return ans;
    }
};

/*
⏱️ Time Complexity: O(n)
- Each node is visited at most twice (once to create thread, once to remove it).

📦 Space Complexity: O(1)
- No stack or recursion used.
- Tree is temporarily modified and restored during traversal.
*/
