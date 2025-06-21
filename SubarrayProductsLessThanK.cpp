// ✅ PROBLEM: Count Subarrays with Product Less Than K

/*
🧠 Description:
Given an array of positive integers and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

🧪 Example:
Input: arr = [10, 5, 2, 6], k = 100  
Output: 8  
Explanation:
Subarrays are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

---

🧩 Approach:
- Use sliding window to maintain a product of current subarray.
- If product >= k, shrink the window from the left.
- For each valid window [i..j], the number of valid subarrays ending at j is (j - i + 1)

📦 Data Structures:
- No extra DS needed, just two pointers and a product variable.

---

✅ Code:
*/

class Solution {
  public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        if (k <= 1) return 0;

        int i = 0;
        long long product = 1, count = 0;

        for (int j = 0; j < n; j++) {
            product *= arr[j];

            while (product >= k && i <= j) {
                product /= arr[i++];
            }

            count += (j - i + 1);
        }

        return count;
    }
};

/*
🕒 Time Complexity: O(n)
📦 Space Complexity: O(1)

🔥 Key Concepts:
- Sliding window
- Subarray product tracking
- For each window ending at j, number of valid subarrays = (j - i + 1)
*/
