/*
 * @lc app=leetcode.cn id=1296 lang=cpp
 *
 * [1296] 划分数组为连续数字的集合
 *
 * https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/
 *
 * algorithms
 * Medium (41.99%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 10.1K
 * Testcase Example:  '[1,2,3,3,4,4,5,6]\n4'
 *
 * 给你一个整数数组 nums 和一个正整数 k，请你判断是否可以把这个数组划分成一些由 k 个连续数字组成的集合。
 * 如果可以，请返回 True；否则，返回 False。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,3,4,4,5,6], k = 4
 * 输出：true
 * 解释：数组可以分成 [1,2,3,4] 和 [3,4,5,6]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
 * 输出：true
 * 解释：数组可以分成 [1,2,3] , [2,3,4] , [3,4,5] 和 [9,10,11]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [3,3,2,2,1,1], k = 3
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums = [1,2,3,4], k = 3
 * 输出：false
 * 解释：数组不能分成几个大小为 3 的子数组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= nums.length
 * 
 * 当同时需要排序加上从小到大遍历的时候，使用map（自带根据key来排序）
 * 如果不需要排序则用unordered_map
 * 
 * 
 */

// @lc code=start
#include <map>
using namespace std;
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int len = nums.size();
        if(len % k != 0)
            return false;
        map<int, int> s;
        for(auto n:nums){
            s[n] ++;
        }

        for(auto iter = s.begin(); iter != s.end(); ++iter){
            int num = iter->first;
            int occ = iter->second;
            if(occ > 0){
                auto it = next(iter);
                for(int i = 1; i < k; ++i, ++it){
                    if(it != s.end() && it->first == num + i && it->second >= occ){
                        it->second -= occ;
                    }else{
                        return false;
                    }
                }
            }

        }
        return true;
    }
};
// @lc code=end

