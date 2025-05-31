/*
📘 Problem: Josephus Problem
----------------------------
Given `n` people standing in a circle and eliminating every `k`-th person, find the position of the last person remaining.

🎯 Goal:
--------
Return the 1-based index of the last person remaining.

🧠 Concept:
-----------
This is a classic **recursive problem** that can also be solved iteratively.
It’s based on simulating the elimination process or using a known recursive relation.

🧮 Recursive Relation:
----------------------
Let `J(n, k)` be the safe position (0-based index) among `n` people:
    J(n, k) = (J(n-1, k) + k) % n
Base case:
    J(1, k) = 0
Answer (1-based):
    J(n, k) + 1

✅ Approach: Optimal Recursion
------------------------------
- No need to simulate the entire process.
- Use mathematical recurrence.
- Time Complexity: O(n)
- Space Complexity: O(n) (because of recursion stack)

⚠️ Mistakes to avoid:
----------------------
- Not converting to 1-based index after recursion.
- Incorrect wrap-around using modulo operation.
- Using large vectors and manual erasure (costly).

🔢 Test Case Example:
---------------------
Input: n = 17, k = 16
Output: 13

*/

// ✅ Optimal Recursive Code (using recurrence)
int josephus(int n, int k) {
    if (n == 1) return 0; // base case: 0-based safe index
    return (josephus(n - 1, k) + k) % n;
}

int josephusPosition(int n, int k) {
    return josephus(n, k) + 1; // converting to 1-based index
}
