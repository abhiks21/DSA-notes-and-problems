/*
Problem:
Print the left view of a binary tree. 
Left view means the first node visible from the left at each level.

Approach:
- Use Level Order Traversal (BFS) using a queue.
- For each level, the first node encountered is part of the left view.
- Push this first node's value into the answer vector before processing the rest of the level.

Time Complexity: O(n) 
    - Each node is visited exactly once.
Space Complexity: O(n)
    - Queue stores up to one level of nodes.

*/

class Solution {
  public:
    void Ltraverse(Node* root, vector<int>& lView){
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            // Add the first node of the current level to left view
            lView.push_back(q.front()->data);
            
            for(int i = 0; i < size; i++){
                Node* cur = q.front();
                q.pop();
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
    }

    vector<int> leftView(Node *root) {
        vector<int> Lview;
        Ltraverse(root, Lview);
        return Lview;
    }
};
