/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 * 
 * 使用前缀和的方法。
 * 
 * 假设我们有5个字符，先不用care这5个字符是什么，那么翻转之后的最终结果要在以下字符串中选一个翻转次数最小的。
 * “00000”， “00001”， “00011”， “00111”， “01111”， “11111”
 * 因此我们可以把这个问题转化成为[分割问题]，即划分位置左边全为0，右边全为1，
 * 对于一个有N个字符的字符串来说，一共有(N+1)个划分位置，假设为5， 字符串为：101010，划分位置(以‘.’表示)可能为：.1.0.1.0.1.0.
 * 这样的话，我们就可以用P数组保存好每个划分位置左边1的个数，来求出我们当前位置需要翻转的次数
 * 
 * 假设我们在N个字符的字符串第i位置进行划分，假设P[i]是它左边为1的字符个数，那么因为我们要得到这个划分位置左边全为0，右边全为1，
 * 所以左边需要翻转的个数即为左边为1的字符数，即P[i]
 * 而右边的1的个数为P[N]-P[i]，这些1不需要翻转，需要翻转的是0，右边的字符数为N-i，所以右边0的个数即翻转数为N-i-(P[N]-P[i])
 * 所以该划分位置的总的翻转个数为P[i] + N-i-(P[N]-P[i]) = 2 * P[i] + N - i - P[N]
 * 
 * 使用动态规划的方式来保存每个划分位置左边有多少个1 (详见代码)
 * 
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int size = S.size();
        vector<int> dp(size + 1, 0);

        for(int i = 1; i <= size; ++i){
            dp[i] = dp[i - 1] + (S[i - 1] == '1' ? 1 : 0);
        }
        int ans = 20000;
        for(int i = 0; i <= size; ++i){
            ans = min(ans, dp[i] + size - i - (dp[size] - dp[i]));
        }
        return ans;
    }
};
// @lc code=end

