/*
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_sum = INT_MIN;
    //后序遍历树，返回经过root的单边最大路径和，并维护整棵树的最大路径和
    int dfs(TreeNode* node)
    {
        //终止条件
        if (node == nullptr) return 0;

        //深度优先，获取左右分支的最大路径和，本结点作为联络点
        //若左右分支返回的值为负数，则对路径和做负贡献，直接舍弃
        int left_max  = max(0, dfs(node->left));
        int right_max = max(0, dfs(node->right));
        
        //由于路径最大的一种可能为left->node->right，而不向root的父结点延伸
        int lnr_sum = left_max + node->val + right_max;
        //更新最大值，全是负数结点的情况，也会在这里更新最大的负数
        max_sum = max(max_sum, lnr_sum);

        //向node的父结点返回经过node的单边分支的最大路径和
        int ret = node->val + max(left_max, right_max);
        return ret;
    }
    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        return max_sum;
    }
};
