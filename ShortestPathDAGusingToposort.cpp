/*
🔹 Problem:
Given a Directed Acyclic Graph (DAG), find the shortest path from source node `0` to all other nodes.

🔹 Approach:
1. Represent the graph using an adjacency list with edge weights.
2. Perform DFS from source node `0` to obtain a topological ordering.
3. Initialize distances from source to all nodes as `INT_MAX`, except for the source which is `0`.
4. Process nodes in topological order, relaxing the distances for adjacent nodes.
5. Convert unreachable node distances from `INT_MAX` to `-1`.

🔹 Time Complexity: O(V + E)
🔹 Space Complexity: O(V + E)
🔹 Suitable for: DAGs (Directed Acyclic Graphs)
*/

class Solution {
public:
    // Helper DFS to compute topological order
    void dfs(vector<vector<pair<int, int>>>& adj, int node, stack<int>& st, vector<int>& vis) {
        vis[node] = 1; // Mark current node as visited
        for (auto& [neigh, wt] : adj[node]) { // Traverse all adjacent nodes
            if (!vis[neigh]) {
                dfs(adj, neigh, st, vis);
            }
        }
        st.push(node); // Push node to stack after visiting all its neighbors (post-order)
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list with weights
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].emplace_back(v, wt); // Directed edge from u to v with weight wt
        }

        // Step 2: Initialize distances with INT_MAX
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Distance from source (0) to itself is 0

        // Step 3: Get topological ordering using DFS starting from source node
        stack<int> st;
        vector<int> vis(V, 0);
        dfs(adj, 0, st, vis); // Only visit nodes reachable from source

        // Step 4: Relax edges using topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // If current node is reachable
            if (dist[node] != INT_MAX) {
                for (auto& [neigh, wt] : adj[node]) {
                    // Relax the edge if a shorter path is found
                    if (dist[neigh] > dist[node] + wt) {
                        dist[neigh] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 5: Replace unreachable node distances with -1
        for (int& d : dist) {
            if (d == INT_MAX) d = -1;
        }

        return dist;
    }
};
