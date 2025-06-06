/*
🔷 Problem: Check if Two Trees are Identical

📘 Definition:
Two binary trees are said to be identical if:
- They are structurally identical (same shape).
- Their corresponding nodes have the same value.

----------------------------------------

🔧 Approach:
- Use recursion to compare nodes at corresponding positions in both trees.
- Base cases:
  - If both nodes are NULL ⇒ return true.
  - If only one is NULL or values don’t match ⇒ return false.
- Recursively check both left and right subtrees.

⚠️ Note: Your original code **missed** returning the result of recursive calls. That causes incorrect behavior.

----------------------------------------

✅ Corrected Code:
*/

class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        if (!r1 && !r2) return true;                      // Both null → identical
        if (!r1 || !r2 || r1->data != r2->data) return false;  // Structure mismatch or data mismatch
        
        // Recursively check left and right subtrees
        return isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }
};

/*
🧠 Example:

Tree 1:         Tree 2:
    1               1
   / \             / \
  2   3           2   3

→ Identical ✅

----------------------------------------

🕒 Time Complexity: O(N)
- Every node in both trees is visited once.

📦 Space Complexity: O(H)
- Due to recursion stack, where H is the height of the tree.

*/
