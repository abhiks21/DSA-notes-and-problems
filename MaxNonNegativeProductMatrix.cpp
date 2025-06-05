/*## 🔥 Problem: Maximum Non-Negative Product in a Matrix

### 📌 Description
You are given an `m x n` matrix `grid` filled with integers. Starting at the top-left cell, you can only move **right** or **down** at each step. Each path creates a product of all visited cell values.

Your task is to return the **maximum non-negative product** modulo `1e9 + 7`. If there's no such product (i.e., all paths result in negative products), return `-1`.

---

### 🧠 Approach

We use **recursion + memoization** to explore all paths and store subproblem results.

At each cell `(i, j)`:
- Track both **minimum** and **maximum** products from `(i, j)` to the bottom-right.
- This is needed because multiplying a **negative min** can lead to a **max**, and vice versa.

We store a pair of values:
```cpp
dp[i][j] = {maxProductFromHere, minProductFromHere}
```

---

### ❗ Why Track Both Min and Max?

Negative numbers change the sign of the product:
- `grid[i][j] * maxChild` might be less than `grid[i][j] * minChild`
- You need to try **both** combinations to ensure correct max and min at each cell.

---

### ⚠️ Common Mistakes

1. ❌ **Wrong loop conditions**:
   - `if (j < n - 1)` not `j < m - 1`
   - `if (i < m - 1)` not `i < n - 1`

2. ❌ **Incorrect DP initialization**:
   - `memset()` doesn't work for `pair<ll, ll>`
   - Manually initialize using nested loops

3. ❌ **Using `% MOD` on negative products**:
   - Only apply `% MOD` at the final positive result.

---

### ✅ Code

cpp*/
class Solution {
public:
    typedef long long ll;
    int m, n;
    int MOD = 1e9 + 7;
    pair<ll, ll> dp[16][16];

    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1)
            return {grid[i][j], grid[i][j]};

        if (dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX))
            return dp[i][j];

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if (j < n - 1) {
            auto [rightMax, rightMin] = solve(i, j + 1, grid);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        if (i < m - 1) {
            auto [downMax, downMin] = solve(i + 1, j, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        return dp[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Initialize DP with {LLONG_MIN, LLONG_MAX}
        for (int i = 0; i < 16; ++i)
            for (int j = 0; j < 16; ++j)
                dp[i][j] = {LLONG_MIN, LLONG_MAX};

        auto [maxProduct, _] = solve(0, 0, grid);
        return maxProduct < 0 ? -1 : maxProduct % MOD;
    }
};/*


---

### ⏱ Time and Space Complexity

| Metric          | Value         |
|-----------------|---------------|
| Time Complexity | O(m × n)      |
| Space Complexity| O(m × n) (for DP + recursion stack) |
