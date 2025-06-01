/*
🧩 Problem:
Given weights and values of `n` items, put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack. You can either include an item or exclude it (0/1 property).

Input:
- val[]: values of the items
- wt[]: weights of the items
- W: total weight capacity

🎯 Goal: Maximize total value without exceeding weight W.

-------------------------------------------------------
🧠 Approach (Top-Down DP with Memoization):

Define a recursive function `solve(n, W)` which returns the maximum value we can obtain by considering items from index 0 to `n` with remaining weight `W`.

Recurrence:
- If `wt[n] <= W`, we have two options:
  1. Include the item: value = val[n] + solve(n-1, W-wt[n])
  2. Exclude the item: value = solve(n-1, W)
  → Take max of both

- If `wt[n] > W`, we can't include it, so skip:
  → value = solve(n-1, W)

Use a memoization table `dp[W+1][n+1]` to store intermediate results.

-------------------------------------------------------
❌ Common Mistake:
You forgot to **add `val[n]`** when you include the item:
WRONG: `max(solve(...), solve(...))`
CORRECT: `max(val[n] + solve(...), solve(...))`

-------------------------------------------------------
✅ Corrected Code:
*/

class Solution {
public:
    int dp[1001][1001]; // dp[w][n] = max value using first n items and weight w
    
    int solve(int n, int W, vector<int> &val, vector<int> &wt) {
        if (n < 0 || W == 0) return 0;

        if (dp[W][n] != -1) return dp[W][n];

        if (wt[n] <= W) {
            // Include or exclude the current item
            return dp[W][n] = max(
                val[n] + solve(n - 1, W - wt[n], val, wt),
                solve(n - 1, W, val, wt)
            );
        } else {
            // Can't include the item, so skip
            return dp[W][n] = solve(n - 1, W, val, wt);
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        memset(dp, -1, sizeof(dp));
        int n = val.size();
        return solve(n - 1, W, val, wt);
    }
};
/*
-------------------------------------------------------
⏱️ Time Complexity: O(n * W)
- We solve each subproblem only once and store it.

🧠 Space Complexity: O(n * W)
- Memoization table + recursion stack (O(n) in worst case)

*/
