// 🚀 PROBLEM: Find the shortest path from node 0 to all other nodes in a weighted directed graph
// Given: V vertices, E edges, and edge list edges[i] = {u, v, wt}
// You must return an array 'dist' of size V where dist[i] = shortest distance from node 0 to node i
// If node i is unreachable, dist[i] = -1

// 🔍 EXAMPLE:
// V = 5, E = 6
// edges = {{0,1,2}, {0,2,4}, {1,2,1}, {1,3,7}, {2,4,3}, {3,4,1}}
// Expected Output: [0,2,3,9,6]

// ❌ MISTAKES/LEARNING:
// 1. Used BFS approach for weighted graph, which is not always optimal.
// 2. This approach works here because it greedily updates distances, but it’s not guaranteed to be optimal for all graphs.
// 3. Better algorithms for weighted graphs: Dijkstra’s or Topological Sort (for DAG).

// ✅ APPROACH (BFS-like for weighted graph):
// - Build adjacency list with {neigh, weight} pairs
// - Use queue<pair<node, distance>> to simulate BFS
// - For each neighbor, update dist[neigh] = min(dist[neigh], dist[cur] + wt) if it's better
// - Push updated neighbor into queue for further processing

// ⏱ TIME COMPLEXITY: O(V + E) in the best case, but may behave worse due to multiple queue insertions
// 🧠 SPACE COMPLEXITY: O(V + E)

// ✅ CODE:
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        
        // Step 1: Build adjacency list
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int edwt = edges[i][2];
            adj[u].push_back({v, edwt});
        }

        vector<int> dist(V, -1); // Default -1 for unreachable
        queue<pair<int,int>> q;  // {node, distance}
        q.push({0, 0});
        dist[0] = 0;

        // Step 2: BFS-like traversal and distance update
        while(!q.empty()) {
            int cur = q.front().first;
            int curdis = q.front().second;
            q.pop();

            for(int i = 0; i < adj[cur].size(); i++) {
                int neigh = adj[cur][i].first;
                int edwt = adj[cur][i].second;

                if(dist[neigh] == -1 || dist[neigh] > curdis + edwt) {
                    dist[neigh] = curdis + edwt;
                    q.push({neigh, dist[neigh]});
                }
            }
        }

        return dist;
    }
};
