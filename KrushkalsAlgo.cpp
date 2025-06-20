/*## 🌲 Kruskal’s Algorithm Notes – Minimum Spanning Tree (MST)

---

### 🔍 Problem: 
**Find the sum of weights of the edges of the Minimum Spanning Tree.**  
You're given a weighted undirected graph with `V` vertices.

---

### ✅ Approach: Kruskal's Algorithm

1. **Store all edges** in a min-heap (priority queue) sorted by weights.
2. **Use Union-Find (DSU)** with **path compression** and **union by rank** to detect cycles.
3. **Iterate through edges in increasing order of weight**:
   - If the nodes of the edge are in different components, **union** them and **add the weight to the MST cost**.

---

### 🧠 Key Concepts:

| Component | Purpose |
|----------|----------|
| **DSU (Disjoint Set Union)** | Used to check whether two vertices are in the same component |
| **Path Compression** | Optimizes `findParent` to flatten the structure |
| **Union by Rank** | Ensures minimal height of the tree for efficiency |
| **Greedy** | Always take the edge with the smallest weight that doesn’t create a cycle |

---

### 🧪 Example:

Input graph:
```
V = 4
Edges:
0 --(1)-- 1
0 --(3)-- 2
1 --(2)-- 2
1 --(4)-- 3
2 --(5)-- 3
```

MST using Kruskal will take:  
Edges: (0-1), (1-2), (1-3)  
Cost = 1 + 2 + 4 = **7**

---

### 🧱 Code with Inline Comments:

```cpp*/
class Solution {
public:
    // Find the root parent of a node with path compression
    int findParent(int node, vector<int>& parent) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node], parent); // path compression
    }

    // Union two components by rank
    void findRank(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pv] > rank[pu]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Main function to return total weight of MST using Kruskal's Algorithm
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V), rank(V, 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        // Step 1: Add all edges to priority queue (min-heap)
        for (int i = 0; i < V; ++i) {
            for (auto& edge : adj[i]) {
                pq.push({edge[1], {i, edge[0]}}); // {weight, {u, v}}
            }
        }

        // Initialize parent array for DSU
        for (int i = 0; i < V; ++i) parent[i] = i;

        int cost = 0;

        // Step 2: Process edges in order of increasing weight
        while (!pq.empty()) {
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();

            // If u and v belong to different components, take the edge
            if (findParent(u, parent) != findParent(v, parent)) {
                findRank(u, v, parent, rank); // Union operation
                cost += wt; // Add edge weight to MST cost
            }
        }

        return cost;
    }
};/*
```

---

### 📌 Mistakes to Avoid:
- ❌ Not checking for cycle before union.
- ❌ Not initializing DSU parent array properly.
- ❌ Not using path compression and union by rank—leads to TLE in large graphs.

---

### 📈 Time and Space Complexity:

| Operation     | Complexity |
|--------------|------------|
| Sorting edges / Priority Queue insertions | O(E log E) |
| DSU operations (`find` and `union`) | Amortized O(α(N)) ≈ O(1) |
| Total Time | **O(E log E)** |
| Space       | **O(V + E)** |

---

### ✅ When to Use Kruskal:
- Sparse graphs (fewer edges).
- You have the edges list ready or easily constructible.

---

### 🧠 Kruskal vs Prim:

| Feature        | Kruskal                         | Prim                               |
|----------------|----------------------------------|-------------------------------------|
| Approach       | Greedy + DSU                    | Greedy + Min-Heap                  |
| Graph Type     | Edge List                       | Adjacency List / Matrix            |
| Best For       | Sparse Graphs                   | Dense Graphs                       |
| Time Complexity| O(E log E)                      | O(E log V) with min-heap + visited |
| Complexity Tip | Sorting edges is main overhead | Min-heap operations are critical   |

---

### 🎯 Summary:
- Kruskal is powerful when you are okay with sorting the edges and managing disjoint sets.
- Mastering Union-Find is the key to unlocking Kruskal.
- Once you're confident, both Kruskal and Prim are must-know tools for competitive programming and interviews.
*/
