/*# 🔁 Cycle Detection in Directed Graph using DFS

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

```cpp*/
 class Solution {
  public:
  
  // DFS function to detect a cycle
  int dfs(vector<int>& path, int node, vector<vector<int>>& adj, vector<int>& vis) {
      vis[node] = 1;       // Mark the node as visited globally
      path[node]++;        // Mark the node in the current DFS path
      
      int size = adj[node].size();  // Number of neighbors
      
      for (int i = 0; i < size; i++) {
          int neigh = adj[node][i];  // Get each neighbor

          // If neighbor is already in the current path → cycle found
          if (path[neigh]) return 1;

          // If neighbor is not visited, do DFS on it
          if (!vis[neigh] && dfs(path, neigh, adj, vis)) return 1;
      }

      path[node]--;  // 🔁 Backtrack: remove node from current DFS path
      return 0;      // No cycle found in this path
  }

  // Main function to check if the graph has a cycle
  bool isCyclic(int V, vector<vector<int>> &edges) {
      int E = edges.size();
      
      // Adjacency list
      vector<vector<int>> adj(V);
      for (int i = 0; i < E; i++) {
          int u = edges[i][0];
          int v = edges[i][1];
          adj[u].push_back(v);  // Directed edge from u to v
      }

      vector<int> path(V, 0);  // To track the current DFS path
      vector<int> vis(V, 0);   // To mark visited nodes

      // Check every node (in case of disconnected components)
      for (int i = 0; i < V; i++) {
          if (!vis[i]) {
              if (dfs(path, i, adj, vis)) return 1;  // Cycle detected
          }
      }

      return 0;  // No cycle in any component
  }
};


