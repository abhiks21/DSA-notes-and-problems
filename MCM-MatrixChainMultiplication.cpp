/*
🧩 Problem:
Matrix Chain Multiplication – Given an array arr[] of size n, 
where arr[i-1] x arr[i] represents the dimension of the ith matrix,
find the minimum number of scalar multiplications needed to multiply the entire chain.

🧠 Example:
Input: arr = {10, 20, 30, 40}
Matrix A: 10x20
Matrix B: 20x30
Matrix C: 30x40

Two ways to multiply:
1. (A*B)*C → (10x20x30) + (10x30x40) = 6000 + 12000 = 18000
2. A*(B*C) → (20x30x40) + (10x20x40) = 24000 + 8000 = 32000

✅ Minimum = 18000

⚙️ Approach:
- Use recursion with memoization.
- Try all possible splits between i and j.
- Add cost of splitting at each k: 
  cost = solve(i,k) + solve(k+1,j) + arr[i-1]*arr[k]*arr[j]

❌ Mistake to avoid:
Do NOT write arr[i-1] * arr[j] * arr[k] ➤ this is incorrect.
✅ Correct: arr[i-1] * arr[k] * arr[j]

✅ Code:
*/

class Solution {
  public:
    int dp[101][101]; // Memoization table

    // Recursive function to compute min cost from i to j
    int solve(int i, int j, vector<int> &arr){
        if(i >= j) return 0; // Base case: 0 or 1 matrix => no cost
        if(dp[i][j] != -1) return dp[i][j]; // Return memoized result

        int mini = INT_MAX;
        for(int k = i; k < j; k++){
            // Cost of splitting at k:
            // Left part: (i to k), Right part: (k+1 to j)
            int cost = solve(i, k, arr) + solve(k+1, j, arr) 
                     + arr[i-1] * arr[k] * arr[j]; // Cost of multiplying resulting matrices
            mini = min(mini, cost); // Track minimum cost
        }
        return dp[i][j] = mini; // Store result
    }

    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp)); // Initialize DP table with -1
        return solve(1, n-1, arr); // Call from index 1 to n-1
    }
};

/*
⏱️ Time Complexity: O(n^3)
📦 Space Complexity: O(n^2)
*/
