/*
📌 Problem: Edit Distance (Levenshtein Distance)
------------------------------------------------
Given two strings `word1` and `word2`, return the minimum number of operations required 
to convert `word1` to `word2`.

Allowed operations:
1. Insert a character
2. Delete a character
3. Replace a character

🧪 Example:
-----------
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

✅ Approach:
------------
- Use recursion + memoization (top-down DP).
- Let solve(i, j) be the minimum number of operations to convert word1[i:] to word2[j:].
- Base cases:
  - If j == word2.size(): return remaining length of word1 (deletions)
  - If i == word1.size(): return remaining length of word2 (insertions)
- If word1[i] == word2[j], recurse to solve(i+1, j+1).
- Else try all three operations:
  1. Replace: solve(i+1, j+1) + 1
  2. Insert:  solve(i, j+1) + 1
  3. Delete:  solve(i+1, j) + 1
- Store results in dp[i][j] to avoid recomputation.

⏱️ Time Complexity:
-------------------
O(n * m), where n = length of word1, m = length of word2.

🧠 Space Complexity:
---------------------
O(n * m) for memoization table + O(n + m) recursion stack in worst case.

🧾 Code:
--------
*/
class Solution {
public:
    int dp[501][501];  // Memoization table for subproblems

    // Recursive function to compute minimum edit distance
    int solve(int i, int j, string &word1, string &word2) {
        // If end of word2 is reached, delete remaining characters in word1
        if(j == word2.size()) return word1.size() - i;

        // If end of word1 is reached, insert remaining characters from word2
        if(i == word1.size()) return word2.size() - j;

        // If already computed, return memoized value
        if(dp[i][j] != -1) return dp[i][j];

        // Characters match, move both pointers
        if(word1[i] == word2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, word1, word2);
        } else {
            // Replace operation
            int rep = solve(i + 1, j + 1, word1, word2) + 1;
            // Insert operation
            int ins = solve(i, j + 1, word1, word2) + 1;
            // Delete operation
            int del = solve(i + 1, j, word1, word2) + 1;

            // Take minimum of all three operations
            return dp[i][j] = min({rep, ins, del});
        }
    }

    // Main function
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));  // Initialize DP table
        return solve(0, 0, word1, word2);  // Start from beginning
    }
};

