// ✅ PROBLEM: Count Subarrays with Sum = 0

/*
🧠 Description:
Given an array of integers, count the total number of subarrays that sum up to zero.

🧪 Example:
Input:  arr = [0, 0, 5, 5, 0, 0]
Output: 6

Explanation:
Zero-sum subarrays are:
[0], [0], [0, 0], [5, 5, 0, 0], [0], [0, 0]

---

🧩 Approach:
- Use prefix sum and a hashmap to store the frequency of prefix sums.
- If the same prefix sum occurs more than once, it means the elements between those indices sum to zero.
- Also handle the special case of prefix sum being zero (from index 0).

🔁 Intuition:
If `sum[j] - sum[i] = 0`, then subarray from i+1 to j has sum 0 ⇒ we store frequency of sums.

📦 Data Structures Used:
- `unordered_map<int, int>` to store frequency of prefix sums.

---

🧱 STEPS:
1. Initialize `sum = 0`, `count = 0`, and map with {0: 1}.
2. Traverse array:
    - Add current element to `sum`
    - Add `mp[sum]` to count (number of times this prefix sum occurred before)
    - Increment `mp[sum]`

---

✅ Code:
*/

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        mp[0] = 1;

        for (int num : arr) {
            sum += num;
            count += mp[sum];
            mp[sum]++;
        }
        return count;
    }
};

/*
🧠 Edge Case:
- All elements are 0 → number of zero-sum subarrays = n*(n+1)/2

🕒 Time Complexity: O(n)
📦 Space Complexity: O(n)

---
🔥 Important Concepts:
- Prefix Sum
- Hashmap for frequency tracking
- Subarray sum formula: sum[j] - sum[i] = target (0 here)
*/
