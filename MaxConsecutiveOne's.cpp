int findMaxConsecutiveOnes(vector<int>& nums) {
    /*
    Problem:
    Given a binary array, find the maximum number of consecutive 1s in the array.

    Approach:
    - Traverse the array while counting consecutive 1s.
    - If a 0 is encountered, update the maximum and reset the counter.
    - Continue until the end of the array.

    ⚠️ Common Mistake (Fixed Here):
    - In `while(nums[i] && i < n)`, the order of condition is wrong.
    - Accessing `nums[i]` before checking `i < n` may cause an out-of-bounds error.
    - ✅ Correct condition: `while(i < n && nums[i])`

    Time Complexity: O(N)
    Space Complexity: O(1)
    */

    int n = nums.size();           // Total elements in the array
    int i = 0, count = 0;          // i for index, count for current streak of 1s
    int maxi = 0;                  // To track the maximum number of consecutive 1s

    while(i < n) {
        while(i < n && nums[i]) {  // Count 1s until a 0 or end is encountered
            count++;
            i++; 
        }
        maxi = max(count, maxi);   // Update max if current count is higher
        count = 0;                 // Reset count for the next sequence
        i++;                       // Move past the 0
    }

    return maxi;
}
