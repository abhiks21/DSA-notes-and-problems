/*
🔷 Problem: Height of a Binary Tree

📘 Definition:
Height of a binary tree is defined as the number of **edges** in the longest path from the root node to a leaf node.

👉 For a tree with a single node (only root), height is 0.
👉 For an empty tree (NULL), height is defined as -1.

----------------------------------------

🔧 Approach:
- Use post-order traversal to calculate the depth of left and right subtrees.
- The height is the **maximum** of left and right subtree heights.
- Since we're counting **edges**, subtract 1 from the total node depth.

----------------------------------------

✅ Code:
*/

class Solution {
  public:
    // Helper function to calculate depth in terms of number of nodes
    int depth(Node* node) {
        if (node == NULL) return 0;  // Base case: empty node has depth 0

        // Recursively calculate the max depth of left and right subtrees
        return 1 + max(depth(node->left), depth(node->right));
    }

    // Main function to return height (in terms of number of edges)
    int height(Node* node) {
        return depth(node) - 1;  // Subtract 1 to convert depth (nodes) to height (edges)
    }
};

/*
🧠 Example:
    Tree:
        1
       / \
      2   3
     /
    4

    - Path from 1 -> 2 -> 4 is longest: 3 nodes, so height = 3 - 1 = 2

----------------------------------------

🕒 Time Complexity: O(N)
- Every node is visited once.

📦 Space Complexity: O(H)
- Due to recursion stack, where H = height of the tree.

*/
