/*
----------------------------------------
🔰 Problem: Shortest Distance in a Binary Matrix
----------------------------------------

Given a matrix `A` of size N x M where:
- `1` represents a valid cell you can move to
- `0` represents a blocked cell

You start at cell (0, 0) and want to reach cell (X, Y) by moving only in four directions (up, down, left, right). 
Find the **minimum number of steps** required to reach the target cell.

----------------------------------------
📘 Example:

Input:
N = 3, M = 4
A = {{1, 1, 1, 1},
     {0, 0, 1, 0},
     {1, 1, 1, 1}}
X = 2, Y = 3

Output:
5

Explanation:
Path: (0,0) → (0,1) → (0,2) → (1,2) → (2,2) → (2,3)

----------------------------------------
❌ Common Mistakes & Why NOT DFS:

- **DFS is not ideal for shortest path** in unweighted graphs/grids.
- DFS can explore deeper paths first, leading to **non-optimal paths**.
- BFS guarantees the shortest path in such cases because it explores all nodes level by level.

----------------------------------------
🧠 Time and Space Complexity:

Time Complexity: O(N * M)
→ Each cell is visited at most once.

Space Complexity: O(N * M)
→ For visited matrix and queue.

----------------------------------------
✅ Optimized BFS Code:
----------------------------------------
*/

class Solution {
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (A[0][0] == 0) return -1;

        vector<vector<int>> vis(N, vector<int>(M, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        int count = 0;

        // Direction vectors: up, down, left, right
        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                if (row == X && col == Y) return count;

                for (int d = 0; d < 4; ++d) {
                    int newRow = row + dRow[d];
                    int newCol = col + dCol[d];

                    if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M &&
                        A[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
            count++;
        }

        return -1; // Target is not reachable
    }
};
