// Problem: Climbing Stairs
// You are climbing a staircase. It takes 'n' steps to reach the top.
// Each time you can either climb 1 or 2 steps.
// Return the number of distinct ways to reach the top.

// Approach:
// - Use recursion to explore all possible ways to reach the top.
// - At each step, we have two choices:
//     1. Take 1 step -> solve(n-1)
//     2. Take 2 steps -> solve(n-2)
// - Base Cases:
//     - If n == 0: One valid way (you’re at the top).
//     - If n < 0: No way (invalid path).
// - Combine results of both choices.

int climbStairs(int n) {
    // Base case: one valid way to stay at step 0
    if (n == 0) return 1;

    // Base case: no way to reach negative steps
    if (n < 0) return 0;

    // Recursive step: take 1 or 2 steps
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// Time Complexity: O(2^n)
// - Each call branches into two more calls (like a binary tree).
// - Exponential growth due to overlapping subproblems.

// Space Complexity: O(n)
// - Due to the recursion call stack depth (max depth = n).
