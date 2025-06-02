/*# Partition Equal Subset Sum - Notes

---

### Problem:
Given a list of positive integers `nums`, determine if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

---

### Approach:
- Calculate total sum of the array.
- If sum is odd, return false immediately (can't split into two equal halves).
- Else, target is `sum/2`.
- Use recursion + memoization or dynamic programming to check if there's a subset with sum equal to `target`.
- State: `dp[n][sum]` indicates whether it's possible to get sum `sum` using first `n` elements.
- Recurrence:
  - If current element `nums[n-1]` ≤ sum, choose either:
    - Include `nums[n-1]` in subset: check `dp[n-1][sum - nums[n-1]]`
    - Exclude `nums[n-1]`: check `dp[n-1][sum]`
  - Else, exclude current element.
- Base cases:
  - sum == 0 → true (empty subset possible)
  - n == 0 and sum != 0 → false

---

### Common Mistakes:
- Not checking if total sum is odd before proceeding.
- Confusing parameters in recursion leading to incorrect conditions.
- Memoization table dimensions too small or indexing errors.
- Modifying the sum parameter incorrectly inside recursion.
- Not using an appropriate DP dimension, leading to out-of-bound errors.

---

### Code (Memoized Recursive):

```cpp*/
class Solution {
public:
    int dp[202][22222];  // dp[n][sum]
    
    bool solve(int n, vector<int> &nums, int sum) {
        if (sum == 0) return true;
        if (n == 0) return false;
        if (dp[n][sum] != -1) return dp[n][sum];

        if (nums[n-1] <= sum) {
            dp[n][sum] = solve(n-1, nums, sum - nums[n-1]) || solve(n-1, nums, sum);
        } else {
            dp[n][sum] = solve(n-1, nums, sum);
        }
        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        memset(dp, -1, sizeof(dp));
        return solve(n, nums, sum / 2);
    }
};
/*
time complexity =O(N*Sum)
space complexity=O(N*Sum)
*/
