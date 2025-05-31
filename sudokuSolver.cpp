/*
--------------------------------------------
🧠 Problem: Sudoku Solver (Leetcode 37)
--------------------------------------------
You are given a 9x9 partially filled Sudoku board. Fill the board so that every row, column, 
and 3x3 sub-box contains all digits from 1 to 9 exactly once. You must use backtracking.

--------------------------------------------
🚀 Approach:
--------------------------------------------
1. For every empty cell ('.'), try placing digits 1 to 9.
2. Use `isfree()` function to check if placing a digit is valid:
   - Check current row
   - Check current column
   - Check current 3x3 box
3. If valid, place the digit and recursively move forward.
4. If further recursion fails (returns false), backtrack and try the next number.
5. Return true only if the entire board is filled successfully.

--------------------------------------------
❗ Bug fixed:
--------------------------------------------
- Initially, we missed returning `true/false` properly from the `solve()` function.
- Without returning `true` when the board is solved, the recursion continues unnecessarily.
- Also, the inner loop to check 3x3 boxes had wrong use of `i<i+3`, which led to infinite loop.
  Fixed by calculating fixed boundaries using: `fi = i+3`, `fj = j+3`.

--------------------------------------------
📦 Time & Space Complexity:
--------------------------------------------
⏱ Time: O(9^(n*n)) in worst case since for each empty cell, we try 9 digits. 
         But pruning due to constraints improves practical performance.
📦 Space: O(1) extra (modifies board in-place), recursion stack goes up to O(81).

*/

class Solution {
public:
    // Function to check if placing num is valid at (row, col)
    bool isfree(int row, int col, vector<vector<char>>& board, int num) {
        char ch = '0' + num;
        int n = board.size();
        
        // Check row
        for (int j = 0; j < n; j++) {
            if (board[row][j] == ch) return false;
        }

        // Check column
        for (int i = 0; i < n; i++) {
            if (board[i][col] == ch) return false;
        }

        // Check 3x3 sub-grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == ch) return false;
            }
        }

        return true;
    }

    // Recursive backtracking function to solve board
    bool solve(int i, int j, int n, vector<vector<char>>& board) {
        if (i == n) return true;  // Board completed

        if (j == n) return solve(i + 1, 0, n, board);  // Move to next row

        if (board[i][j] != '.') return solve(i, j + 1, n, board);  // Skip filled cell

        for (int num = 1; num <= 9; num++) {
            if (isfree(i, j, board, num)) {
                board[i][j] = '0' + num;  // Place number
                if (solve(i, j + 1, n, board)) return true;  // Recur
                board[i][j] = '.';  // Backtrack
            }
        }

        return false;  // No valid number found
    }

    // Main function
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(0, 0, n, board);
    }
};
