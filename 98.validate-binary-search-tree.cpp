/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
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
 * 
 * 它的每个节点的左子树都比该节点小，右子树都比该节点大。
 * 因此，判断一棵树是否是二叉搜索树，需要对每个节点进行判断
 * 同时需要比较其左子树和右子树的值。
 * 递归法:
 * 对于每个节点，递归地检查其左右子树是否满足要求，
 * 并且该节点的值是否大于左子树的最大值，小于右子树的最小值。
 * 需要注意的是，当递归到空节点时，应该返回 true，因为空节点本身符合二叉搜索树的定义。
 */
class Solution {
public:
    
    bool isValidBST(TreeNode* root) {
        // init as LONG_MIN and LONG_MAX
        return isValidBST(root, LONG_MIN, LONG_MAX);
        
    }
    bool isValidBST(TreeNode* root, long minval, long maxval) {
        if(root == nullptr) return true;
        if(root->val <= minval || root->val >= maxval) return false;

        return isValidBST(root->left, minval, root->val) && isValidBST(root->right, root->val, maxval);

    }
};
// @lc code=end

