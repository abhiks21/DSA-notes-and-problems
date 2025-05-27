/*
🟩 Problem:
Sort an array consisting only of 0s, 1s, and 2s **in-place** (without using any extra space).  
Example: [2,0,2,1,1,0] → [0,0,1,1,2,2]

🟩 Approach: (Dutch National Flag Algorithm)
- Use three pointers: `low`, `mid`, and `high`.
- `low` tracks position of 0s, `mid` is current element, `high` tracks position of 2s.
- Traverse the array:
  - If nums[mid] == 0 → swap with low, increment both.
  - If nums[mid] == 1 → move ahead (mid++).
  - If nums[mid] == 2 → swap with high and **only decrement high** (do NOT increment mid immediately).

🟥 Mistake (common bug):
- ❌ In the `else` block (nums[mid] == 2), doing `mid++` is incorrect.
- Why? After swapping, the value at mid could still be 2, 1, or 0 — we need to check it again.

🕒 Time Complexity: O(N) — one pass through the array.
🧠 Space Complexity: O(1) — constant space used.
*/

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;       // ✅ Correct: do not increment mid here
        }
    }
}
