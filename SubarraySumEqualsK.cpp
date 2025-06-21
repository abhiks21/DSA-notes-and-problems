// ✅ PROBLEM: Count Subarrays with Sum = K

/*
🧠 Description:
Given an array of integers and an integer `k`, count the total number of **continuous subarrays** that sum up to `k`.

🧪 Example:
Input:  nums = [1, 2, 3], k = 3  
Output: 2  
Explanation: [1, 2] and [3] both sum to 3

---

🧩 Approach:
- Use prefix sum and a hashmap to track the number of times a prefix sum has occurred.
- For current prefix sum `sum`, if `sum - k` has appeared before, then the subarray between that index and current sums to `k`.

🔁 Intuition:
If `sum[j] - sum[i] = k`, then subarray (i+1 to j) has sum `k` ⇒ count how often `sum - k` has occurred.

📦 Data Structures Used:
- `unordered_map<int, int>` → stores frequency of prefix sums.

---

🧱 STEPS:
1. Initialize `sum = 0`, `count = 0`, and `mp[0] = 1` for base case.
2. Loop over the array:
    - Add current number to `sum`
    - If `mp[sum - k]` exists, it means there's a subarray ending at current index with sum `k`
    - Add its frequency to `count`
    - Increment frequency of `sum` in map

---

✅ Code:
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;  // base case
        int sum = 0, count = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.count(sum - k)) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }

        return count;
    }
};

/*
🧠 Edge Case:
- k = 0 → means you want subarrays with total sum = 0

🕒 Time Complexity: O(n)
📦 Space Complexity: O(n)

---
🔥 Key Concepts:
- Prefix Sum
- Hashmap for frequency
- Property: sum[j] - sum[i] = k → subarray i+1 to j has sum k
*/
