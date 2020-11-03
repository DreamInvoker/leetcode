/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 * 
 * 刚开始是想把indexes进行排序来做，但是发现复杂度有点高（因为需要同时排序sources和target，保证顺序的一致性），所以一直在这卡着。
 * 
 * 但是看了解析发现其实可以用一个辅助数组，遍历indexes保存对应的映射，来实现和排序一样的效果。
 * 
 * substr获得子串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ans;
        vector<int> m(S.size(), -1);
        for(int i = 0; i < indexes.size(); ++i){
            int index = indexes[i];
            string src = sources[i];
            string tmp = S.substr(index, src.size());
            if(src == tmp)
                m[index] = i;
        }
        for(int i = 0; i < S.size(); ++i){
            if(m[i] != -1){
                ans += targets[m[i]];
                i += sources[m[i]].size() - 1;
            }else{
                ans = ans + string(1, S[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

