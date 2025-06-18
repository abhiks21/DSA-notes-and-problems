/*
📌 PROBLEM:
Given a weighted undirected graph with `n` vertices (1 to n) and `m` edges of the form {a, b, w}, 
find the shortest path from vertex 1 to vertex n. Return a list where:
- The first element is the total weight of the path.
- The rest are the nodes in the path from 1 to n.
If no path exists, return a vector containing -1.

📥 INPUT:
- int V: number of vertices
- int E: number of edges
- vector<vector<int>> edges: each element = {a, b, w}

📤 OUTPUT:
- vector<int> of format: [totalWeight, node1, node2, ..., nodeN]
- If no path: [-1]

🧪 EXAMPLE:
Input:
V = 5
edges = {
    {1, 2, 4},
    {1, 3, 2},
    {2, 3, 1},
    {2, 4, 5},
    {3, 5, 10}
}
Output: [12, 1, 3, 5]

🧠 APPROACH:
- Build adjacency list from edge list
- Use Dijkstra’s algorithm with a priority queue (min-heap) to find shortest distances from source (node 1)
- Track the parent of each node to reconstruct the path
- After the algorithm, if the destination (node n) is unreachable, return {-1}
- Otherwise, reconstruct the path using the parent array, and prepend the total weight to the result

❌ MISTAKE MADE:
- Returned only the path, but **missed inserting the total path weight** at the beginning of the result vector.
  ➤ This led to failure in output validation.
  ✅ Fixed by adding: `path.insert(path.begin(), dist[n-1]);`

⌛ TIME COMPLEXITY:
- O((V + E) * log V) using priority queue

🧠 SPACE COMPLEXITY:
- O(V + E) for adjacency list and extra arrays

✅ FINAL CODE (with inline comments):
*/

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int> dist(V, INT_MAX);     // distance from source
        vector<int> parent(V, -1);        // to reconstruct the path
        vector<vector<pair<int, int>>> adj(V); // adjacency list

        // Build the adjacency list (convert to 0-indexed)
        for (auto &edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // Dijkstra's algorithm using min-heap
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0); // {distance, node}

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            for (auto &[v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    parent[v] = u;
                    pq.emplace(dist[v], v);
                }
            }
        }

        // If destination is unreachable
        if (dist[V - 1] == INT_MAX) return {-1};

        // Reconstruct path from parent array
        vector<int> path;
        for (int at = V - 1; at != -1; at = parent[at])
            path.push_back(at + 1); // convert back to 1-based index

        reverse(path.begin(), path.end());

        // ✅ Prepend total weight to path
        path.insert(path.begin(), dist[V - 1]);

        return path;
    }
};
