bool check(vector<int>& nums) {
    /*
    ✅ Problem:
    - Given an array `nums`, check if it is a rotated version of a non-decreasing sorted array.
    - Rotation can be 0 or more times.
    - A valid rotated sorted array can have at most one "drop" (nums[i] > nums[i+1]).

    ✅ Approach:
    - Traverse the array and count the number of times nums[i] > nums[i+1].
    - If this count exceeds 1, return false — it can't be a rotated sorted array.
    - After the loop, return true if either:
        - the array has no drop, OR
        - the array has 1 drop and satisfies the rotation condition.

    🕒 Time Complexity: O(n) — One complete pass through the array.
    💾 Space Complexity: O(1) — Only constant extra space used.
    */

    int i = 0;
    int n = nums.size();
    int cnt = 0;  // To count number of drops (nums[i] > nums[i+1])

    // Count how many times the sorted order breaks
    while (i < n - 1) {
        if (nums[i] > nums[i + 1]) {
            cnt++;
            if (cnt > 1) return false;  // More than one drop => not a rotated sorted array
        }
        i++;
    }

    // If there's exactly one drop, check if it is a valid rotation
    return nums[0] < nums[n - 1] && cnt > 0 ? 0 : 1;
}
