/*
Problem: Isomorphic Strings

Description:
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
Conditions:
- Every character in s must map to one and only one character in t.
- No two characters may map to the same character, but a character may map to itself.

Approach:
- Use two hash maps (unordered_map):
  - mp1 maps characters from s to t.
  - mp2 maps characters from t to s.
- This ensures the mapping is **one-to-one and onto** (bijection).

Common Mistake in Initial Approach:
- Using only one map (e.g., `mp[s[i]] = t[i]`) may allow two characters from s to map to the same character in t.
  ➤ For example: s = "ab", t = "aa" would wrongly return true with one map.
- Missing bidirectional check breaks the isomorphism rule.

Corrected Optimal Solution:
*/

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;  // Quick length check

    unordered_map<char, char> mp1; // s -> t mapping
    unordered_map<char, char> mp2; // t -> s mapping

    for (int i = 0; i < s.size(); ++i) {
        // Check if current mapping exists and matches for both directions
        if ((mp1.count(s[i]) && mp1[s[i]] != t[i]) ||
            (mp2.count(t[i]) && mp2[t[i]] != s[i]))
            return false;

        // Insert into both maps
        mp1[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }

    return true;  // Strings are isomorphic
}

/*
Time Complexity:  O(n)
- We traverse both strings once, and each map operation is O(1) on average.

Space Complexity: O(1)
- Maximum of 256 entries per map due to finite ASCII characters, hence constant space.
*/
