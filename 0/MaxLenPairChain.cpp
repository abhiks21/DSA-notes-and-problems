/*
🔹 Problem: Maximum Length of Pair Chain
Leetcode 646: https://leetcode.com/problems/maximum-length-of-pair-chain/

🔹 Problem Statement:
You are given an array of `n` pairs `pairs[i] = [a, b]`, where `a < b`.
A pair `[c, d]` can follow `[a, b]` if `b < c`.
Return the length of the longest chain which can be formed.

🔹 Approach:
This is similar to Longest Increasing Subsequence (LIS).
We:
1. Sort the pairs by their first element.
2. Use recursion with memoization (Top-down DP) to check:
   - Whether to include the current pair (if it can follow the last selected one)
   - Or skip it and move forward.
3. Store results in a 2D `dp[i][p+1]` table (`p` can be `-1`, hence shift index by 1).

🔹 Code:
*/

class Solution {
public:
    int dp[1001][1002]; // dp[i][p+1] to handle p = -1

    int solve(int i, int p, vector<vector<int>>& pairs) {
        if (i >= pairs.size()) return 0;

        if (dp[i][p + 1] != -1) return dp[i][p + 1];

        int take = 0;
        // If no previous pair selected or current can follow previous
        if (p == -1 || pairs[i][0] > pairs[p][1]) {
            take = 1 + solve(i + 1, i, pairs);
        }

        int skip = solve(i + 1, p, pairs);

        return dp[i][p + 1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end()); // Sort by first element
        memset(dp, -1, sizeof(dp)); // Initialize memo table
        return solve(0, -1, pairs);
    }
};

/*
🔹 Time Complexity:
- Sorting: O(n log n)
- Recursion with memoization: O(n^2)
  (We try each pair with all previous ones)

🔹 Space Complexity:
- O(n^2) for memoization table (dp[n][n+1])

🔹 Alternate Greedy Approach (Faster):
- Sort by second element and greedily pick next pair with smallest end that’s > previous end.
- TC: O(n log n), SC: O(1)
*/
