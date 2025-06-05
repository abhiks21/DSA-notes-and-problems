// ✅ Problem:
// A robot is located at the top-left corner of an m x n grid.
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid.
// How many possible unique paths are there?

// ✅ Example:
// Input: m = 3, n = 7
// Output: 28

// ✅ Approach:
// - Use recursion with memoization (top-down DP)
// - At each cell (i, j), try moving right and down
// - Add the number of ways to reach the destination from right and down
// - Memoize results in dp[i][j]
// - Base case: if (i == m-1 && j == n-1), return 1 (reached destination)
// - If out of bounds, return 0 (invalid path)

// ✅ Common Mistakes:
// 1. Not memoizing results (leads to TLE)
// 2. Returning 1 for out-of-bounds paths instead of 0
// 3. Using local dp instead of class-level for persistence across calls

// ✅ Final Code:

class Solution {
public:
    int dp[101][101];

    int solve(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) return 1; // reached destination
        if (i >= m || j >= n) return 0;         // out of bounds

        if (dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, m, n);
        int down = solve(i + 1, j, m, n);

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m, n);
    }
};

// ✅ Time Complexity:
// O(m * n) — each cell (i, j) is visited once due to memoization

// ✅ Space Complexity:
// O(m * n) — for the dp table
