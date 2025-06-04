/*
Problem:
--------
Count all palindromic substrings in a given string.  
A palindromic substring is a contiguous sequence of characters which reads the same backward as forward.

Example:
--------
Input: "aaa"  
Output: 6  
Explanation: The palindromic substrings are:  
"a" (3 times), "aa" (2 times), "aaa" (1 time)

Approach:
---------
1. Use recursion to generate all possible substrings by varying the start index.
2. For each substring [start...end], check if it is a palindrome.
3. If palindrome, increment the count.
4. Recursively move the start index forward to cover all substrings.
5. No memoization needed because each substring is checked only once.

Common Mistakes:
----------------
- Confusing subsequences with substrings (subsequences are non-contiguous).
- Counting empty substrings (should not count empty string).
- Forgetting to backtrack or reset state when using recursive approaches that modify temporary structures.

Time Complexity:
----------------
O(n^3) in worst case  
- O(n^2) substrings  
- O(n) palindrome check per substring

Space Complexity:
-----------------
O(n) recursion stack (due to recursion depth)  
O(1) additional space (besides input and counters)

Code:
-----
*/class Solution {
public:
    int count = 0;

    // Helper function to check if substring s[left...right] is palindrome
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    // Recursive function to consider substrings starting from index 'start'
    void countPalindromicSubstrings(int start, string &s) {
        if (start == s.size()) return;

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                count++;
            }
        }

        countPalindromicSubstrings(start + 1, s);
    }

    int countSubstrings(string s) {
        count = 0;
        countPalindromicSubstrings(0, s);
        return count;
    }
};

