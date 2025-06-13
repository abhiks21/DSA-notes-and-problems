// Problem:
// Detect cycle in an undirected graph using DFS.
//
// Given V vertices and a list of undirected edges, check if the graph contains any cycle.

// Example:
// Input:
// V = 5
// edges = {{0,1}, {1,2}, {2,3}, {3,4}, {4,1}}
// Output: true (There is a cycle: 1-2-3-4-1)

// Mistakes:
// 1. Placing `vis[node] = 1` inside the loop after checking conditions.
// 2. Calling `dfs(0, ...)` in the loop for all nodes. It should be `dfs(i, ...)`.
// 3. Not handling disconnected graphs initially.

// Approach:
// - Create an adjacency list from the edges.
// - Use DFS to traverse the graph.
// - For each unvisited node, call DFS.
// - During DFS, if we reach an already visited node that is not the parent, a cycle exists.

// Time Complexity: O(V + E)
// Space Complexity: O(V + E) for the adjacency list and visited array

class Solution {
  public:
  // DFS function to detect cycle
  int dfs(int node, int parent, int V, vector<vector<int>>& adj, vector<int> &vis){
      vis[node]=1; // mark current node visited
      for(int i=0;i<adj[node].size();i++){
          if(parent==adj[node][i]) continue; // skip the parent
          if(vis[adj[node][i]]) return 1; // if already visited and not parent, cycle
          if(dfs(adj[node][i], node, V, adj, vis)) return 1;
      }
      return 0;
  }

  bool isCycle(int V, vector<vector<int>>& edges) {
      // Create adjacency list
      vector<vector<int>> adj(V);
      for(int i=0;i<edges.size();i++){
          int u=edges[i][0];
          int v=edges[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
      }

      vector<int> vis(V,0);
      // Call DFS for all components
      for(int i=0; i<V; i++){
          if(!vis[i]){
              if(dfs(i, -1, V, adj, vis)) return true;
          }
      }
      return false;
  }
};
