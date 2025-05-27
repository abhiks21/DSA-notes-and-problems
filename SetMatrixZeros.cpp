/*
Problem:
Given a m x n matrix, if an element is 0, set its entire row and column to 0 in-place.

Approach:
- Use the first row and first column of the matrix to store markers indicating which rows/columns should be set to zero.
- Two boolean variables track whether the first row and column themselves originally had any zero.
- First pass: set the markers.
- Second pass: set cells to 0 based on those markers.
- Finally, zero out the first row and/or column if needed.

Time Complexity: O(m * n)
Space Complexity: O(1) (no extra space used except 2 boolean flags)
*/

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();       // Number of rows
    int n = matrix[0].size();    // Number of columns
    bool firstRow = false, firstCol = false;

    // Step 1: Check if the first row has any zero
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRow = true;
            break;
        }
    }

    // Step 2: Check if the first column has any zero
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstCol = true;
            break;
        }
    }

    // Step 3: Use first row and first column to mark zeros
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;  // Mark corresponding row
                matrix[0][j] = 0;  // Mark corresponding column
            }
        }
    }

    // Step 4: Set matrix[i][j] to 0 if either row or column is marked
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 5: Handle first row if it had any zeros
    if (firstRow) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 6: Handle first column if it had any zeros
    if (firstCol) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}
