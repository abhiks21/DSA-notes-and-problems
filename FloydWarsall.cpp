/*### 📘 Floyd-Warshall Algorithm Notes

---

### 🔍 Problem:
Given a graph with `V` vertices (possibly with negative weights, but **no negative cycles**), find the **shortest path between every pair of vertices**.

---

### 🧠 Key Idea:
Try to improve the path from `i → j` using an intermediate node `k`.

Formula:
```
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

---

### 📥 Input Format:
- `dist[i][j]` represents the distance from vertex `i` to `j`.
- If there is no edge between `i` and `j`, `dist[i][j] = 1e8` (acts as infinity).
- `dist[i][i] = 0` for all `i`.

---

### ✅ Approach:
1. Iterate `k = 0 to n-1` → intermediate node
2. For each pair `(i, j)`, check if going through `k` gives a shorter path.
3. If so, update `dist[i][j]`.

---

### ⚠️ Edge Case Handling:
- Skip update if `dist[i][k] == INF` or `dist[k][j] == INF` to avoid overflow.

---

### 📦 Example:
Given:
```
0 3 INF
INF 0 1
1 INF 0
```

After applying Floyd-Warshall:
```
0 3 4
2 0 1
1 4 0
```

---

### 💻 Code (C++)

```cpp*/
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] == 1e8 || dist[k][j] == 1e8)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }/*
```

---

### ⏱️ Time Complexity: `O(V³)`
### 🧠 Space Complexity: `O(V²)` (for distance matrix)

---

### 🛑 Bonus:
To detect a **negative cycle**, check:
```cpp
for (int i = 0; i < V; i++) {
    if (dist[i][i] < 0) {
        // Negative cycle exists
    }
}
```

---

### ✅ Status:
- Works with negative weights ✅
- Fails with negative cycles ❌
- Best for **dense graphs** and **all-pairs shortest paths**
*/
