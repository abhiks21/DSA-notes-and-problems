/*
🔰 Problem:
Given a binary tree and the value of a starting node,
find how much time it will take to infect the entire tree.
Infection spreads to connected nodes (left, right, or parent) every minute.

---

🛠 Approach (You Got Right):
1. Use DFS to locate the `start` node.
2. From the `start` node:
   - Time to infect downward = height of the subtree.
   - As we return up the recursion stack, we simulate the infection moving to the parent.
3. Use a signal (`return -1`) to indicate the infected path when coming back up.
4. Track max time using a global variable `maxi`.

---

⚠️ Mistake:
You correctly used `-1` to mark infection up the tree but:
- Didn't decrement it during the return (`return l` instead of `l - 1`)
- This caused the infection path to never increment upward

✅ Fix:
Change return to `return l - 1` or `return r - 1` so the depth increases as infection moves up.

---

💻 Final Correct Code (In-Place Fix Applied)
*/

class Solution {
public:
    int maxi = INT_MIN;

    // Returns the height of a subtree
    int find(TreeNode* root) {
        if (root == NULL) return 0;
        int l = find(root->left);
        int r = find(root->right);
        return max(l, r) + 1;
    }

    // DFS to find start node and simulate infection
    int solve(TreeNode* root, int start) {
        if (root == NULL) return 0;

        if (root->val == start) {
            int down = find(root) - 1; // infect downward
            maxi = max(maxi, down);
            return -1; // mark path up as infected
        }

        int l = solve(root->left, start);
        int r = solve(root->right, start);

        if (l < 0) {
            maxi = max(maxi, (-l + r)); // infection going up through left
            return l - 1; // continue infection upward
        } else if (r < 0) {
            maxi = max(maxi, (-r + l)); // infection going up through right
            return r - 1; // continue infection upward
        }

        return max(l, r) + 1; // regular height return
    }

    int amountOfTime(TreeNode* root, int start) {
        if (root->val == start) return find(root) - 1; // shortcut
        solve(root, start);
        return maxi;
    }
};

/*
⏱ Time Complexity: O(n)
- Each node is visited once in both `solve()` and `find()`.

📦 Space Complexity: O(h)
- Due to recursion stack, where h = height of tree.

🧠 Key Insight:
- Infection spreads like a wave: down (height), and up (depth from start).
- Use negative returns to propagate the infection path upward.
*/
