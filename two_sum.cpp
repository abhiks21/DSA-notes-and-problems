// LC - 1: Two Sum
// Problem: Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to target.

// Approach:
// 1. Use a hash map to track numbers we've seen so far and their indices.
// 2. For each number in `nums`, calculate its complement (target - current number).
// 3. Check if the complement exists in the hash map:
//    - If yes: Return the current index and the complement's stored index.
//    - If no: Store the current number and its index in the hash map.
// 4. This ensures we check pairs in a single pass without reusing the same element.

// Time Complexity: O(n) → Single iteration through the array.
// Space Complexity: O(n) → Hash map stores up to n elements in worst case.

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash; // Maps numbers to their indices
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int comp = target - nums[i]; // Required complement for current number
        
        // Check if complement exists in the hash map
        if (hash.count(comp)) {
            // Found a valid pair: current index + complement's index
            return {i, hash[comp]};
        }
        
        // Store current number and index for future checks
        hash[nums[i]] = i;
    }
    
    return {}; // Edge case (no solution, though problem guarantees one)
}

