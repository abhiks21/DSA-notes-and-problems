/*## 📘 Problem: Frequency Sort (Leetcode 451)

### 🔹 Description:
Sort the characters in a string such that characters with higher frequency come first.

---

### 🔸 Example:

Input: `"tree"`  
Output: `"eetr"` or `"eert"`

Explanation:  
- Frequencies: `t → 1`, `r → 1`, `e → 2`  
- Sorted by frequency → e appears first

---

### 🔧 Approach:

1. Count frequency of each character using a hashmap
2. Move the entries into a vector of pairs
3. Sort the vector in descending order of frequency
4. Rebuild the output string by repeating each character `frequency` times

---

### ⏱️ Time Complexity:
- Counting frequencies: **O(n)**
- Sorting: **O(k log k)** where k = number of unique characters (max 26 for lowercase)
- Building result string: **O(n)**  
**→ Total: O(n + k log k)**

### 📦 Space Complexity:
- Hash map: **O(k)**  
- Vector of pairs: **O(k)**  
- Output string: **O(n)**  
**→ Total: O(n)**

---

### ✅ Code:
```cpp*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        vector<pair<char, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
            return a.second > b.second;  // sort by frequency descending
        });

        string ans = "";
        for (auto it : vec) {
            ans += string(it.second, it.first); // repeat char it.second times
        }

        return ans;
    }
};
```
