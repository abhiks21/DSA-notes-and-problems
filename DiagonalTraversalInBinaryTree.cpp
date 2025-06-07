/*
🟩 Problem: Diagonal Traversal of a Binary Tree

🔸 Description:
Given a binary tree, print all the elements diagonally.
- Nodes on the same diagonal (top-right direction) should be grouped together.
- Return all diagonals in top-down order.

--------------------------------------------------

🧠 Approach: DFS + Map

1. Maintain a `map<int, vector<int>> mp` where key = diagonal level
2. Start DFS from root with diagonal level `0`
3. Rules:
   - Going **left** → increase diagonal level by 1
   - Going **right** → stay on same diagonal
4. After traversal, flatten the map to build the answer.

--------------------------------------------------

❌ Common Mistakes:
- Reversing diagonal update (some mistakenly increase on right).
- Using queue when recursion is enough (DFS is simpler here).

--------------------------------------------------

✅ Code:
class Solution {
  public:
    void solve(int d, Node* root, map<int, vector<int>> &mp){
        if (!root) return;

        mp[d].push_back(root->data);
        solve(d + 1, root->left, mp); // left -> next diagonal
        solve(d, root->right, mp);    // right -> same diagonal
    }

    vector<int> diagonal(Node *root) {
        vector<int> ans;
        map<int, vector<int>> mp;
        solve(0, root, mp);
        for (auto &it : mp) {
            ans.insert(ans.end(), it.second.begin(), it.second.end());
        }
        return ans;
    }
};

--------------------------------------------------

⏱️ Time Complexity: O(n)
- Each node is visited once.

📦 Space Complexity: O(n)
- Map + call stack (in case of skewed tree)

--------------------------------------------------

📌 Notes:
- This DFS + map approach is clean, structured, and accepted on GFG.
- If needed, can be rewritten using BFS + queue for level-wise diagonal traversal.

*/
