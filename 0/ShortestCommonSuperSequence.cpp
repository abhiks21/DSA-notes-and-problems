/*
=============================================
🧩 Problem: Shortest Common Supersequence (SCS)
=============================================
Given two strings `s1` and `s2`, return the length of the shortest string which has both `s1` and `s2` as subsequences.

---------------------------------------------
📌 Example:
s1 = "ab"
s2 = "ac"

Shortest Common Supersequence = "abc"
Output: 3

---------------------------------------------
🧠 Approach (Top-Down DP with Memoization):

1. Define dp[i][j] as the length of the SCS of s1[i:] and s2[j:].
2. If characters match (s1[i] == s2[j]):
   → Include it once: 1 + solve(i+1, j+1)
3. If not equal:
   → Take the min of both possibilities:
      - Add s1[i] and move i (1 + solve(i+1, j))
      - Add s2[j] and move j (1 + solve(i, j+1))
4. Base Cases:
   - If i reaches end of s1: remaining chars of s2 = s2.length() - j
   - If j reaches end of s2: remaining chars of s1 = s1.length() - i

---------------------------------------------
✅ Code:
*/

class Solution {
  public:
    int dp[501][501];

    int solve(int i, int j, string& s1, string &s2){
        if(i == s1.size()) return s2.size() - j;
        if(j == s2.size()) return s1.size() - i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2);
        } else {
            return dp[i][j] = min(
                1 + solve(i + 1, j, s1, s2),
                1 + solve(i, j + 1, s1, s2)
            );
        }
    }

    int shortestCommonSupersequence(string &s1, string &s2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2);
    }
};

/*
---------------------------------------------
⏱ Time Complexity:
O(n * m)
Where n = s1.length(), m = s2.length()

🧠 Space Complexity:
O(n * m) for memoization table

---------------------------------------------
📌 Tip:
You can also construct the actual supersequence by maintaining a parent matrix or reconstructing from choices.

---------------------------------------------
📘 Extension:
To get the actual string, trace back from dp[0][0] using the same logic and build the string accordingly.

*/
