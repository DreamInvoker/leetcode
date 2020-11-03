/*
 * @lc app=leetcode.cn id=1072 lang=cpp
 *
 * [1072] 按列翻转得到最大值等行数
 *
 * https://leetcode-cn.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/
 *
 * algorithms
 * Medium (49.28%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    1.8K
 * Total Submissions: 3.4K
 * Testcase Example:  '[[0,1],[1,1]]'
 *
 * 给定由若干 0 和 1 组成的矩阵 matrix，从中选出任意数量的列并翻转其上的 每个 单元格。翻转后，单元格的值从 0 变成 1，或者从 1 变为
 * 0 。
 * 
 * 返回经过一些翻转后，行上所有值都相等的最大行数。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[0,1],[1,1]]
 * 输出：1
 * 解释：不进行翻转，有 1 行所有值都相等。
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[0,1],[1,0]]
 * 输出：2
 * 解释：翻转第一列的值之后，这两行都由相等的值组成。
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[0,0,0],[0,0,1],[1,1,0]]
 * 输出：2
 * 解释：翻转前两列的值之后，后两行由相等的值组成。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= matrix.length <= 300
 * 1 <= matrix[i].length <= 300
 * 所有 matrix[i].length 都相等
 * matrix[i][j] 为 0 或 1
 * 
 * 经过翻转之后，行上所有值相等的两行，要么全相等，要么全相反
 * 
 * 可以使用判断第一个字符是否为1，如果为1，就这一行不变，如果为0，这一行全部取反。
 * 这种归一化方式妙啊
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        int res = 1;
        for(auto& r: matrix){
            string s;
            int d = 0 ^ r[0];
            for(auto x: r){
                s += (d ^ x) + '0';
            }
            m[s] ++;
            res = max(res, m[s]);
        }
        return res;
    }

};
// @lc code=end

