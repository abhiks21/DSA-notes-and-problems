/*
🔰 Problem:
Flatten a binary tree into a right-skewed "linked list" in-place,
following the **preorder traversal order** (Root → Left → Right).

Example:
Input:
    1
   / \
  2   5
 / \   \
3   4   6

Output:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

---

🛠 Method 1: Brute-Force (using extra space)
1. Do a preorder traversal and store all node values.
2. Create a new linked list using those values.
⚠️ Not in-place. Uses O(n) extra space and destroys original structure.

---

🛠 Method 2: Optimized Morris-style (in-place)
➡️ Use a threaded binary tree approach.
1. For each node, if it has a left subtree:
   a. Find the rightmost node in that left subtree.
   b. Attach the original right subtree to that node.
   c. Move the left subtree to the right.
   d. Set the left to NULL.
2. Move to the next right node and repeat.

This is space-optimized and modifies the original tree directly.

---

✅ Final In-Place Code (Your Optimized Version)
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        while (root) {
            if (!root->left) {
                // No left child, move to right
                root = root->right;
            } else {
                // Find rightmost node in left subtree
                TreeNode* cur = root->left;
                while (cur->right) {
                    cur = cur->right;
                }

                // Attach original right subtree to rightmost node
                cur->right = root->right;

                // Move left subtree to right and nullify left
                root->right = root->left;
                root->left = NULL;

                // Next root will be updated in next loop iteration
            }
        }
    }
};

/*
⏱ Time Complexity: O(n)
- Each node is visited at most twice.

📦 Space Complexity: O(1)
- No recursion, no stack, done entirely in-place.

🧠 Key Optimisation:
- Uses Morris traversal-like threading to avoid stack/recursion.
- Restructures tree without needing extra memory.

✅ Clean, efficient, and interview-ready solution.
*/
