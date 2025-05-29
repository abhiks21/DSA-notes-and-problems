#include <iostream>
#include <vector>
using namespace std;

/*
🧠 PROBLEM: Combination Sum (like Leetcode 39)
Given an array of distinct integers `candidates` and a target integer `target`, return a list of all unique combinations of `candidates` where the chosen numbers sum to `target`.

Each number in `candidates` may be used an unlimited number of times.

📌 Example:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

---

✅ APPROACH:
- Use backtracking to explore all possible combinations.
- At each step, we either:
  1. Include the current element and stay at the same index (unlimited use).
  2. Skip the current element and move to the next index.
- If the running sum == target → push current combination to result.
- If running sum > target → return.

---

❌ YOUR MISTAKES:
 You moved to the next index after including the current element — which violates the condition that elements can be reused unlimited times.

---

✅ FIXED CODE WITH COMMENTS:
*/

void solve(vector<int> &candidates, int target, vector<vector<int>> &ans,
           vector<int> &temp, int i, int sum) {

    // Base case: reached the end of array
    if (i == candidates.size()) return;

    // If sum equals target, we found a valid combination
    if (sum == target) {
        ans.push_back(temp);
        return;
    }

    // Include the current element if it doesn’t exceed the target
    if (sum + candidates[i] <= target) {
        temp.push_back(candidates[i]);
        // Stay at current index for unlimited use
        solve(candidates, target, ans, temp, i, sum + candidates[i]);
        temp.pop_back(); // backtrack
    }

    // Exclude the current element and move to next
    solve(candidates, target, ans, temp, i + 1, sum);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, target, ans, temp, 0, 0);
    return ans;
}

/*
---

📈 TIME COMPLEXITY:
In worst case, O(2^T), where T = target.
Because in each step, we have two choices (include or exclude), and we can go deep until target is reached.

📦 SPACE COMPLEXITY:
- O(target) for recursion stack (depth depends on target)
- O(K * X) for output, where:
    K = average length of each combination,
    X = number of valid combinations

---

🔁 VISUALIZATION (Example: candidates = [2,3], target = 5)

            []
           /  \
         [2]   [ ]
        /   \
     [2,2]  [2]
      |
   [2,2,2]  ← skipped (sum > 5)
      |
   backtrack
      |
   [2,3] ✔️ added

Then go to [3] from root, etc...

---
*/

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);

    for (auto &v : result) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}
