/*
==========================================
🧠 N-Queens Problem - Full Notes & Code
==========================================

📌 Problem:
------------
Place N queens on an N×N chessboard such that no two queens attack each other. 
Return all distinct board configurations.

✅ Approach:
------------
- Use backtracking to place queens row by row.
- For each row, try every column and check if it's safe.
- To optimize, maintain 3 arrays for:
    • col[j]          -> column is occupied
    • diag1[row - col + n - 1] -> left diagonal is occupied
    • diag2[row + col] -> right diagonal is occupied
- This reduces safety check from O(n) to O(1).

❌ Common Mistakes:
-------------------
- Using isSafe() with loops to scan board every time.
- Forgetting proper base condition or backtracking step.

✅ Learning:
------------
- Backtracking combined with hashing gives optimal performance.
- Use mathematical indices to map diagonals efficiently.

🧮 Time Complexity:
--------------------
- O(N!) – Each row has at most N choices, but constrained by other queens.

🧮 Space Complexity:
---------------------
- O(N^2) for board storage
- O(N) for col, diag1, diag2 arrays

=========================================================
*/

class Solution {
public:
    // Recursive backtracking function
    void solve(int row, int n, vector<string>& board,
               vector<int>& col, vector<int>& diag1, vector<int>& diag2,
               vector<vector<string>>& ans) {
        // Base case: All rows filled, valid board
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try all columns in current row
        for (int j = 0; j < n; ++j) {
            // Skip if column or diagonals are already blocked
            if (col[j] || diag1[row - j + n - 1] || diag2[row + j])
                continue;

            // Place queen
            board[row][j] = 'Q';
            col[j] = diag1[row - j + n - 1] = diag2[row + j] = 1;

            // Recurse to next row
            solve(row + 1, n, board, col, diag1, diag2, ans);

            // Backtrack: Remove queen and unmark
            board[row][j] = '.';
            col[j] = diag1[row - j + n - 1] = diag2[row + j] = 0;
        }
    }

    // Main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        // Create empty board
        vector<string> board(n, string(n, '.'));

        // Hash arrays to track occupied cols and diagonals
        vector<int> col(n, 0);            // Columns
        vector<int> diag1(2 * n - 1, 0);  // Left diagonals
        vector<int> diag2(2 * n - 1, 0);  // Right diagonals

        // Begin solving from first row
        solve(0, n, board, col, diag1, diag2, ans);
        return ans;
    }
};

/*
=========================================================
📚 Summary Table:

| Concept         | Explanation                                  |
|-----------------|----------------------------------------------|
| Algorithm       | Backtracking                                 |
| Optimization    | Hash arrays for O(1) validity check          |
| Key Learning    | Use diagonals + column hashing for pruning   |
| TC              | O(N!)                                        |
| SC              | O(N^2) for board, O(N) for tracking arrays   |
=========================================================
*/
