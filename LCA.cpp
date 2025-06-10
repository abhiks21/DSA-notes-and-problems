/*

📌 Problem:
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
The LCA is the lowest node in the tree that has both p and q as descendants.

📥 Example:
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

LCA(5, 1) = 3
LCA(5, 4) = 5

---------------------------------------
✅ Method 1: Path Comparison Method

🧠 Approach:
1. Perform DFS from root and record paths to both `p` and `q`.
2. Once both paths are stored, compare them index-by-index.
3. The last matched node is the LCA.

⏱ Time Complexity: O(N)
💾 Space Complexity: O(N)

⚠️ Common Mistakes:
- Forgetting to copy temp to pathp/pathq using `=`
- Not using reference correctly
- Not handling cases where p or q is not found

*/

class Solution {
public:
    int foundp = 0, foundq = 0;

    void findPath(TreeNode* root, TreeNode* p, TreeNode* q,
                  vector<TreeNode*>& pathp, vector<TreeNode*>& pathq, vector<TreeNode*>& temp) {
        if (!root) return;

        temp.push_back(root);  // add current node to path

        if (root == p) {
            pathp = temp;      // store path to node p
            foundp = 1;
        }
        if (root == q) {
            pathq = temp;      // store path to node q
            foundq = 1;
        }

        // Continue DFS only if paths aren't both found
        if (!foundp || !foundq) {
            findPath(root->left, p, q, pathp, pathq, temp);
            findPath(root->right, p, q, pathp, pathq, temp);
        }

        temp.pop_back();  // backtrack
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp, pathq, temp;
        findPath(root, p, q, pathp, pathq, temp);

        TreeNode* ans = nullptr;
        int size = min(pathp.size(), pathq.size());

        // Find the last common node in both paths
        for (int i = 0; i < size; i++) {
            if (pathp[i] == pathq[i]) {
                ans = pathp[i];
            } else {
                break;
            }
        }
        return ans;
    }
};

/*
---------------------------------------
✅ Method 2: Optimal Recursive Method

🧠 Approach:
1. Use DFS recursion.
2. If current node is either p or q, return it.
3. Recurse left and right.
4. If both return non-null → current node is LCA.
5. Else, return the non-null one.

⏱ Time Complexity: O(N)
💾 Space Complexity: O(H)

⚠️ Common Mistakes:
- Returning too early
- Not checking both left and right properly
- Using unnecessary flags or global variables

*/

class Solution {
public:
    TreeNode* findPath(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;  // base case: found p or q or reached end

        TreeNode* left = findPath(root->left, p, q);   // recurse left
        TreeNode* right = findPath(root->right, p, q); // recurse right

        if (left && right)
            return root;  // both found → current is LCA

        return left ? left : right; // return non-null child if only one found
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findPath(root, p, q);
    }
};

/*
✅ Summary:
- Method 1 is easier to understand, useful for debugging.
- Method 2 is cleaner and optimal — ideal for interviews.

🔥 Use method 2 unless path retrieval is specifically required.

*/
