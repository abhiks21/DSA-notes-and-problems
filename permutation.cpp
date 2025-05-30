// 🔒 Problem: Generate all permutations of a given list of integers.
// 📌 Constraint: -10 <= nums[i] <= 10
// ❗ Important: Elements may contain duplicates, but we want to generate all possible permutations (not necessarily unique).

// ✅ Approach:
// - Use backtracking to build all permutations by recursively adding unused elements.
// - Track which indices have been used using a boolean vector `vis` of size nums.size().
// - Backtrack by removing the last added element and marking that index as unused.

// ❌ Common Mistake:
// - Tracking used values with `vis[nums[j] + 10]` (based on values) fails for duplicates like {1, 1, 2}.
// - Correct way: Track by **indices**, not values, to ensure all valid permutations are generated.

#include <vector>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> &temp, 
           vector<bool> &vis, vector<int> &nums) {
    // 🔁 Base case: If the temporary permutation is complete
    if (temp.size() == nums.size()) {
        ans.push_back(temp); // add the current permutation
        return;
    }

    // 🔁 Try placing every unused number at the current position
    for (int j = 0; j < nums.size(); j++) {
        if (!vis[j]) { // if this index has not been used
            vis[j] = true; // mark as used
            temp.push_back(nums[j]); // choose the element

            solve(ans, temp, vis, nums); // recurse

            temp.pop_back(); // backtrack
            vis[j] = false; // unmark as used
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;       // to store all permutations
    vector<int> temp;              // current permutation
    vector<bool> vis(nums.size(), false); // visited indices

    solve(ans, temp, vis, nums);   // start backtracking
    return ans;
}

// 🧠 Time Complexity: O(n * n!) 
// - There are n! permutations of n elements.
// - Each permutation takes O(n) time to build.

// 🧠 Space Complexity: O(n) for recursion stack + O(n) for visited + O(n * n!) for result storage.
