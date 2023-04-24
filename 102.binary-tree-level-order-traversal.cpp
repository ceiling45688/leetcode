/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
 *  @Method: Queue 
 * 首先，将根节点放入队列中。
 * 然后，在每个循环迭代中，我们从队列中取出一个节点，处理该节点（例如，访问它的值）
 * 并将其所有子节点添加到队列中，以便在下一次迭代中处理它们
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if(root == NULL) return results;

        queue<TreeNode*> queue; // store node
        queue.push(root);

        while(!queue.empty()){
            vector<int> level;
            int levelSize = queue.size();
            
            for (int i = 0; i < levelSize; i++){
                /* deal with queue in level */
                TreeNode* node = queue.front(); // 一次只娶一个值
                queue.pop();
                level.push_back(node->val);

                if(node->left) {
                    queue.push(node->left);
                }
                if(node->right) {
                    queue.push(node->right);
                }
            }     

            results.push_back(level);
        }        
        return results;
    }
};
// @lc code=end

