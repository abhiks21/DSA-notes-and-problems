// 📌 Problem: Right View of Binary Tree
//    Given a binary tree, return the list of nodes you see when looking at the tree from the right side (rightmost node at each level).

// 🧠 Approach:
//    - Use **Level Order Traversal** (BFS) using a queue.
//    - At each level, capture the **first node** in the queue (which will be the rightmost node of that level).
//    - To ensure rightmost nodes appear first, push **right child before left child** into the queue.

// ⚠️ Trick Used:
//    - Unlike the standard BFS where we push left child first, we push **right child first** here.
//    - This ensures the **first node at each level** is the **rightmost node**, so we can simply take `q.front()`.

// ✅ Time Complexity: O(N), where N = number of nodes
// ✅ Space Complexity: O(N), for queue and output vector

class Solution {
  public:
    // BFS-based helper function to fill right view
    void lTraverse(Node* root, vector<int> &rView){
        if(!root) return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            // The first node in the queue will be the rightmost at this level
            rView.push_back(q.front()->data);

            for(int i = 0; i < size; i++){
                Node* cur = q.front();
                q.pop();

                // Push right first, then left to ensure rightmost appears first in next level
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
        }
    }

    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        vector<int> rView;
        lTraverse(root, rView);
        return rView;
    }
};
