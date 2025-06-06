/*## 🔍 Problem: Left View of Binary Tree

**Goal:**  
Print the left view of a binary tree, i.e., the set of nodes visible when the tree is viewed from the left side.

---

### 🧠 Approach:

- Use **DFS (preorder traversal)** with **level tracking**.
- Keep track of the current level in the recursion.
- For each level, add the first node encountered (which will be the leftmost node at that level) to the result vector.

---

### ✅ Key Insight:

Only push the node's value into the result when `result.size() == level`. This ensures we only take the first node seen at each level (the leftmost).

---

### 🧾 Code with Comments

```cpp*/
class Solution {
  public:
    // Helper function to collect left view nodes using DFS
    void collectLeftView(Node* root, vector<int>& result, int level) {
        if (!root) return;

        // If we're visiting this level for the first time
        if (result.size() == level) result.push_back(root->data);

        // Traverse left child first for left view
        collectLeftView(root->left, result, level + 1);
        collectLeftView(root->right, result, level + 1);
    }

    // Main function to be called with the root of the binary tree
    vector<int> leftView(Node *root) {
        vector<int> result;
        collectLeftView(root, result, 0);  // Start from level 0
        return result;
    }
};/*
```

---

### ⏱️ Time and Space Complexity

- **Time Complexity:** `O(n)` — Each node is visited once.
- **Space Complexity:** `O(h)` — Due to recursion stack (h = height of the tree).

---

### 📌 Example:

For the tree:
```
       1
     /   \
    2     3
     \   /
      4 5
```

**Output:**  
`[1, 2, 4]`

---*/

### 📘 Notes:

- This solution is optimal and avoids extra queue/level tracking via BFS.
- Ideal for **interviews** when recursion is acceptable.
