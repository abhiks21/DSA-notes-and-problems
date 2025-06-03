/*
==============================
🔷 Problem: Longest Common Subsequence (LCS)
==============================
Given two strings text1 and text2, return the length of their longest common subsequence.

==============================
🔧 Approach: Top-Down DP (Memoization)
==============================
- Use recursion to compare characters from both strings.
- If characters match, move both pointers forward.
- If not, recursively try both skipping options.
- Store intermediate results in a dp table to avoid recomputation.

==============================
⚠️ Initial Mistake
==============================
❌ Passing strings by value in the recursive function:
    int solve(int i, int j, string text1, string text2)

➡ This caused copies of the strings to be made in every recursive call, 
   leading to Time Limit Exceeded (TLE) due to excessive overhead.

==============================
✅ Fix
==============================
✔️ Pass strings by reference:
    int solve(int i, int j, string &text1, string &text2)

➡ This avoids unnecessary copying and keeps recursion efficient.

==============================
🧩 Final Correct Code
==============================
*/

class Solution {
public:
    int dp[1001][1001];

    int solve(int id1, int id2, string &text1, string &text2) {
        if(id1 == text1.size() || id2 == text2.size()) return 0;

        if(dp[id1][id2] != -1) return dp[id1][id2];

        if(text1[id1] == text2[id2]) {
            return dp[id1][id2] = 1 + solve(id1 + 1, id2 + 1, text1, text2);
        }

        int leave1 = solve(id1 + 1, id2, text1, text2);
        int leave2 = solve(id1, id2 + 1, text1, text2);
        return dp[id1][id2] = max(leave1, leave2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, text1, text2);
    }
};

/*
==============================
📊 Time and Space Complexity
==============================
Time Complexity:  O(n * m)
Space Complexity: O(n * m) — for the dp table

Where:
- n = length of text1
- m = length of text2

==============================
✅ Status: Working & Optimized
==============================
*/
