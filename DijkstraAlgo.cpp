/*# ✅ Dijkstra's Algorithm Notes

---

## 🔍 Problem Statement

Given a directed graph with non-negative weights, find the **shortest path** from a source node `src` to all other vertices.

---

## 📦 Input Format

- `V`: Number of vertices (0 to V-1)
- `edges`: List of edges where each edge is a triplet `[u, v, w]` meaning an edge from `u` to `v` with weight `w`
- `src`: Source node

---

## ⚠️ Common Mistakes

1. ❌ Using `visited[]` array:
   - Marking a node visited too early can skip better paths discovered later.
   - **Don't use** `visited[]` in Dijkstra. It breaks correctness.

2. ❌ Not skipping outdated entries from the priority queue:
   - You may process a node multiple times with outdated (longer) distances.

   ✅ Fix: Use this check before processing:
   ```cpp
   if (weight > dist[node]) continue;
   ```

---

## 🧠 Key Idea

- Use a **min-heap** (priority_queue with `greater<>>`) to always expand the node with the shortest current distance.
- Update distances of neighbors only if a **shorter path** is found.

---

## 🧪 Example

### Graph:
```
Edges:
0 → 1 (4)
0 → 2 (1)
2 → 1 (2)
1 → 3 (1)
2 → 3 (5)
```

### Input:
```cpp
V = 4
edges = { {0,1,4}, {0,2,1}, {2,1,2}, {1,3,1}, {2,3,5} }
src = 0
```

### Output:
```
dist[] = {0, 3, 1, 4}
```

---

## ⏱️ Time & Space Complexity

- **Time Complexity**: `O((V + E) log V)`
  - Each node is processed once.
  - Each edge causes at most one push in priority queue.
- **Space Complexity**: `O(V + E)`
  - For adjacency list and distance array.

---

## ✅ Correct Code (C++17+)

```cpp*/
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        // Min-heap: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            // Skip if this is an outdated entry
            if (weight > dist[node]) continue;

            for (auto &[neigh, w] : adj[node]) {
                if (dist[neigh] > dist[node] + w) {
                    dist[neigh] = dist[node] + w;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist;
    }
};
