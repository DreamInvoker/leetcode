/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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

在遍历每一个节点时，判断当前节点的祖父节点是否为偶数，如果是偶数，则加上去。

 */
class Solution {
public:
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        search(root, -1, -1);
        return sum;
    }
    void search(TreeNode* root, int grand_father, int father){
        if(root != nullptr and grand_father % 2 == 0){
            sum += root->val;
        }
        if(root != nullptr){
            search(root->left, father, root->val);
            search(root->right, father, root->val);
        }
    }
};
// @lc code=end

