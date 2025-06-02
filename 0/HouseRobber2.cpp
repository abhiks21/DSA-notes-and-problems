/*
---------------------------------------------
🧩 Problem: House Robber II (Leetcode #213)
---------------------------------------------
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this
place are arranged in a circle, which means the first and the last house are neighbors.

You cannot rob two adjacent houses.

Return the maximum amount of money you can rob tonight **without alerting the police**.

---------------------------------------------
💡 Key Constraint:
- Since houses are in a circle, you cannot rob both the first and last house.

---------------------------------------------
🔍 Approach Overview:
We reduce the circular problem to **two linear subproblems**:
1️⃣ Rob houses from index 0 to n-2 (exclude last house)
2️⃣ Rob houses from index 1 to n-1 (exclude first house)
Return the maximum of both.

Each subproblem is a classic **House Robber I** problem.

---------------------------------------------
✅ Approach 1: Top-Down DP with Memoization
---------------------------------------------
- Recursive `solve(n, last, nums, dp)` returns the max money from house `last` to `n-1`
- `dp[n]` caches the result for subproblem ending at index `n`

📦 Code:
*/

class Solution {
public:
    int solve(int n, int last, vector<int>& nums, vector<int>& dp){
        if(n <= last) return 0;

        if(dp[n] != -1) return dp[n];

        return dp[n] = max(
            nums[n - 1] + solve(n - 2, last, nums, dp),
            solve(n - 1, last, nums, dp)
        );
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n + 1, -1); // for 1 to n-1
        vector<int> dp2(n + 1, -1); // for 0 to n-2

        int fromLast = solve(n, 1, nums, dp1);      // Rob from 1 to n-1
        int fromSecLast = solve(n - 1, 0, nums, dp2); // Rob from 0 to n-2

        return max(fromLast, fromSecLast);
    }
};

/*
---------------------------------------------
⏱ Time Complexity:
- Each subproblem runs in O(n)
- Two calls → Total: O(n)

🧠 Space Complexity:
- O(n) for memoization arrays

---------------------------------------------
🔄 Other Approaches:

🔹 Approach 2: Bottom-Up DP (Tabulation)
- Build a DP array from start to end
- Similar logic, but uses iteration instead of recursion

🔹 Approach 3: Space Optimized Bottom-Up
- Only need last two states → use 2 variables instead of full array
- Reduces space to O(1)

---------------------------------------------
🧠 Summary:
- Split circular problem into two linear ranges
- Apply classic house robber logic on both
- Return the max of both subproblems
---------------------------------------------
*/
