/*
================== PROBLEM ==================
🔹 Problem: [Leetcode 1911. Maximum Alternating Subsequence Sum]
You are given an array `nums`. An alternating sum is defined as:
    sum = nums[i1] - nums[i2] + nums[i3] - nums[i4] + ... 
Your task is to select a **subsequence** (not necessarily contiguous) and return the **maximum alternating sum** possible.

Constraints:
- You may skip elements
- Start with a positive sign at the first selected element

=============== APPROACH =================
We use **Dynamic Programming (Top-Down with Memoization)**

State:
- `i`: current index in the array
- `even`: a boolean indicating whether the current sign is `+` (even index in subsequence) or `-` (odd index)

Recurrence:
- If even: 
    take = +nums[i] + solve(i+1, false)
- If odd:
    take = -nums[i] + solve(i+1, true)
- Skip = solve(i+1, even)
- Return max(take, skip)

We memoize with a 2D `dp[i][even]` to avoid recomputation.

=============== FINAL CODE ===============
*/

class Solution {
public:
    long long dp[100002][2];

    long long solve(int i, bool even, vector<int>& nums){
        if(i == nums.size()) return 0;

        if(dp[i][even] != -1) return dp[i][even];

        if(even) {
            // Positive sign
            long long take = 1LL * nums[i] + solve(i + 1, false, nums);
            long long skip = solve(i + 1, true, nums);
            return dp[i][even] = max(take, skip);
        } else {
            // Negative sign
            long long take = -1LL * nums[i] + solve(i + 1, true, nums);
            long long skip = solve(i + 1, false, nums);
            return dp[i][even] = max(take, skip);
        }
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, true, nums); // Start with positive sign
    }
};

/*
============== TIME & SPACE COMPLEXITY ==============

🕒 Time Complexity: O(n * 2) = O(n)
    -> Each state (i, even) is computed once, and there are 2 options at each index.

💾 Space Complexity: O(n * 2) for dp array + O(n) recursion stack

============== WHY START FROM i = 0 WORKS BETTER ==============

🔸 When starting from i = 0 (left to right), the recursion terminates early,
    and memoization prunes efficiently.

🔸 Starting from n (right to left) leads to more branching and deeper stacks 
    before hitting base case, often increasing TLE risk.

============== VERDICT ==============
✅ Recommended to implement top-down recursion from i = 0 for subsequence-based DP problems 
   where pruning and direction of sign alternation matters.
*/
