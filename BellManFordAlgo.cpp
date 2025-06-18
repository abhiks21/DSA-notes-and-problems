🧾 **Bellman-Ford Algorithm Notes**

---

## 🧩 Problem Statement:
Given a weighted **directed graph** with `V` vertices and `E` edges, find the **shortest distances from a given source node `src`** to all other nodes.

- Edges are given as `{u, v, wt}`.
- Graph **can contain negative edge weights**.
- If a **negative weight cycle** is detected → return `{-1}`.
- If a node is **unreachable** from `src`, its distance stays `INT_MAX`.

---

## 🧪 Example

**Input:**
```
V = 7  
edges = {
    {4, 5, 10},
    {5, 3, 1}
}
src = 0
```

**Output:**
```
[0, INF, INF, INF, INF, INF, INF]
```

(No node is reachable from node 0)

---

## 🧠 Approach

1. Initialize `dist[]` array of size `V` with `INT_MAX`. Set `dist[src] = 0`.

2. Run a loop `V - 1` times:
   - For every edge `(u, v, wt)`:
     - If `dist[u] + wt < dist[v]`, update `dist[v]`.

3. Do one more pass on all edges:
   - If any edge can still be relaxed → **negative weight cycle exists**, return `{-1}`.

4. Return the final `dist[]`.

---

## ⚠️ Common Mistakes

- ❌ Not checking `dist[u] != INT_MAX` before updating `dist[v]`.
- ❌ Forgetting the final negative cycle check.
- ❌ Confusing 0-based and 1-based indexing in problems.
- ❌ Printing or interpreting `INT_MAX` as a valid distance.

---

## ⏱️ Time & Space Complexity

- **Time:** O(V × E)
- **Space:** O(V)

---

## ✅ Optimized Code with Inline Comments

```cpp
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Step 1: Initialize distances
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Step 2: Relax all edges V-1 times
        for(int i = 0; i < V - 1; i++) {
            for(auto &edge : edges) {
                int u = edge[0], v = edge[1], wt = edge[2];

                // Only relax if u is reachable
                if(dist[u] != INT_MAX && dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Step 3: Check for negative weight cycle
        for(auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if(dist[u] != INT_MAX && dist[v] > dist[u] + wt) {
                return {-1};  // Negative cycle detected
            }
        }

        return dist;
    }
};
```

---

## 🗣️ Personal Reflection
> “This thing used to scare me two months ago, and now it feels like nothing.”

That's a **solid milestone**. You’ve grown stronger at:
- Understanding DSA core principles
- Avoiding edge-case traps
- Writing clean, optimal solutions

---

## 🎯 What's Next?
- Floyd-Warshall (All-pairs shortest path)
- Johnson’s Algorithm (for sparse graphs)
- Practice graph questions on Leetcode/Codeforces
