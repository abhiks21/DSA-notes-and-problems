/*
❓ Problem: 
Given integers n (length of array), m (maximum number allowed in array), and k (search cost),
return the number of arrays consisting of numbers from 1 to m of length n such that the search cost is exactly k.
The search cost increases every time we insert a number greater than all previous elements.
Return the answer modulo 10^9 + 7.

💡 Approach:
We use recursion with memoization (top-down DP).
At each index, we try all values from 1 to m. If a value is greater than the current max,
we increase the search cost. If not, we keep the cost the same.
We memoize using 3 states:
- index in array (0 to n)
- current search cost (0 to k)
- current maximum element seen so far (0 to m)

✅ Code:
*/

class Solution {
public:
    int N, M, K;
    const int MOD = 1e9 + 7;

    // dp[index][max_so_far][cost_so_far] = number of valid arrays from this state
    int dp[51][101][51];

    // Recursive function with memoization
    int solve(int ind, int searchcost, int maxel) {
        // Base case: If array is fully constructed
        if (ind == N) {
            // Valid only if we used exactly K comparisons (search cost)
            return (searchcost == K) ? 1 : 0;
        }

        // Return cached value if already computed
        if (dp[ind][maxel][searchcost] != -1)
            return dp[ind][maxel][searchcost];

        int result = 0;

        // Try placing each number from 1 to M at current index
        for (int i = 1; i <= M; i++) {
            if (i > maxel) {
                // i is a new max, so increase search cost
                if (searchcost + 1 <= K)
                    result = (result + solve(ind + 1, searchcost + 1, i)) % MOD;
            } else {
                // i is <= max so far, doesn't increase search cost
                result = (result + solve(ind + 1, searchcost, maxel)) % MOD;
            }
        }

        // Store and return result for current state
        return dp[ind][maxel][searchcost] = result;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;

        // Initialize dp array with -1 (uncomputed state)
        memset(dp, -1, sizeof(dp));

        // Start building from index 0, cost 0, and max element 0
        return solve(0, 0, 0);
    }
};

/*
🧠 Time Complexity: O(n * m * k * m)
- For each (index, max_element, cost) state, we loop over m possible values.
- Total states = n * m * k, and each tries m values => O(n * m * k * m)

💾 Space Complexity: O(n * m * k)
- Due to 3D DP array to store results.
*/
