/*==========================================================
✅ Problem: Longest Increasing Subsequence (LIS)
-----------------------------------------------------------
Given an integer array `nums`, return the length of the 
longest strictly increasing subsequence.

🔸 Example:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The LIS is [2,3,7,101].

==========================================================
✅ Approach: Top-Down DP with Memoization (Recursive)
-----------------------------------------------------------
- Use recursion to try every possibility of taking or not 
  taking an element based on whether it's increasing.
- Use a 2D dp array where `dp[i][p+1]` stores the LIS 
  starting from index `i` with previous index `p`.
- We shift `p` by +1 to safely handle `p = -1`.

==========================================================
✅ Code:
*/

class Solution {
public:
    int dp[3001][3001];

    int solve(int i, int p, vector<int>& nums){
        if(i >= nums.size()) return 0;

        if(dp[i][p + 1] != -1) return dp[i][p + 1]; // shifted p by +1

        int take = 0;
        if(p == -1 || nums[i] > nums[p]) {
            take = 1 + solve(i + 1, i, nums);
        }
        int skip = solve(i + 1, p, nums);

        return dp[i][p + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }
};

/*
==========================================================
✅ Time Complexity: O(n^2)
- Each state dp[i][p+1] is visited once.
- Two nested loops (i and p) lead to n^2 total states.

✅ Space Complexity: O(n^2)
- Due to the 2D dp array of size n x n.

==========================================================
🔹 Follow-up:
- You can solve this problem in O(n log n) using a binary 
  search + greedy approach (patience sorting method).
==========================================================
*/
