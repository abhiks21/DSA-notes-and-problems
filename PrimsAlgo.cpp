/*# ✅ Minimum Spanning Tree using Prim's Algorithm (Priority Queue)

## 🧩 Problem
Given a connected, undirected, and weighted graph represented as an adjacency list, return the **sum of the weights of the edges in the Minimum Spanning Tree (MST)**.

Function signature:
```cpp
int spanningTree(int V, vector<vector<int>> adj[]);
```

## 🔍 Example
**Input:**
```
V = 3  
edges = [
  [1, 1],  // Edge from 0 to 1 with weight 1
  [2, 2]   // Edge from 0 to 2 with weight 2
]
edges[1] = [
  [0, 1],
  [2, 3]
]
edges[2] = [
  [0, 2],
  [1, 3]
]
```

**Graph:**  
```
    0
   / \
  1   2
 w1   w2 (1,2,3)
```

**Output:**  
`3`  
(Minimum Spanning Tree includes edge 0–1 and 0–2 with total cost 1 + 2 = 3)

---

## 🧠 Approach
We use **Prim's Algorithm** with a **Min-Heap (Priority Queue)** to pick the edge with the least weight at each step.

1. **Build an adjacency list** from the given edges.
2. Use a min-heap to always pick the next smallest edge.
3. Maintain a `visited` array to avoid cycles.
4. Start from node 0, and keep adding the smallest unvisited edge to the MST.
5. Keep adding the weight of edges used in MST.

---

## ❌ Mistakes to Avoid
- Confusing the input structure:  
  `vector<vector<int>> edges[]` is an adjacency list where each `edges[u]` contains vectors like `{v, wt}`.
- Not checking `visited[]` before pushing into priority queue or visiting.
- Missing to add weights only from unvisited nodes.

---

## ⏱ Time Complexity
**O(E * log V)**  
- Each edge insertion into the priority queue costs log V.
- E is total number of edges.

## 📦 Space Complexity
**O(V + E)**  
- Adjacency list + visited array + priority queue.

---

## 🧾 Code (Prim's Algorithm with Priority Queue)
```cpp*/
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Min-heap priority queue: {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V, 0); // Visited array
        int cost = 0;

        pq.push({0, 0}); // Start from node 0 with weight 0

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            cost += wt;

            // Explore adjacent nodes
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];
                if (!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return cost;
    }
};
```
