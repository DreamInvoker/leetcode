/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (61.99%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    30.3K
 * Total Submissions: 48.7K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 
 * 
 * 例如：
 * 
 * 输入: 原始二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
 * 
 * 
 * 
 * 注意：本题和 1038:
 * https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        recursiveSum(root, 0);
        return root;
    }
private:
    int recursiveSum(TreeNode* root, int accum){
        if(root == nullptr)
            return 0;
        cout << root->val << endl;
        cout << "begin right sum" <<endl;
        int right = recursiveSum(root->right, accum);
        cout << "right sum is " << right << endl;
        if(right != 0)
            root->val += right;
        else
            root->val += accum;
        int left = recursiveSum(root->left, root->val);
        if(left == 0)
            return root->val;
        else
            return left;

    }
};
// @lc code=end

