/*
 * @lc app=leetcode.cn id=1414 lang=cpp
 *
 * [1414] 和为 K 的最少斐波那契数字数目
 *
 * https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/
 *
 * algorithms
 * Medium (54.42%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 5.9K
 * Testcase Example:  '7'
 *
 * 给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。
 * 
 * 斐波那契数字定义为：
 * 
 * 
 * F1 = 1
 * F2 = 1
 * Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
 * 
 * 
 * 数据保证对于给定的 k ，一定能找到可行解。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：k = 7
 * 输出：2 
 * 解释：斐波那契数字为：1，1，2，3，5，8，13，……
 * 对于 k = 7 ，我们可以得到 2 + 5 = 7 。
 * 
 * 示例 2：
 * 
 * 输入：k = 10
 * 输出：2 
 * 解释：对于 k = 10 ，我们可以得到 2 + 8 = 10 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：k = 19
 * 输出：3 
 * 解释：对于 k = 19 ，我们可以得到 1 + 5 + 13 = 19 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int a = 1, b = 1;
        vector<int> body = {a, b};
        while(a + b <= k){
            int c = a + b;
            body.push_back(c);
            a = b;
            b = c;
        }
        int ans = 0;
        for(int i = body.size() - 1; i >= 0; --i){
            if(k >= body[i]){
                ans ++;
                k -= body[i];
            }
        }
        return ans;
    }
};
// @lc code=end

