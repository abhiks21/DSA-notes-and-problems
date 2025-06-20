/*## 🧭 Problem: Minimum Effort Path (Leetcode 1631)

**Goal**: Find a path from top-left to bottom-right such that the **maximum absolute difference** in heights between adjacent cells along the path is **minimized**.

---

### ✅ Approach: Dijkstra’s Algorithm on Grid

Use a **priority queue** (min-heap) to always expand the cell with the minimum **current effort**.  
Track the **minimum effort** to reach each cell using an `effort[][]` matrix (similar to `dist[][]` in classic Dijkstra).

---

### 🧪 Example:

```
Input:
heights = [[1,2,2],
           [3,8,2],
           [5,3,5]]

Output:
2

Explanation:
Path: (0,0) → (0,1) → (0,2) → (1,2) → (2,2)  
Max height difference: max(1,0,0,3) = 3  
But a better path is: (0,0) → (1,0) → (2,0) → (2,1) → (2,2)  
With height diffs: 2,2,0,2 → max = 2 ✅
```

---

### ❌ Common Mistakes:

- Using `visited[][]` in weighted graph: ❌ Not enough, as you may reach a cell again with better cost.
- Updating a global `mini` inside the loop: ❌ Incorrect, you need to track effort *per cell*.
- Not checking if the current `newEffort` is better than the stored `effort[nx][ny]`.

---

### ⚠️ BFS vs Dijkstra in Grid

| Graph Type | Use `visited[][]`? | Use `effort[][]` or `dist[][]`? | Revisit Cell? |
|------------|--------------------|-----------------------------|----------------|
| Unweighted | ✅ Yes              | ❌ Not needed                | ❌ No           |
| Weighted   | ❌ No               | ✅ Yes                       | ✅ If better cost |

---

### 📦 Time & Space Complexity

- **Time Complexity**: O(M * N * log(M * N))  
  where M = rows, N = cols (each cell at most pushed once with a better effort)
- **Space Complexity**: O(M * N)  
  for `effort[][]` matrix and priority queue

---

### ✅ Final Optimal Code (C++)

```cpp*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        effort[0][0] = 0;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> pq;

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [currEffort, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            if (x == m - 1 && y == n - 1) return currEffort;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int diff = abs(heights[x][y] - heights[nx][ny]);
                    int maxEffort = max(currEffort, diff);

                    if (effort[nx][ny] > maxEffort) {
                        effort[nx][ny] = maxEffort;
                        pq.push({maxEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0; // default return, shouldn't reach here
    }
};/*
```

---

### 🧠 Summary:

- Use Dijkstra for weighted grid path problems where cost is not step count but a custom metric (like max diff).
- Never rely on `visited[][]` alone in weighted graphs.
- Use `effort[][]` to track the best way to each cell and only revisit when it improves.

*/
