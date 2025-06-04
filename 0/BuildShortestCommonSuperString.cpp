/*
Problem:
---------
Given two strings s1 and s2, find the shortest common supersequence (SCS) - 
the shortest string which has both s1 and s2 as subsequences.

Example:
---------
s1 = "abac"
s2 = "cab"
Output: "cabac"
Explanation: Both "abac" and "cab" are subsequences of "cabac" which is shortest.

Approach:
---------
1. Use recursion + memoization (DP) to find the length of SCS first.
2. Base case:
   - If i == s1.length(), return remaining length of s2.
   - If j == s2.length(), return remaining length of s1.
3. If characters match (s1[i] == s2[j]), add 1 + solve(i+1, j+1).
4. Else, try adding s1[i] or s2[j] and take minimum:
   1 + min(solve(i+1, j), solve(i, j+1))
5. Store results in dp[i][j] to avoid recomputation.

6. After dp table is built, reconstruct the actual SCS string using the dp table:
   - If s1[i] == s2[j], add s1[i] and recurse both indices.
   - Else follow the smaller dp value path, adding s1[i] or s2[j] accordingly.
   - Append remaining parts of strings when one is exhausted.

Common Mistakes in Implementation:
----------------------------------
- Trying to build the string and compute length in the same recursion leading to 
  excessive memory usage and Time Limit Exceeded (TLE).
- Not using references for strings in recursive calls (causes unnecessary copies).
- Using string DP for memoization of strings leads to Memory Limit Exceeded.
- Forgetting to memoize results causing recomputation.
- Incorrect reconstruction logic due to missing dp values or comparing wrong indices.

Code:
-----
*/
class Solution {
public:
    int dp[1001][1001];

    // Step 1: Compute the length of the shortest common supersequence using recursion + memoization
    int scsLength(int i, int j, string &s1, string &s2) {
        // If we've reached the end of s1, return remaining length of s2
        if(i == s1.size()) return s2.size() - j;
        // If we've reached the end of s2, return remaining length of s1
        if(j == s2.size()) return s1.size() - i;

        // If already computed, return cached value
        if(dp[i][j] != -1) return dp[i][j];

        // If characters match, take one and move both indices
        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + scsLength(i+1, j+1, s1, s2);
        } else {
            // If not matching, take minimum of two options:
            // 1. Add s1[i] and move i
            // 2. Add s2[j] and move j
            return dp[i][j] = 1 + min(scsLength(i+1, j, s1, s2), scsLength(i, j+1, s1, s2));
        }
    }

    // Step 2: Reconstruct the actual shortest common supersequence string using dp table
    void buildSCS(int i, int j, string &s1, string &s2, string &result) {
        // If s1 is exhausted, append remaining s2
        if(i == s1.size()) {
            result += s2.substr(j);
            return;
        }
        // If s2 is exhausted, append remaining s1
        if(j == s2.size()) {
            result += s1.substr(i);
            return;
        }

        // If characters match, include character once and move both pointers
        if(s1[i] == s2[j]) {
            result += s1[i];
            buildSCS(i+1, j+1, s1, s2, result);
        }
        // Else, choose the path with smaller dp value to get shorter SCS
        else if(dp[i+1][j] < dp[i][j+1]) {
            result += s1[i];         // take from s1
            buildSCS(i+1, j, s1, s2, result);
        } else {
            result += s2[j];         // take from s2
            buildSCS(i, j+1, s1, s2, result);
        }
    }

    // Main function to return the shortest common supersequence
    string shortestCommonSupersequence(string s1, string s2) {
        memset(dp, -1, sizeof(dp));          // initialize dp array with -1
        scsLength(0, 0, s1, s2);              // fill dp table

        string result;
        buildSCS(0, 0, s1, s2, result);       // build the actual SCS from dp table
        return result;
    }
};

/*
Time Complexity:
----------------
O(n * m), where n = length of s1, m = length of s2, due to memoization avoiding repeated subproblems.

Space Complexity:
-----------------
O(n * m) for the dp array + O(n + m) for the recursion stack (worst case).

*/
