/*
Problem:
    Given an array `nums` of distinct integers, return all possible permutations.

Previous Approach:
    - Used a boolean `vis[]` array to track visited elements.
    - Used a separate temporary vector `temp` to build each permutation.
    - Time Complexity: O(n * n!)
    - Space Complexity: O(n) extra for `vis` and `temp` (besides output)

Optimized Approach:
    - Eliminates the need for `vis[]` and `temp[]` by modifying `nums` in-place.
    - Uses swapping to fix an element at the current index.
    - After recursive call, backtracks by swapping back.

Approach:
    - Fix the current index by swapping it with every index ≥ current.
    - Recursively generate permutations of the remaining subarray.
    - Backtrack by restoring the original state (swap back).

Recurrence Relation:
    T(n) = n * T(n-1) + O(n)
    Base case: T(1) = O(1)
    Total Time Complexity = O(n * n!)  — optimal for permutation generation.

Time Complexity:
    - O(n * n!)
        - n! total permutations
        - O(n) time to copy each permutation to the result

Space Complexity:
    - O(n) recursion depth (call stack)
    - O(n * n!) output space for storing permutations
    - No extra space like `vis[]` or `temp[]` used

Code:
*/

void solve(vector<vector<int>>& ans, vector<int>& nums, int index) {
    // Base Case: A complete permutation is formed
    if (index == nums.size()) {
        ans.push_back(nums);  // Copy the current permutation
        return;
    }

    // Try all candidates for the current position
    for (int j = index; j < nums.size(); j++) {
        swap(nums[index], nums[j]);         // Fix nums[j] at current index
        solve(ans, nums, index + 1);        // Recurse for next index
        swap(nums[index], nums[j]);         // Backtrack: undo the swap
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    solve(ans, nums, 0);  // Start from index 0
    return ans;
}
