/*## 🔍 Problem: Check if a graph has an Euler Path or Euler Circuit

### 📌 Input
- `V`: number of vertices
- `adj[]`: adjacency list of undirected graph

### ✅ Output
- `2` → Eulerian Circuit exists
- `1` → Only Eulerian Path exists
- `0` → Neither exists

---

### 📘 Approach
1. **Count degree** of each node.
2. **Find starting node** with degree > 0.
3. Use **DFS to check** if all non-isolated nodes are connected.
4. **Count odd-degree nodes**:
   - `0` → Eulerian **circuit**.
   - `2` → Eulerian **path**.
   - `>2` → **Neither**.

---

### ⚠️ Mistakes Avoided
- `indegree[]` is used correctly as degree here.
- DFS starts only from non-isolated vertex.
- Checks connectivity and then degree parity, not mixed.

---

### 🧮 Time & Space Complexity
- **Time:** `O(V + E)` — DFS + degree count
- **Space:** `O(V)` — visited + degree arrays

*/
class Solution {
  public:
  // DFS to mark all reachable nodes from 'node'
  void dfs(vector<int> adj[], int node, vector<int>& vis) {
      vis[node] = 1;
      for(int neighbor : adj[node]) {
          if(!vis[neighbor]) {
              dfs(adj, neighbor, vis);
          }
      }
  }

  int isEulerCircuit(int V, vector<int> adj[]) {
      vector<int> vis(V, 0);
      vector<int> degree(V, 0); // For undirected graph, degree = adj[i].size()

      // Step 1: Compute degree of each vertex
      for(int i = 0; i < V; i++) {
          degree[i] = adj[i].size();
      }

      // Step 2: Find starting node with degree > 0
      int start = -1;
      for(int i = 0; i < V; i++) {
          if(degree[i] > 0) {
              start = i;
              break;
          }
      }

      // If all nodes are isolated (no edges), return 2 (trivial Euler circuit)
      if(start == -1) return 2;

      // Step 3: DFS to check if all non-zero degree nodes are connected
      dfs(adj, start, vis);
      for(int i = 0; i < V; i++) {
          if(degree[i] > 0 && !vis[i]) return 0; // disconnected
      }

      // Step 4: Count odd-degree nodes
      int odd = 0;
      for(int i = 0; i < V; i++) {
          if(degree[i] % 2 == 1) odd++;
      }

      // Step 5: Determine Euler Path or Circuit
      if(odd == 0) return 2;       // Eulerian Circuit
      else if(odd == 2) return 1;  // Eulerian Path
      else return 0;              // Neither
  }
};
