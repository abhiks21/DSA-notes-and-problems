/*
────────────────────────────────────────────────────────────
🧩 Problem: Perfect Sum Problem
────────────────────────────────────────────────────────────
Given an array of non-negative integers `arr[]` and an integer `target`, 
count the total number of subsets of the array whose sum is equal to `target`.

Subsets that only differ in ordering are considered the same, and 
since the array can contain zeroes, each zero can be either included or excluded 
without affecting the sum.

Return the count modulo 1e9+7.

────────────────────────────────────────────────────────────
🧠 Approach: Top-Down DP with Memoization
────────────────────────────────────────────────────────────
- Use recursion + memoization to count subsets that sum up to `target`.
- For each element:
    ▸ Include it in the sum.
    ▸ Exclude it from the sum.
- Use `dp[n][target]` to memoize results to avoid recomputation.
- Proper base case: 
    ▸ If `n == 0` and `target == 0`, return 1 (empty subset counts).
    ▸ If `n == 0` and `target != 0`, return 0 (no subset can be formed).

────────────────────────────────────────────────────────────
❌ Common Mistakes:
────────────────────────────────────────────────────────────
1. ❌ Incorrect base case:
   if (target == 0) return 1; if (n == 0) return 0;
   → This prematurely stops recursion, and misses all combinations 
     that include zeros after the target is met.

2. ❌ Using a separate `zeroMultiplier = 2^zeroCount`:
   → This is only needed if you prune recursion early after target==0.
   → But if you let recursion continue, zero combinations are counted naturally.

3. ❌ Not using modulo in recursive addition:
   → (a + b) % MOD is essential to prevent overflow.

────────────────────────────────────────────────────────────
✅ Correct Code:
────────────────────────────────────────────────────────────
*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1002][1002];

    int solve(int n, vector<int>& arr, int target) {
        if (n == 0) return (target == 0);  // ✅ Correct base case

        if (dp[n][target] != -1) return dp[n][target];

        if (arr[n - 1] <= target) {
            return dp[n][target] = (solve(n - 1, arr, target - arr[n - 1]) +
                                    solve(n - 1, arr, target)) % MOD;
        } else {
            return dp[n][target] = solve(n - 1, arr, target);
        }
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(n, arr, target);
    }
};

/*
────────────────────────────────────────────────────────────
⏱ Time Complexity:
────────────────────────────────────────────────────────────
O(n * target) 
- We compute each state (n, target) once due to memoization.

📦 Space Complexity:
────────────────────────────────────────────────────────────
O(n * target) 
- For the memoization table `dp`.

Optionally, recursion stack space: O(n) in worst case.
────────────────────────────────────────────────────────────
*/
