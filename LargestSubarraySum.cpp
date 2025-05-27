/*
Problem:
Given an integer array `nums`, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Example:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Approach:
- Use Kadane’s Algorithm.
- Initialize `maxi` as the first element which will hold the result.
- Use `lmax` (local maximum) to track the maximum sum ending at the current index.
- For each element from index 1 to n-1:
    - Update `lmax` as max of (current element, lmax + current element).
    - Update `maxi` if `lmax` is greater.
- Finally, return `maxi`.

Time Complexity: O(n) — only one pass through the array.
Space Complexity: O(1) — uses constant space.
*/

int maxSubArray(vector<int>& nums) {
    int maxi = nums[0];      // Stores the overall maximum subarray sum
    int lmax = nums[0];      // Stores the current subarray sum ending at current index
    int n = nums.size();

    for (int i = 1; i < n; i++) {
        lmax = max(lmax + nums[i], nums[i]); // Either extend the subarray or start new from nums[i]
        maxi = max(maxi, lmax);              // Update global max if current is larger
    }

    return maxi;
}
