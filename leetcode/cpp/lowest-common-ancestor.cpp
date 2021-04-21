/*
    给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        // q、p都在左子树
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // q、p都在右子树
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};


/*
    给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left&&right) {
            return root;
        } else if (left) {
            return left;
        } else if (right) {
            return right;
        } else {
            return nullptr;
        }
    }
};