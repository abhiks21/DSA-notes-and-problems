/*## ✅ Topological Sort using Kahn's Algorithm (BFS-based)

---

### 🔍 Problem

Given a Directed Acyclic Graph (DAG) with `V` vertices and a list of `edges`, return a **topological ordering** of its vertices such that for every directed edge `u → v`, `u` comes before `v`.

---

### 🧠 Why Kahn’s Algo?

Kahn’s algorithm ensures:
- All dependencies (in-degrees) of a node are resolved **before** it's placed in the result.
- Processes nodes in order of **readiness** (zero in-degree).

---

### 🧪 Example

Input:
```
V = 6  
edges = {{5, 0}, {5, 2}, {4, 0}, {4, 1}, {2, 3}, {3, 1}}
```

Output:
```
[4, 5, 2, 3, 1, 0] ✅  
(Other valid topological orders are also possible)
```

---

### ✅ Code

```cpp*/
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indeg(V, 0);

        // Step 1: Build graph and in-degree array
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        // Step 2: Push nodes with in-degree 0 into queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        // Step 3: Process queue
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);

            for (int neigh : adj[node]) {
                indeg[neigh]--;
                if (indeg[neigh] == 0) q.push(neigh);
            }
        }

        return ans;
    }
};/*
```

---

### 📊 Time & Space Complexity

- **Time**: `O(V + E)`  
- **Space**: `O(V + E)`  
  - Adjacency list: `O(E)`  
  - In-degree array + queue: `O(V)`

---

### ⚠️ Mistakes to Avoid

- Forgetting to decrease in-degree of neighbors
- Not checking if graph is a DAG (optional: if `ans.size() != V`, cycle exists)

---

```
*/
