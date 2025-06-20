/*
---

## ⚠️ Common Mistakes:
- ❌ Not restoring the original word after modifying characters — causes incorrect transformations.
- ❌ Not erasing the transformed word from the set **after pushing** into the queue — leads to TLE.
- ❌ Using `count++` in queue — causes incorrect increment due to post-increment.
- ❌ Returning `count` instead of `0` when no path is found.

---

## ✅ Approach (BFS):

- Use a **queue** for level-order BFS traversal.
- Use a **set** for constant-time word existence check.
- For every word, try replacing every character with `a-z` and check if it's valid.
- If valid and not visited, enqueue and erase it from the set.

---

## ⏱ Time Complexity:
- O(N * L^2), where:
  - N = number of words in `wordList`
  - L = length of each word

## 🧠 Space Complexity:
- O(N * L) for set + queue

---

## ✅ Final C++ Code (Optimized):
```cpp*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, count] = q.front();
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string original = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (word == endWord) return count + 1;
                    if (st.find(word) != st.end()) {
                        q.push({word, count + 1});
                        st.erase(word); // ❗️ erase after pushing
                    }
                }
                word = original; // ✅ restore original word
            }
        }
        return 0;
    }
};
