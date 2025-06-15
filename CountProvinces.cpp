// 📌 Problem: Number of Provinces (Leetcode 547)
// You are given an `n x n` matrix `isConnected` representing a graph.
// A province is a group of directly or indirectly connected cities.
// You need to return the number of provinces.

// 🔍 Example:
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Explanation:
// City 0 and City 1 are connected => one province
// City 2 is alone => another province

// ✅ Approach: Depth-First Search (DFS)
// - Build an adjacency list from the matrix (since it's symmetric).
// - Traverse using DFS, marking visited nodes.
// - For every unvisited node, start a new DFS → it represents a new province.

// 🔁 Time Complexity: O(N^2) for building adjacency list + O(N + E) for DFS traversal
// 🔁 Space Complexity: O(N + E) for the adjacency list + O(N) for visited array

class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;
        int size = adj[node].size();

        for(int i = 0; i < size; i++) {
            if(!vis[adj[node][i]])
                dfs(adj[node][i], adj, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();  // number of cities

        // ✅ Step 1: Create adjacency list from the matrix
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(grid[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // ✅ Step 2: Use DFS to count connected components (provinces)
        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                count++;  // found a new province
            }
        }

        return count;
    }
};
