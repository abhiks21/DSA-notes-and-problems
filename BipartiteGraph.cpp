/*************************************
🧠 Problem: Check if a Graph is Bipartite (LeetCode 785)

📌 Definition:
A graph is **bipartite** if we can split its set of vertices into two disjoint sets such that every edge connects vertices from different sets (i.e., no two adjacent nodes share the same set).

🧪 Example:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: The graph cannot be colored with two colors without two adjacent nodes sharing the same color.

✅ Why this approach (BFS)?
- We assign alternating colors (0 and 1) while traversing the graph.
- If at any point, two adjacent nodes have the same color → graph is not bipartite.

🔍 Approach:
1. Use a `color` array initialized to -1 for all nodes (unvisited).
2. For every unvisited node, perform BFS and color it 0, then alternate the color for its neighbors.
3. If during traversal, you find a neighbor with the same color → return false.
4. If the entire graph passes this check, return true.

⏱️ Time Complexity: O(V + E)  
- We visit each vertex and edge once.

📦 Space Complexity: O(V)  
- For the color array and queue used in BFS.

🧩 Code (BFS Approach):
*************************************/
class Solution {
public:
    // Helper BFS function to check bipartite from a given node
    bool bfs(int node, vector<vector<int>>& graph, vector<int> &color){
        if(color[node] == -1) color[node] = 0; // Color the starting node with 0
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            node = q.front();
            q.pop();

            for(int neigh : graph[node]){
                if(color[neigh] != -1){
                    // If neighbor is already colored and has the same color → not bipartite
                    if(color[neigh] == color[node]) return false;
                    continue;
                }
                // Assign the opposite color to the neighbor
                color[neigh] = !color[node];
                q.push(neigh);
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);  // -1 = unvisited

        // Run BFS for each unvisited component
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(!bfs(i, graph, color)) return false;
            }
        }
        return true;
    }
};
