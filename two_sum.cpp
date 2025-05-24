// LC - 1: Two Sum
// Problem: Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to target.

// Time Complexity: O(n)
// Space Complexity: O(n)

vector<int> twoSum(vector<int>& nums, int target) {
    // Create a hash map to store {number, index}
    unordered_map<int, int> hash;
    int n = nums.size();

    // Iterate over the array
    for (int i = 0; i < n; i++) {
        int comp = target - nums[i]; // Find the complement

        // Check if complement exists in the map
        if (hash.count(comp)) {
            // If found, return the pair of indices
            return {i, hash[comp]};
        }

        // Otherwise, store the current number and its index
        hash[nums[i]] = i;
    }

    // Return empty if no valid pair is found
    return {};
}
