### 🧩 Problem
Given a Directed Acyclic Graph (DAG), return a linear ordering (topological sort) such that for every directed edge `u → v`, `u` appears before `v`.

---

### 📘 Example

Graph edges:
```
4 → 5 → 0 → 1 → 2 → 3
```

Valid topological order:
```
4 5 0 1 2 3
```

---

### 🧠 Why Stack?

In DFS, we go **deep into dependencies first**.  
We push each node into the stack **after** all its children (dependencies) are fully visited.

This ensures:
- **Dependents are pushed later**, so they come out earlier.
- When we pop the stack, we get the correct topological order.

#### Without stack:
Result: 0 1 2 3 4 5(wrong)
You might print nodes in the order you visit them — which can break dependencies.

#### With stack:
We reverse post-order DFS:
```
Stack (top → bottom): 3 2 1 0 5 4
Result after popping: 4 5 0 1 2 3 ✅
```

---

### ✅ Correct Code

```cpp
class Solution {
  public:
  void dfs(stack<int>& st, vector<vector<int>> &adj, int node, vector<int>& vis){
      vis[node] = 1;
      for(int neigh : adj[node]){
          if(!vis[neigh]){
              dfs(st, adj, neigh, vis);
          }
      }
      st.push(node); // Push after visiting dependencies
  }

  vector<int> topoSort(int V, vector<vector<int>>& edges) {
      vector<int> ans;
      stack<int> st;
      vector<vector<int>> adj(V);
      vector<int> vis(V, 0);

      // Build adjacency list
      for(auto &edge : edges){
          int u = edge[0], v = edge[1];
          adj[u].push_back(v);
      }

      // Run DFS on unvisited nodes
      for(int i = 0; i < V; i++){
          if(!vis[i]){
              dfs(st, adj, i, vis);
          }
      }

      // Collect from stack
      while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
      }

      return ans;
  }
};
```

---

### ⏱️ Time Complexity
- `O(V + E)` — each node and edge visited once.

### 💾 Space Complexity
- `O(V + E)` — for adjacency list, visited array, and stack.
