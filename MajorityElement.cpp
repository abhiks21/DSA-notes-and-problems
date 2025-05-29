/*
PROBLEM: Majority Element II (LeetCode 229)
Given an integer array of size n, find all elements that appear more than ⌊n/3⌋ times.
The algorithm should run in linear time and O(1) space.

APPROACH: Boyer-Moore Majority Vote Algorithm (Extended)
- Key insight: There can be at most 2 elements that appear more than n/3 times
- Phase 1: Find 2 potential candidates using voting mechanism
- Phase 2: Verify if these candidates actually appear more than n/3 times

TIME COMPLEXITY: O(n) - Two passes through the array
SPACE COMPLEXITY: O(1) - Only using constant extra space (excluding output)
*/

vector<int> majorityElement(vector<int>& nums) {
    // Initialize two different candidates (any values work initially)
    int c1 = 0, c2 = 1; 
    int cnt1 = 0, cnt2 = 0; // Vote counts for each candidate
    
    // Phase 1: Find potential majority candidates using Boyer-Moore voting
    for (int num : nums) {
        if (num == c1) {
            cnt1++; // Vote for candidate 1
        }
        else if (num == c2) {
            cnt2++; // Vote for candidate 2
        }
        else if (cnt1 == 0) {
            // Replace candidate 1 with current number
            c1 = num;
            cnt1 = 1;
        }
        else if (cnt2 == 0) {
            // Replace candidate 2 with current number
            c2 = num;
            cnt2 = 1;
        }
        else {
            // Current number doesn't match either candidate
            // Decrease both counts (voting against both)
            cnt1--;
            cnt2--;
        }
    }
    
    // Phase 2: Verify the candidates by counting their actual occurrences
    cnt1 = cnt2 = 0;
    for (int num : nums) {
        if (num == c1) cnt1++;       // Count occurrences of candidate 1
        else if (num == c2) cnt2++;  // Count occurrences of candidate 2
    }
    
    // Build result array with elements that appear more than n/3 times
    vector<int> ans;
    if (cnt1 > nums.size() / 3) ans.push_back(c1);
    if (cnt2 > nums.size() / 3) ans.push_back(c2);
    
    return ans;
}
