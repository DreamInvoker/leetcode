/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (50.46%)
 * Likes:    678
 * Dislikes: 0
 * Total Accepted:    113.7K
 * Total Submissions: 224.8K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        if(root->left == NULL ^ root->right == NULL)
            return false;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        TreeNode *a, *b;
        while(!q.empty()){
            a = q.front();
            q.pop();
            b = q.front();
            q.pop();
            if(a == NULL && b == NULL)
                continue;
            if(a == NULL ^ b == NULL)
                return false;
            if(a->val == b->val){
                q.push(a->left);
                q.push(b->right);
                q.push(a->right);
                q.push(b->left);
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

