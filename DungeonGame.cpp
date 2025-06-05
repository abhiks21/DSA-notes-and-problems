/* 
🧩 Problem: Dungeon Game (Leetcode 174)
You are a knight starting at the top-left corner of a dungeon grid. You need to reach the bottom-right corner (princess's cell) with minimum initial health. 
You can only move right or down, and at any point your health must be ≥ 1.

Each cell contains either a positive (gain health), zero (no change), or negative (lose health) value.

🎯 Objective:
Find the minimum initial health required to survive the dungeon and rescue the princess.

📥 Example:
Input: 
[[-2, -3, 3],
 [-5, -10, 1],
 [10, 30, -5]]

Output: 
7

Explanation: Minimum HP required at start is 7 to reach the end without dying.

----------------------------
🔍 Approach:
1. Use recursion with memoization (Top-Down DP).
2. At every cell, you can move right or down.
3. Calculate the **minimum HP** required to move forward (to the right or downward cell).
4. Ensure that the HP never drops below 1.
5. Memoize the result to avoid recomputation.

----------------------------
❌ Common Mistakes:
- Forgetting to check memo table (`dp[i][j]`).
- Typo: `dp[i][i]` instead of `dp[i][j]`.
- Not storing the result back in `dp[i][j]`.

----------------------------
✅ Final Code:
*/

class Solution {
public:
    int m, n;
    int dp[1001][1001];

    int solve(int i, int j, vector<vector<int>>& dungeon) {
        if (i == m - 1 && j == n - 1) {
            return dungeon[i][j] < 0 ? abs(dungeon[i][j]) + 1 : 1;
        }

        if (i >= m || j >= n) return INT_MAX;

        if (dp[i][j] != -1) return dp[i][j];

        int down = solve(i + 1, j, dungeon);
        int right = solve(i, j + 1, dungeon);
        int result = min(down, right);
        int required = result - dungeon[i][j];

        return dp[i][j] = (required <= 0 ? 1 : required);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, dungeon);
    }
};

/*
🧠 Why This Works:
- We always want the **minimum required health** to move forward.
- At each step, we subtract the current cell’s value and take the **max of 1 and the result**.
- We memoize to prevent TLE.

----------------------------
📈 Time Complexity: O(m * n)
📦 Space Complexity: O(m * n) for memoization

This ensures optimal performance even for large dungeon grids.
*/
