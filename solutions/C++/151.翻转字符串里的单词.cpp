/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (36.43%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    35.1K
 * Total Submissions: 95.8K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 
 * 
 * 示例 3：
 * 
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmp;
        int len = s.size();
        int i, j;
        if(len == 0) return s;
        for(i = 0; i < len; i = j){
            if(s[i] == ' '){
                j = i + 1;
                continue;
            }
            for(j = i; j < len; ++j){
                if(s[j] == ' '){
                    break;
                }
            }
            tmp.push_back(s.substr(i, j - i));
            
        }
        reverse(tmp.begin(), tmp.end());
        string ans = "";
        for(auto &str: tmp){
            ans += str + " ";
        }
        ans.pop_back();
        return ans;
    }

};
// @lc code=end

