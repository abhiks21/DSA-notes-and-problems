/*🧾 PROBLEM:
Detect cycle in a directed graph using **Kahn’s Algorithm** (topological sort approach).

📌 EXAMPLE:
Input:
V = 4, Edges = [[0,1],[1,2],[2,3],[3,1]]

Graph:
0 → 1 → 2 → 3
        ↑   ↓
        ←----

There is a cycle: 1 → 2 → 3 → 1 → ...

Output: true (cycle exists)

🧠 WHY KAHN’S ALGORITHM?
- Kahn’s Algorithm uses **in-degree** tracking to perform **topological sorting**.
- If a topological order **cannot** include all vertices → a **cycle** exists.
- Suitable for **dependency resolution** problems in DAGs.

📎 APPROACH:
1. Create an adjacency list from edges.
2. Create an `inDegree` array for each node.
3. Add all nodes with inDegree 0 to a queue (they have no dependencies).
4. Process each node:
   - Remove it from the queue.
   - Decrease inDegree of its neighbors.
   - If any neighbor’s inDegree becomes 0, add to queue.
5. After processing, if all nodes are processed → no cycle.
6. If some nodes are left unprocessed → cycle exists.

⏱️ TIME COMPLEXITY:
O(V + E), where V = number of vertices, E = number of edges

📦 SPACE COMPLEXITY:
O(V + E) for adjacency list, in-degree array, and queue

🧩 CODE:
```cpp*/
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        int E = edges.size();
        
        // Step 1: Build adjacency list and in-degree array
        vector<int> inDegree(V, 0);
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            inDegree[v]++;  // Count incoming edge
        }

        // Step 2: Push all nodes with in-degree 0 to queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process the queue
        int count = 0;  // To count processed nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;  // Processed one node

            // Decrease in-degree of neighbors
            for (int neigh : adj[node]) {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        // Step 4: If all nodes processed, no cycle; else, cycle exists
        return count != V;
    }
};
