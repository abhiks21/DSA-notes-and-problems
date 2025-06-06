/*
🔷 Problem: Check if a Binary Tree is Height-Balanced

📘 Definition:
A binary tree is height-balanced if for every node:
→ The height difference between left and right subtree is ≤ 1.

----------------------------------------

🔧 Approach: Post-order DFS with a Flag (Early Termination Optimized)

🛠️ Logic:
- Use a boolean reference flag to track imbalance.
- Recursively compute height using post-order traversal.
- If at any node, the absolute difference between left and right subtree heights > 1 → mark flag as false.
- If flag becomes false, stop further recursive calls to save time.

----------------------------------------

✅ Function Code:
*/

int solve(Node* node, bool &flag) {
    if (!node || !flag) return 0;  // Early exit if node is NULL or imbalance already found

    int left = solve(node->left, flag);   // Get height of left subtree
    int right = solve(node->right, flag); // Get height of right subtree

    if (abs(left - right) > 1) {
        flag = false; // Tree is not balanced at this node
    }

    return 1 + max(left, right);  // Return height of current subtree
}

bool isBalanced(Node* root) {
        // Code here
        bool flag =true;
        solve(root, flag);
        return flag;
}

/*
----------------------------------------

🧠 Example:

      1
     / \
    2   3
   /
  4

→ Balanced ✅

----------------------------------------

🕒 Time Complexity: O(N)
- Each node is visited once.

📦 Space Complexity: O(H)
- H = height of the tree (due to recursion stack).

📘 Notes:
- Slightly optimized compared to full traversal because it stops early if imbalance is found.
- Good for interview-style questions involving tree checks.

*/
