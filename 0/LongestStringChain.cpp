/*
🧩 Problem: Longest String Chain (Leetcode 1048)

🔗 Description:
Given a list of words, each word can be a part of a chain if by
removing exactly one character from it,the resulting word is also
present in the list and part of a chain. The goal is to find the
length of the longest possible chain.

📥 Input:
vector<string> words

📤 Output:
int -> maximum length of word chain

-----------------------------------------
🧠 Approach: Top-down DP with Recursion + Memoization

1. Sort the words by length to ensure smaller words come before longer ones.
2. For each word, try to include it in the chain if it is one character longer
    than a previously selected word and only differs by one character.
3. Use recursion with memoization to explore all valid chains.
4. Use a helper `check()` to verify if a word can follow the previous one in the chain.

-----------------------------------------
✅ Code:
*/

class Solution {
public:
    int dp[1001][1002];

    // Check if shorter is a valid predecessor of longer
    bool check(const string& longer, const string& shorter) {
        if (longer.size() != shorter.size() + 1) return false;

        int i = 0, j = 0;
        while (i < longer.size()) {
            if (j < shorter.size() && longer[i] == shorter[j]) {
                i++; j++;
            } else {
                i++; // skip one char in longer
            }
        }
        return j == shorter.size();
    }

    // Recursive solve function with memoization
    int solve(int i, int p, vector<string>& words) {
        if (i >= words.size()) return 0;
        if (dp[i][p + 1] != -1) return dp[i][p + 1];

        int take = 0;
        if (p == -1 || check(words[i], words[p])) {
            take = 1 + solve(i + 1, i, words);
        }

        int skip = solve(i + 1, p, words);
        return dp[i][p + 1] = max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        memset(dp, -1, sizeof(dp));
        return solve(0, -1, words);
    }
};

/*
-----------------------------------------
⏱ Time Complexity:
O(N^2 * L)
- N: number of words
- L: max length of a word
- check() runs in O(L) for each pair

🧠 Space Complexity:
O(N^2) for memoization table + recursion stack

-----------------------------------------
📌 Key Insights:
- This problem is similar to Longest Increasing Subsequence (LIS) where the relation between words is based on character addition.
- Sorting by length is crucial to ensure that we only check valid predecessor-successor relationships.
*/
