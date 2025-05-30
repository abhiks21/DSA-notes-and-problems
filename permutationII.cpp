/*
===============================================
📝 Leetcode 47: Permutations II (permuteUnique)
===============================================

🔒 Problem:
Given an array nums that may contain duplicates, return all possible unique permutations in any order.

🔹 Example:
Input:  nums = [1,1,2]
Output: [[1,1,2],[1,2,1],[2,1,1]]

-------------------------------------------------
🎯 Goal:
Generate all DISTINCT permutations without duplicates.

-------------------------------------------------
✅ Approach 1: Brute-force with set<vector<int>>
-------------------------------------------------
🔧 Method:
- Use backtracking with in-place swapping
- Store permutations in a set to automatically remove duplicates

🔻 Drawbacks:
- Extra memory used by set
- Slower due to logN insertions and post-processing

🧠 Code:
    void solve(vector<int>& nums, set<vector<int>>& st, int i) {
        if (i == nums.size()) {
            st.insert(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            solve(nums, st, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        solve(nums, st, 0);
        for (auto& p : st) ans.push_back(p);
        return ans;
    }

⏱ Time Complexity: O(n! * n log(n!))
🧠 Space Complexity: O(n! + n)

-------------------------------------------------
✅ Approach 2: Optimal with Unordered_Set (Best)
-------------------------------------------------
🔧 Method:
- Perform in-place backtracking
- Use an unordered_set<int> at each recursion level to track values already used at that level
- Prevents generating duplicate branches early

🧠 Final Code:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int i) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for (int j = i; j < nums.size(); j++) {
            if (seen.count(nums[j])) continue; // skip duplicate values at this level
            seen.insert(nums[j]);
            swap(nums[i], nums[j]);
            solve(nums, ans, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }

⏱ Time Complexity: O(n! * n) (pruned by skipping duplicates)
🧠 Space Complexity: O(n) (stack) + O(n) seen set per call

-------------------------------------------------
✅ Summary:
| Approach       | Time Complexity   | Space Complexity | Avoids Duplicates Early? |
|----------------|-------------------|------------------|---------------------------|
| Set-based      | O(n! * n log(n!)) | O(n! + n)        | ❌ No                    |
| Optimal (Set)  | O(n! * n)         | O(n)             | ✅ Yes                   |

*/
