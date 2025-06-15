// 🔍 Problem:
// Find all connected components in an undirected graph.

// 🧠 Approach:
// - Use Depth First Search (DFS) to traverse each connected component.
// - For each unvisited node, start a DFS and collect all reachable nodes in a temporary vector.
// - Push the collected component to the result vector `ans`.
// - Clear the temporary vector after each component is collected.

// 🧪 Example:
// Input: V = 5, edges = {{0, 1}, {0, 2}, {3, 4}}
// Graph:
// 0 - 1
// |
// 2     3 - 4
// Output: [[0, 1, 2], [3, 4]] (order of nodes inside each component may vary)

// 🧮 Time Complexity: O(V + E)
// - Each vertex is visited once.
// - Each edge is processed once (undirected).

// 🧮 Space Complexity: O(V + E)
// - Adjacency list + visited array + call stack + result storage.

// ✅ Optimal: Yes, this is an optimal DFS-based approach.

class Solution {
  public:
    // DFS function to collect all nodes in the same component
    void dfs(vector<int> &temp, int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1;
        temp.push_back(node);
        int size = adj[node].size();
        
        for(int i = 0; i < size; i++){
            if(!vis[adj[node][i]]){
                dfs(temp, adj[node][i], vis, adj);
            }
        }
    }

    // Function to get all connected components
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> ans;      // Final list of components
        vector<int> temp;             // Temporary list for one component
        vector<vector<int>> adj(V);   // Adjacency list

        // Build adjacency list
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph
        }

        vector<int> vis(V, 0); // Visited array

        // DFS for each unvisited node
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(temp, i, vis, adj);
                ans.push_back(temp);
                temp.clear(); // Clear for next component
            }
        }

        return ans;
    }
};
