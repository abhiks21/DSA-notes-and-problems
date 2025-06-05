// ✅ Problem:
// A robot is located at the top-left corner of a grid with obstacles.
// The robot can only move either down or right at any point in time.
// An obstacle and space are marked as 1 or 0 respectively in the grid.
// Return the number of unique paths from top-left to bottom-right avoiding obstacles.

// ✅ Example:
// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There are two paths avoiding the obstacle at (1,1).

// ✅ Approach:
// - Use recursion with memoization (top-down DP)
// - At each cell (i, j), try moving right and down if not an obstacle
// - If current cell is out of bounds or an obstacle, return 0
// - Base case: if at bottom-right cell and not an obstacle, return 1
// - Memoize results in dp[i][j] to avoid recomputation

// ✅ Common Mistakes:
// 1. Not checking for obstacle at destination (can cause incorrect 1 return)
// 2. Forgetting to handle edge cases with obstacle at start or end
// 3. Not using memoization — leads to TLE

// ✅ Final Code:

class Solution {
public:
    int m, n;
    int dp[101][101];

    int solve(int i, int j, vector<vector<int>>& Grid) {
        if (i >= m || j >= n || Grid[i][j] == 1) return 0;
        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, Grid);
        int down = solve(i + 1, j, Grid);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, obstacleGrid);
    }
};

// ✅ Time Complexity:
// O(m * n) — each cell is visited once with memoization

// ✅ Space Complexity:
// O(m * n) — for the dp table
