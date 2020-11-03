/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 *
 * https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
 *
 * algorithms
 * Medium (38.29%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 16.8K
 * Testcase Example:  '["un","iq","ue"]'
 *
 * 给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。
 * 
 * 请返回所有可行解 s 中最长长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = ["un","iq","ue"]
 * 输出：4
 * 解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = ["cha","r","act","ers"]
 * 输出：6
 * 解释：可能的解答有 "chaers" 和 "acters"。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
 * 输出：26
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 16
 * 1 <= arr[i].length <= 26
 * arr[i] 中只含有小写英文字母
 * 
 * 回溯法，使用二级制记录是否存在，1<<5，说明第5个字母f存在
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int m = 0;   
        return dfs(arr, 0, m);
    }
private:
    int dfs(vector<string>& arr, int childIndex, int m) {
        if (childIndex == arr.size()) {
            return 0;
        }
        int t = m;
        if (isUnique(arr[childIndex], t)) {
            int curLen = arr[childIndex].length();
            int len1 = curLen + dfs(arr, childIndex+1, t);
            int len2 = dfs(arr, childIndex+1, m);
            return max(len1, len2);
        }
        return dfs(arr, childIndex+1, m);
    }
    /*注意这里要加引用，改变原有的t*/
    bool isUnique(string& s, int& t){
        for(char c:s){
            int i = c - 'a';
            if(t & (1<<i)){
                return false;
            }
            t |= (1<<i);
        }
        return true;
    }
    
    
};
// @lc code=end

