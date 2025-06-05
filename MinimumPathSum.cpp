// ✅ Problem:
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path. You can only move either down or right at any point in time.

// ✅ Example:
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Path 1→3→1→1→1 minimizes the sum.

// ✅ Approach:
// - Use recursion with memoization (top-down dynamic programming)
// - At each cell (i, j), try moving right and down
// - Memoize results in dp[i][j] to avoid recomputation
// - Base case: if you reach bottom-right cell, return its value
// - If out of bounds, return a large value (invalid path)

// ✅ Common Mistakes:
// 1. Returning 0 for out-of-bound paths (causes min to pick invalid paths)
// 2. Redefining class variables like m and n inside function (shadowing)
// 3. Returning too early (using multiple return statements improperly)

// ✅ Final Code:

class Solution {
public:
    int dp[101][101];
    int m, n;

    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) return grid[i][j];
        if (i >= m || j >= n) return INT_MAX; // Out of bounds

        if (dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, grid);
        int down = solve(i + 1, j, grid);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, grid);
    }
};

// ✅ Time Complexity:
// O(m * n) — each cell is computed once and memoized

// ✅ Space Complexity:
// O(m * n) — for the dp table (memoization)
