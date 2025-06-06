/*
🔷 Problem: Convert Binary Tree to its Mirror

📘 Definition:
Mirror of a binary tree is a tree where:
- The left and right children of **all** nodes are swapped.

📌 Example:
    Original Tree:        Mirrored Tree:
         1                     1
        / \                   / \
       2   3      →          3   2
      / \                     / \
     4   5                   5   4

----------------------------------------

🔧 Approach:
- Use post-order traversal (left → right → node).
- At each node, swap its left and right children.
- Then recursively call for left and right subtrees.

✅ Code:
*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == NULL) return;  // Base case: empty tree

        // Swap the left and right children
        swap(node->left, node->right);

        // Recurse for left and right subtrees
        mirror(node->left);
        mirror(node->right);
    }
};

/*
----------------------------------------

🕒 Time Complexity: O(N)
- Each node is visited once.

📦 Space Complexity: O(H)
- Due to recursion stack, where H is the height of the tree.

📘 Note:
- Works in-place. No extra memory needed.
- Classic use case for recursive tree traversal.

*/
