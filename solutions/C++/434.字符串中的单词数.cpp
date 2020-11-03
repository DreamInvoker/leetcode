/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 * 
 * 要注意细节：
 * 处理输入，看每道题的时候一定要看清楚输入是不是需要处理
 * 要使用给定的例子带入验证，看是不是正确的
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0)
            return 0;
        int count = 0;
        char pre = s[0];
        for(int i = 1; i < s.size(); ++i){
            char cur = s[i];
            if(cur == ' ' && pre != ' '){
                count ++;
            }
            pre = cur;
        }
        if(pre != ' ')
            count ++;
        return count;
    }
};
// @lc code=end

