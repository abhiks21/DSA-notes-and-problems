# 🔁 Cycle Detection in Directed Graph using DFS

---

## 🧩 Problem:
Given `V` vertices and a list of `edges`, determine whether the **directed graph** contains a **cycle**.

---

## 📘 Example:

**Input:**
```
V = 4  
edges = {{0, 1}, {1, 2}, {2, 3}, {3, 1}}
```

**Output:**  
`true` (cycle exists: 1 → 2 → 3 → 1)

---

## ❌ Common Mistakes:
1. Not using a `visited[]` array → causes repeated DFS on the same nodes.
2. Only checking if a node is visited → fails to distinguish between **currently-in-path** and **already-processed** nodes.
3. Not backtracking the `path[]` after recursion.

---

## ✅ Correct Approach (DFS + Recursion Stack):
- Use:
  - `visited[]` → to track nodes that are already fully processed.
  - `path[]` (a.k.a. recursion stack) → to track the **current DFS path**.
- If we visit a node already in the `path[]`, a **cycle exists** (back edge detected).
- Run DFS from all unvisited nodes.

---

## ⏱️ Time Complexity:
- `O(V + E)`  
Each node and edge is visited exactly once.

---

## 🧮 Space Complexity:
- `O(V)` for `visited[]`, `path[]`, and recursion stack.

---

## ✅ Final Code:

```cpp
class Solution {
public:
    // DFS function to detect cycle
    bool dfs(int node, vector<int>& path, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        path[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, path, vis, adj)) return true;
            } else if (path[neigh]) {
                return true; // back edge → cycle
            }
        }

        path[node] = 0; // backtrack
        return false;
    }

    // Main function
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(V, 0), path(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, path, vis, adj)) return true;
            }
        }

        return false;
    }
};
```

---

Let me know if you want a note for **undirected graphs** or **BFS-based (Kahn's Algorithm)** approach as well!
