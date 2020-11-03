/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 *
 * https://leetcode-cn.com/problems/element-appearing-more-than-25-in-sorted-array/description/
 *
 * algorithms
 * Easy (60.58%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 7.2K
 * Testcase Example:  '[1,2,2,6,6,6,6,7,10]'
 *
 * 给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。
 * 
 * 请你找到并返回这个整数
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：arr = [1,2,2,6,6,6,6,7,10]
 * 输出：6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^5
 * 
 * 
 * 这样的元素只能出现在25%, 50%和70%的位置，所以根据这三个位置的元素，根据二分法找他们的边界计算长度是否大于25%, 实际上，如果25%和50%不是的话，返回75%位置的元素就行了
 * 
 * TODO 可以使用STL中的lower_bound()和upper_bound()得到上下边界，这个不知道是不是二分法确定的，待验证
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        arr.push_back(-1);
        int l = arr.size();
        int num = (int) (0.25 * l); 
        int i = 0;
        for(int j = 1; j < l; ++j){
            if(arr[j] != arr[i]){
                if(j - i > num){
                    return arr[i];
                }
                i = j;
            }
        }
        return arr[0];
    }
};
// @lc code=end

