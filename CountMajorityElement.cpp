/*
Problem:
Find the majority element in the array — the element that appears more than n/2 times.

Approach:
- Use Boyer-Moore Voting Algorithm.
- Initialize a candidate element and a count.
- Traverse the array:
  - If count is 0, update candidate to current element.
  - If current element equals candidate, increment count.
  - Else decrement count.
- Candidate at the end is the majority element.

Time Complexity: O(n) — single pass through the array.
Space Complexity: O(1) — constant extra space.
*/
int majorityElement(vector<int>& nums) {
    int count = 0;        // Counter for the current candidate
    int candidate = 0;    // Potential majority element

    for (int num : nums) {
        if (count == 0) {
            candidate = num;  // Set a new candidate
        }

        // If current number matches candidate, increment count
        if (num == candidate) {
            count++;
        } else {
            count--;          // Otherwise, cancel out a previous vote
        }
    }

    return candidate;  // Since a majority is guaranteed, return candidate
}
