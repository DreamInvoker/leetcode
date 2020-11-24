/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 * 
 * 该路径一定有一个根，可以把这个路径由根将左右看做是两个箭头，每个箭头我们计算他们的同值路径长度，然后把他们加起来，得到这个路径的长度。
 * 
 * 所以我们相当于可以遍历所有树中的节点，以该节点为根，来将左右两边的箭头的长度相加，最终得到最大的长度。
 * 
 * 这可以视为一种自底向上的过程，刚开始想的是自顶向下，但是解决不了一个子树全是同值的问题。
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
 */
#include <iostream>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    int ans;
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        digui(root);
        return ans;
    }
    int digui(TreeNode* root){
        if(root == nullptr) return 0;
        int left = digui(root->left);
        int right = digui(root->right);
        int left_arrow = 0, right_arrow = 0;
        if(root->left != nullptr && root->left->val == root->val){
            left_arrow += left + 1;
        }
        if(root->right != nullptr && root->right->val == root->val){
            right_arrow += right + 1;
        }
        ans = max(ans, left_arrow + right_arrow);
        return max(left_arrow, right_arrow);
    }
    // int digui(TreeNode* root, int val){
    //     if(root == nullptr) return val;
    //     int cur = root->val;
    //     cout << "cur: " << cur << endl;
    //     int v = 0;
    //     if(root->left != nullptr){
    //         int left_val = root->left->val;
    //         if(root->right != nullptr){
    //             int right_val = root->right->val;
    //             if(left_val == cur){
    //                 if(right_val == cur){
    //                     int a = max(digui(root->left, val + 1), digui(root->right, val + 1));
    //                     int b = digui(root->left, 1) + digui(root->right, 1);
    //                     if (b > a){
    //                         v = b;
    //                     }else{
    //                         v = a;
    //                     }  
    //                 }else{
    //                     v = max(digui(root->left, val + 1), digui(root->right, 0));
    //                 }
    //             }else{
    //                 if(right_val == cur){
    //                     v = max(digui(root->left, 0), digui(root->right, val + 1));
    //                 }else{
    //                     v = max(digui(root->left, 0), digui(root->right, 0));
    //                 }

    //             }
    //         }else{
    //             if(left_val == cur){
    //                 v = digui(root->left, val + 1);
    //             }else{
    //                 v = digui(root->left, 0);
    //             }
    //         }
    //     }else{
    //         if(root->right != nullptr){
    //             int right_val = root->right->val;
    //             if(right_val == cur){
    //                 v = digui(root->right, val + 1);
    //             }else{
    //                 v = digui(root->right, 0);
    //             }
    //         }else{
    //             v = val;
    //         }
    //     }
    //     cout << "v: " << v << endl;
    //     return v; 
    // }
};
// @lc code=end

