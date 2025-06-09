/*
🔰 Problem:
Boundary Traversal of a Binary Tree in anti-clockwise direction:
1. Root node
2. Left boundary (excluding leaves)
3. All leaf nodes (left to right)
4. Right boundary (excluding leaves, in reverse)

📌 Approach:
1. Traverse the left boundary (excluding leaf nodes).
2. Traverse all the leaf nodes using DFS.
3. Traverse the right boundary (excluding leaf nodes) and reverse the result.
4. Combine: root + left + leaves + reversed right.

⚠️ Common Mistakes:
- Including leaf nodes in both left/right and leaf traversal → duplication.
- Forgetting to reverse the right boundary.
- Not handling single-node trees separately.

*/

class Solution {
public:

  // Traverses the left boundary excluding leaf nodes
  void leftTra(Node* root, vector<int>& leftB){
      if(!root || (!root->left && !root->right)) return;

      leftB.push_back(root->data); // add current node

      // Prefer left child, fallback to right if no left
      if(root->left) leftTra(root->left, leftB);
      else leftTra(root->right, leftB);
  }

  // Traverses all leaf nodes using DFS
  void bottomTra(Node* root, vector<int>& bottomB){
      if(!root) return;

      if(!root->left && !root->right){
          bottomB.push_back(root->data); // add leaf node
      }

      bottomTra(root->left, bottomB);
      bottomTra(root->right, bottomB);
  }

  // Traverses the right boundary excluding leaf nodes
  void rightTra(Node* root, vector<int> &rightB){
      if(!root || (!root->left && !root->right)) return;

      rightB.push_back(root->data); // add current node

      // Prefer right child, fallback to left if no right
      if(root->right) rightTra(root->right, rightB);
      else rightTra(root->left, rightB);
  }

  // Main function to compute boundary traversal
  vector<int> boundaryTraversal(Node *root) {
      if(!root) return {};
      // Special case: only root node
      if(!root->left && !root->right) return {root->data};

      vector<int> leftB, bottomB, rightB;

      leftTra(root->left, leftB);       // Step 1: left boundary
      bottomTra(root, bottomB);         // Step 2: leaf nodes
      rightTra(root->right, rightB);    // Step 3: right boundary

      reverse(rightB.begin(), rightB.end()); // reverse right boundary

      // Step 4: Combine all parts
      vector<int> ans;
      ans.push_back(root->data);                     // root
      ans.insert(ans.end(), leftB.begin(), leftB.end());   // left boundary
      ans.insert(ans.end(), bottomB.begin(), bottomB.end()); // leaves
      ans.insert(ans.end(), rightB.begin(), rightB.end());   // right boundary reversed

      return ans;
  }
};

/*
⏱️ Time Complexity: O(n)
- Each node is visited once either in left, right or leaf traversal.

📦 Space Complexity: O(h) recursion stack + O(n) for result vectors
- h = height of the tree (in worst case: skewed tree)
*/
