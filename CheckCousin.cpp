class Solution {
public:
    int c1 = -1, c2 = -1;

    bool checkParent(Node* root, int x, int y) {
        if (!root) return false;

        if (root->left && root->right) {
            if ((root->left->data == x && root->right->data == y) ||
                (root->left->data == y && root->right->data == x)) {
                return true;
            }
        }

        return checkParent(root->left, x, y) || checkParent(root->right, x, y);
    }

    void hasLevel(Node* root, int x, int y) {
        if (!root) return;

        queue<Node*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* cur = q.front();
                q.pop();

                if (cur->data == x) c1 = level;
                if (cur->data == y) c2 = level;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            level++;
        }
    }

    bool isCousins(Node* root, int x, int y) {
        c1 = -1; c2 = -1;  // Reset before use
        hasLevel(root, x, y);

        if (c1 != c2 || c1 == -1 || c2 == -1) return false;

        bool sameParent = checkParent(root, x, y);
        return !sameParent;
    }
};
