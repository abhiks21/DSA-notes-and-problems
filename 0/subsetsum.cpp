/*
🧠 Problem: Subset Sum Problem

Given a set of non-negative integers `arr[]` and a value `sum`, 
the task is to determine if there is a subset of the given set 
with sum equal to `sum`.

-----------------------------------
🧩 Approach: Recursion + Memoization (Top-Down DP)

We try to build the sum using recursion with choices:
- Either include the current element if it is ≤ sum.
- Or exclude it.

To avoid recomputation, we use a 2D DP array to memoize subproblem results.
Here, `dp[i][j]` denotes whether it's possible to achieve sum `j` using the first `i` elements.

Base Cases:
- If `sum == 0`, return true (empty subset exists).
- If `n == 0`, return false (no elements left to use).

-----------------------------------
✅ Code:
*/

class Solution {
  public:
  // dp[n][sum] => whether we can form 'sum' with first 'n' elements
  int dp[202][10002];
  
  // Recursive function with memoization
  bool solve(int n, vector<int>& arr, int sum){
      // Base case: sum is achieved
      if(sum == 0) return 1;

      // Base case: no items left
      if(n == 0) return 0;

      // Return already computed result
      if(dp[n][sum] != -1) return dp[n][sum];

      // Choice: include or exclude the current element
      if(arr[n-1] <= sum){
          // Include arr[n-1] or don't include
          return dp[n][sum] = (solve(n-1, arr, sum - arr[n-1]) || solve(n-1, arr, sum));
      }
      else{
          // Cannot include arr[n-1], move on
          return dp[n][sum] = solve(n-1, arr, sum);
      }
  }

  //Driver function
  bool isSubsetSum(vector<int>& arr, int sum) {
      int n = arr.size();

      // Initialize dp with -1
      memset(dp, -1, sizeof(dp));

      return solve(n, arr, sum);
  }
};

/*-----------------------------------
⏱️ Time Complexity: O(n * sum)
- Each subproblem (n, sum) is solved at most once due to memoization.

🗃️ Space Complexity: O(n * sum)
- For memoization table `dp[n+1][sum+1]`.

-----------------------------------
📌 Notes:
- Suitable for constraints where `n <= 200` and `sum <= 10^4`.
- Classic DP problem often used in 0/1 Knapsack variations.
```*/
