/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列

 方法一：双指针
贪心地匹配靠前的字符是最优决策。

假定当前需要匹配字符 c，而字符 c 在 t 中的位置 x_1 和 x_2（x_1 < x_2），
那么贪心取 x_1是最优解，因为x_2后面能取到的字符，x_1也都能取到，
并且通过 x_1 与 x_2 之间的可选字符，更有希望能匹配成功。

这样，我们初始化两个指针 i 和 j，分别指向 s 和 t 的初始位置。每次贪心地匹配，匹配成功则 i 和 j 同时右移，匹配 s 的下一个位置，
匹配失败则 j 右移，i 不变，尝试用 t 的下一个字符匹配 s。

最终如果 i 移动到 s 的末尾，就说明 s 是 t 的子序列。



 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                // 时间都花在找t中下一个匹配的位置，
                // 动态规划的思路就是将这部分花的时间变成O(1)
                // 即构建一个dp数组来保存t中每一个位置之后的下一个字符的位置
                i ++;
            }
            j++;
        }
        return i == n;
    }

    /*

    // 动态规划的解法
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int>> f(m + 1, vector<int>(26, 0));

        for(int i = 0; i < 26; ++i){
            f[m][i] = m;
        }

        for(int i = m - 1; i >= 0; --i){
            for(int j = 0; j < 26; ++j){
                if(j == (t[i] - 'a')){
                    f[i][j] = i;
                }else{
                    f[i][j] = f[i + 1][j];
                }
            }
        }

        int add = 0;
        for(int ii = 0; ii < n; ++ii){
            if(f[add][s[ii] - 'a'] == m){
                return false;
            }
            add = f[add][s[ii] - 'a'] + 1;
        }
        return true;
    }
    */
};
// @lc code=end

