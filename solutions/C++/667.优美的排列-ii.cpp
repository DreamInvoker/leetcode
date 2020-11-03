/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 *
 * https://leetcode-cn.com/problems/beautiful-arrangement-ii/description/
 *
 * algorithms
 * Medium (59.12%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 6.2K
 * Testcase Example:  '3\n2'
 *
 * 给定两个整数 n 和 k，你需要实现一个数组，这个数组包含从 1 到 n 的 n 个不同整数，同时满足以下条件：
 * 
 * ① 如果这个数组是 [a1, a2, a3, ... , an] ，那么数组 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ...
 * , |an-1 - an|] 中应该有且仅有 k 个不同整数；.
 * 
 * ② 如果存在多种答案，你只需实现并返回其中任意一种.
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 3, k = 1
 * 输出: [1, 2, 3]
 * 解释: [1, 2, 3] 包含 3 个范围在 1-3 的不同整数， 并且 [1, 1] 中有且仅有 1 个不同整数 : 1
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 3, k = 2
 * 输出: [1, 3, 2]
 * 解释: [1, 3, 2] 包含 3 个范围在 1-3 的不同整数， 并且 [2, 1] 中有且仅有 2 个不同整数: 1 和 2
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * n 和 k 满足条件 1 <= k < n <= 10^4.
 * 
 * 可以先枚举n和k的情况，从例子中找出路
 * 比如n=9,k=8时，这时候的情况只有[1, 9, 2, 8, 3, 7, 4, 6, 5]
 * 可以用双指针的形式，i = 1, j = 9, 这里就是i++, j--, i++, j--, i++, j--, i++, j--, i++
 * 当k<8时，只需要保持前面k-1个不同的差值，后面按顺序排列（即差值为1），就可以做到k个不同的差值
 * 
 * 这道题我觉得用了枚举法 + 双指针法
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for(int i = 1, j = n; i <= j; ){
            if(k > 1){
                res.push_back(k-- % 2 ? i++ : j--);
            }else{
                res.push_back(i++);
            }
        }
        return res;
    }
};
// @lc code=end

