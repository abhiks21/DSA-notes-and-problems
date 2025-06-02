/*
=============================================
🧠 Problem: House Robber (Leetcode #198)
=============================================
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money. You cannot rob two adjacent houses.

📥 Input: vector<int> nums — nums[i] is the money at the i-th house.
🎯 Output: Maximum amount you can rob without robbing adjacent houses.

=====================================================
🧭 Approach 1: Recursion + Memoization (Top-Down DP)
=====================================================
- Use a helper function with memoization to avoid recomputation.
- For each index n:
   1. Rob: nums[n-1] + solve(n-2)
   2. Skip: solve(n-1)

🔁 Time Complexity: O(n)
📦 Space Complexity: O(n) — recursion + memo table

✅ Code:
*/

class Solution {
public:
    int dp[102];
    int solve(int n, vector<int>& nums){
        if(n <= 0) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = max(nums[n-1] + solve(n-2, nums), solve(n-1, nums));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(n, nums);
    }
};

/*
=====================================
🧭 Approach 2: Bottom-Up Tabulation
=====================================
- Build a DP array t[] iteratively.
- Transition:
   t[i] = max(nums[i-1] + t[i-2], t[i-1])

🔁 Time Complexity: O(n)
📦 Space Complexity: O(n)

✅ Code:
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> t(n + 1);
        t[0] = 0;
        t[1] = nums[0];

        for(int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + t[i - 2];
            int skip = t[i - 1];
            t[i] = max(steal, skip);
        }
        return t[n];
    }
};

/*
======================================================
🧭 Approach 3: Space Optimized DP (2 variables only)
======================================================
- We don't need the full DP array, just previous two states.
- Use prev1 and prev2 to track last two optimal values.

🔁 Time Complexity: O(n)
📦 Space Complexity: O(1)

✅ Code:
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = 0;        // dp[i-2]
        int prev1 = nums[0];  // dp[i-1]

        for (int i = 1; i < n; i++) {
            int steal = nums[i] + prev2;
            int skip = prev1;
            int curr = max(steal, skip);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
