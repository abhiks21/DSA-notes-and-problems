/*## 🧠 Problem: Count All Possible Shortest Paths from Source to Destination

You are given a **weighted undirected graph** with `n` nodes (0 to n-1) and a list of `roads`, where each road is defined as `[u, v, time]`.

You need to **count the number of different shortest paths** from node `0` to node `n-1`.

Return the result **modulo 1e9+7**.

---

### 📌 Example:

**Input:**
```cpp
n = 7  
roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
```

**Output:**  
`4`  
(There are 4 different shortest paths from node 0 to node 6)

---

### ❌ Common Mistakes:

1. **Using BFS for Weighted Graphs**  
   BFS is only valid for unweighted graphs. Use **Dijkstra** for weighted graphs.

2. **Incorrect Modulo Application**  
   Never apply `% mod` to distances. Only apply it when **counting ways**.

3. **Incorrect Way Tracking**  
   You need a `ways[]` array to track how many shortest paths reach each node.

---

### ✅ Approach: Dijkstra + Path Counting

- Use a **priority queue (min-heap)** to implement Dijkstra's algorithm.
- Maintain:
  - `dist[i]`: Minimum distance from node `0` to node `i`
  - `ways[i]`: Number of shortest paths from `0` to `i`

---

### 🧮 Time & Space Complexity:

| Aspect       | Complexity        |
|--------------|-------------------|
| Time         | `O(E * log V)`    |
| Space        | `O(V + E)`        |
| Data Structs | Adjacency List, Min-Heap, Distance Array, Ways Array |

---

### ✅ Final Code:

```cpp*/
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        // Adjacency list: node -> list of (neighbor, weight)
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // undirected graph
        }

        // Distance and ways initialization
        vector<long long> dist(n, LLONG_MAX);  // Min distance to reach each node
        vector<int> ways(n, 0);                // No. of shortest paths to reach each node

        // Min-heap priority queue: (distance, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // Start from node 0
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            // If the current distance is already worse, skip
            if (d > dist[u]) continue;

            // Explore neighbors
            for (auto& [v, wt] : adj[u]) {
                long long newDist = d + wt;

                // Found a better path to v
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];  // all ways to u now lead to v
                    pq.push({newDist, v});
                }
                // Found another shortest path to v
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        // Return number of shortest paths to node n-1
        return ways[n - 1];
    }
};/*
```

---

### ✅ Summary Table:

| Term       | Meaning                                         |
|------------|--------------------------------------------------|
| `dist[i]`  | Minimum distance from node 0 to node i           |
| `ways[i]`  | Number of shortest paths from 0 to i             |
| `mod`      | 1e9 + 7 to avoid overflow in path count          |
| Dijkstra   | For shortest paths in weighted graph             |

---
*/
