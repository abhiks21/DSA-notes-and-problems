/*## 🚀 Shortest Path in an Unweighted Graph (BFS)

### 🧩 Problem:
Given an adjacency list of an **unweighted undirected graph**, and a source node `src`, return the shortest distance from `src` to all other nodes.

---

### 📘 Example:
Graph:
```
0 --- 1 --- 3
|     |
2     4
```

Adjacency List:
```cpp
adj = {
    {1, 2},   // 0
    {0, 4, 3},// 1
    {0},      // 2
    {1},      // 3
    {1}       // 4
}
```

Source: `0`

Output:
```
[0, 1, 1, 2, 2]
```

---

### ❌ Common Mistake:
When pushing neighbors to the queue, we **forget to update the distance** properly:

```cpp
q.push({neigh, curdist}); // ❌ wrong, reuses old distance
```

This leads to incorrect or inconsistent distances.

---

### ✅ Correct Approach:
Use BFS because:
- All edges have the same weight (unweighted)
- BFS naturally explores nodes level by level, giving shortest paths

Steps:
1. Initialize a distance/visited array `vis` with `-1`
2. Use a queue to do BFS
3. Push `(node, distance)` into the queue
4. For each neighbor, if not visited:
   - Update its distance as `curdist + 1`
   - Push it into the queue

---

### ⏱️ Time Complexity:
- `O(V + E)` — each node and edge is visited once

### 🧠 Space Complexity:
- `O(V)` — for queue and `vis` array

---

### ✅ Final Code:
```cpp*/
class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> vis(n, -1);
        queue<pair<int, int>> q;
        q.push({src, 0});
        vis[src] = 0;

        while (!q.empty()) {
            int cur = q.front().first;
            int curdist = q.front().second;
            q.pop();

            for (int neigh : adj[cur]) {
                if (vis[neigh] == -1) {
                    vis[neigh] = curdist + 1;
                    q.push({neigh, curdist + 1}); // ✅ Corrected here
                }
            }
        }

        return vis;
    }
};
```

---

### 🧠 Tip:
- For shortest path with **weighted graphs**, use **Dijkstra's Algorithm**.
- For **actual path reconstruction**, maintain a `parent[]` array.

---

