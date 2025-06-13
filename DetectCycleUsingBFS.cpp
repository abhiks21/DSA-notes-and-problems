// Problem:
// Detect cycle in an undirected graph using BFS.
//
// Given V vertices and a list of undirected edges, check if the graph contains any cycle.

// Example:
// Input:
// V = 5
// edges = {{0,1}, {1,2}, {2,3}, {3,4}, {4,1}}
// Output: true (There is a cycle: 1-2-3-4-1)

// Mistakes:
// 1. Incorrectly nested loop in edge-to-adjacency list conversion.
// 2. Wrong loop bound using V instead of edges.size().
// 3. Pushing the wrong indices or skipping vis[node]=1 at the correct time.

// Approach:
// - Create an adjacency list from the edges.
// - Use BFS to traverse the graph.
// - For each unvisited node, initiate BFS.
// - Track parent nodes. If we revisit a node that's not the parent, a cycle exists.

// Time Complexity: O(V + E)
// Space Complexity: O(V + E) for the adjacency list and visited array

class Solution {
  public:
    int bfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
        queue<pair<int,int>> q;
        q.push({node, parent});
        vis[node]=1;

        while(!q.empty()){
            node = q.front().first;
            parent = q.front().second;
            q.pop();

            for(int i = 0; i < adj[node].size(); i++){
                int neigh = adj[node][i];
                if(parent == neigh) continue;
                if(vis[neigh]) return 1;
                vis[neigh] = 1;
                q.push({neigh, node});
            }
        }
        return 0;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(bfs(i, -1, adj, vis)) return 1;
            }
        }
        return 0;
    }
};
