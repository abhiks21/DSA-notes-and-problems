// ✅ PROBLEM: Minimum Size Subarray Sum (Leetcode 209)

/*
🧠 Description:
Given an array of positive integers `nums` and a target integer `target`,
return the minimal length of a contiguous subarray of which the sum is ≥ `target`.

If no such subarray exists, return 0.

---

🧪 Example:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has sum ≥ 7 and length 2.

---

✅ APPROACH: Sliding Window (Variable Size)
- Expand the window by moving `j` and adding to `sum`.
- When `sum >= target`, shrink the window by moving `i` while updating `mini`.

---

🧩 KEY OBSERVATIONS:
- Only works with **positive numbers**, because shrinking always reduces sum.
- Classic use-case for sliding window: "minimum length", "at least X sum".

---

🕒 Time Complexity: O(n)
📦 Space Complexity: O(1)

---

✅ FINAL CODE (with inline comments):
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;
        int i = 0, j = 0, sum = 0;

        while (j < nums.size()) {
            sum += nums[j];  // expand window by adding nums[j]

            // While current window sum is enough, try shrinking from left
            while (sum >= target && i <= j) {
                mini = min(mini, j - i + 1);  // update minimum length
                sum -= nums[i];  // shrink window from left
                i++;
            }

            j++;  // move right end of window forward
        }

        return mini == INT_MAX ? 0 : mini;
    }
};

/*
🔥 TAKEAWAYS:
- Sliding window = great for fixed or variable size contiguous subarray problems.
- Use while-loop inside to shrink window when condition (sum >= target) is met.
- If all numbers are positive, this approach guarantees correctness in O(n).
*/
