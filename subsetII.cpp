#include <bits/stdc++.h>
using namespace std;

/*
🔵 PROBLEM:
Given an integer array `nums` that may contain duplicates, return all possible subsets (the power set) without duplicate subsets.

📌 Example:
Input: [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

------------------------------------------------

✅ APPROACH:
1. Sort the input array to ensure duplicates are adjacent.
2. Use recursive backtracking to explore all subset possibilities.
3. Store each unique subset in a `set<vector<int>>` to automatically avoid duplicates.
4. Convert the set into a vector of vectors to return.

------------------------------------------------

❌ MISTAKES IN ORIGINAL CODE:
1. Used `unordered_set<vector<int>>` which is invalid in C++ because `vector<int>` does not have a hash function by default.
2. Did not sort the array before backtracking, which led to permutations like [2,1] and [1,2] being treated as different subsets.

------------------------------------------------

🛠️ FIXES:
- Replaced `unordered_set` with `set`.
- Sorted the input array before starting recursion.

------------------------------------------------
*/

void solve(vector<int> &nums, int i, set<vector<int>> &st, vector<int> &temp) {
    // Base case: reached the end of the array
    if (i == nums.size()) {
        st.insert(temp); // Insert subset into set to avoid duplicates
        return;
    }

    // Include current element
    temp.push_back(nums[i]);
    solve(nums, i + 1, st, temp);
    temp.pop_back(); // Backtrack

    // Exclude current element
    solve(nums, i + 1, st, temp);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> st;         // To store unique subsets
    vector<vector<int>> ans;     // Final answer
    vector<int> temp;            // Current subset

    sort(nums.begin(), nums.end()); // Sort to ensure duplicates are adjacent

    solve(nums, 0, st, temp);

    // Convert set to vector
    for (auto& subset : st) {
        ans.push_back(subset);
    }

    return ans;
}

/*
------------------------------------------------
🕒 TIME COMPLEXITY:
- O(2^n * k * log(2^n)), where:
  - 2^n is the number of subsets
  - k is the average length of each subset
  - log(2^n) for inserting into the set

🧠 SPACE COMPLEXITY:
- O(2^n * k) for storing all unique subsets
- O(n) auxiliary space due to recursion stack

✅ Notes:
- You can optimize further by avoiding use of `set` and using index-based pruning directly in recursion.
*/
