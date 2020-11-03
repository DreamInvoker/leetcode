/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 *
 * https://leetcode-cn.com/problems/shortest-common-supersequence/description/
 *
 * algorithms
 * Hard (43.16%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    1.3K
 * Total Submissions: 3K
 * Testcase Example:  '"abac"\n"cab"'
 *
 * 给出两个字符串 str1 和 str2，返回同时以 str1 和 str2
 * 作为子序列的最短字符串。如果答案不止一个，则可以返回满足条件的任意一个答案。
 * 
 * （如果从字符串 T 中删除一些字符（也可能不删除，并且选出的这些字符可以位于 T 中的 任意位置），可以得到字符串 S，那么 S 就是 T
 * 的子序列）
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：str1 = "abac", str2 = "cab"
 * 输出："cabac"
 * 解释：
 * str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。 
 * str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
 * 最终我们给出的答案是满足上述属性的最短字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 和 str2 都由小写英文字母组成。
 * 
 * 
 * 
 * 两个字符串的最长公共子序列LCS +
 * 第一个字符串除去LCS之后的序列 +
 * 第二个字符串除去LCS之后的序列
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = dp[i-1][j - 1] + str1[i - 1];
                }else{
                    dp[i][j] = (dp[i - 1][j].size() > dp[i][j-1].size()?dp[i-1][j]:dp[i][j-1]);
                }
            }
        }
        string ans, lcs=dp[n][m];
        int i  = 0, j = 0;
        for(char ch:lcs){
            while(i<n&&str1[i]!=ch)
                ans+=str1[i++];
            while(j<m&&str2[j]!=ch)
                ans += str2[j++];
            ans+=ch, i++, j++;
        }
        return ans + str1.substr(i) + str2.substr(j);

    }
};
// @lc code=end

