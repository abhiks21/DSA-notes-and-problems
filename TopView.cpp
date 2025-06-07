/*
🔷 Problem: Top View of a Binary Tree

📘 Definition:
Return the list of nodes visible when the binary tree is viewed from the top.
At each vertical level (column), only the first node seen from top to bottom is part of the top view.

----------------------------------------

🔧 Approach: Column Range Detection (DFS) + Level Order Traversal (BFS)

🛠️ Key Steps:
1. **DFS Traversal** to compute the min and max horizontal distance (column range) of the tree.
2. **BFS Traversal** to visit each node level-by-level, tracking their column index.
3. For each column, store the **first node encountered**, using a visited array.

📌 Benefit:
This approach avoids using `map`, making it more memory-efficient and faster than typical implementations.

----------------------------------------
*/

class Solution {
  public:
    // Step 1: Find the minimum and maximum column index using DFS
    void findColumnRange(Node* root, int &minCol, int &maxCol, int col) {
        if (!root) return;

        // Update minimum and maximum column boundaries
        if (col < minCol) minCol = col;
        if (col > maxCol) maxCol = col;

        // Traverse left with column - 1
        findColumnRange(root->left, minCol, maxCol, col - 1);
        // Traverse right with column + 1
        findColumnRange(root->right, minCol, maxCol, col + 1);
    }

    // Step 2: BFS to capture the first (topmost) node at each column
    void collectTopViewByBFS(Node* root, vector<int>& ans, vector<int>& visited, int minCol) {
        if (!root) return;

        queue<Node*> q;         // Queue to store tree nodes
        queue<int> colQ;        // Parallel queue to store column indices

        q.push(root);
        colQ.push(-minCol);     // Shift columns to start from index 0

        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            int col = colQ.front(); colQ.pop();

            // If this column hasn't been visited yet, store this node's data
            if (!visited[col]) {
                ans[col] = cur->data;
                visited[col] = 1;
            }

            // Add left child with column index -1
            if (cur->left) {
                q.push(cur->left);
                colQ.push(col - 1);
            }

            // Add right child with column index +1
            if (cur->right) {
                q.push(cur->right);
                colQ.push(col + 1);
            }
        }
    }

    // Main function to compute top view
    vector<int> topView(Node *root) {
        if (!root) return {};

        // Determine the range of horizontal distances (columns)
        int minCol = 0, maxCol = 0;
        findColumnRange(root, minCol, maxCol, 0);

        int width = maxCol - minCol + 1;

        vector<int> ans(width);         // To store the final top view
        vector<int> visited(width, 0);  // To track which columns are already filled

        // Collect top view nodes using BFS
        collectTopViewByBFS(root, ans, visited, minCol);

        return ans;
    }
};

/*
----------------------------------------

🕒 Time Complexity: O(N)
- N = number of nodes in the binary tree.
- Each node is visited once in BFS and once in DFS (for column range).

📦 Space Complexity: O(W)
- W = width of the tree (maxCol - minCol + 1)
- Due to queue and result vectors.

📌 Highlights:
- Uses arrays instead of map for better space and time efficiency.
- Ensures correct top view order: left to right by precomputing column range.

*/
