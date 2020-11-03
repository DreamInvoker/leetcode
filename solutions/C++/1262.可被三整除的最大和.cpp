/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 *`
 * [1262] 可被三整除的最大和
 *
 * https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/description/
 *
 * algorithms
 * Medium (44.84%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 9.1K
 * Testcase Example:  '[3,6,5,1,8]'
 *
 * 给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,6,5,1,8]
 * 输出：18
 * 解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
 * 
 * 示例 2：
 * 
 * 输入：nums = [4]
 * 输出：0
 * 解释：4 不能被 3 整除，所以无法选出数字，返回 0。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,2,3,4,4]
 * 输出：12
 * 解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 4 * 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 使用动态规划，dp[i]表示数字和 模 3 = i的数字和
 * 
 * 每遍历一个数，我们可以计算mod 3的结果，为i
 * 那么他可以和之前数字和模3等于3 - i的相加，得到模3为0的新的数字和
 * 可以和之前数字和模3等于3 + 1 - i的相加，得到模3为1的新的数字和
 * 可以和之前数字和模3等于3 + 2 - i的相加，得到模3为2的新的数字和
 * 
 */

// @lc code=start
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int dp[3] = {0, 0, 0};
        int a, b, c;
        for(int i = 0; i < nums.size(); ++i){
            int mod = nums[i] % 3;
            a = dp[(3 + 0 - mod) % 3];
            b = dp[(3 + 1 - mod) % 3];
            c = dp[(3 + 2 - mod) % 3];
            if(a || mod == 0) dp[0] = max(dp[0], a + nums[i]);
            if(b || mod == 1) dp[1] = max(dp[1], b + nums[i]);
            if(c || mod == 2) dp[2] = max(dp[2], c + nums[i]);
        }
        return dp[0];
    }
};
// @lc code=end

