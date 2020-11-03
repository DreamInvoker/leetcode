/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> map;
        unordered_map<char, string> reversed_map;

        string tmp = "";
        int j = 0;
        for(int i = 0; i < s.size(); ++i){
            char cur = s[i];
            cout << "cur: " << cur << endl;
            if(cur == ' ' || i == s.size() - 1){
                if(i == s.size() - 1)
                    tmp += string(1, cur);
                unordered_map<string, char>::const_iterator got = map.find(tmp);
                cout << "j: " << j << endl;
                if(got == map.end()){
                    map[tmp] = pattern[j];
                }else{
                    if(map[tmp] != pattern[j]){
                        cout << "tmp: " << tmp << endl;
                        cout << "pattern char: " << pattern[j] << " " << "j: " << j << endl;
                        cout << "not" << endl;
                        return false;
                    }
                }
                unordered_map<char, string>::const_iterator got2 = reversed_map.find(pattern[j]);
                if(got2 == reversed_map.end()){
                    reversed_map[pattern[j]] = tmp;
                }else{
                    if(reversed_map[pattern[j]] != tmp){
                        cout << "tmp: " << tmp << endl;
                        cout << "pattern char: " << pattern[j] << " " << "j: " << j << endl;
                        cout << "not" << endl;
                        return false;
                    }
                }
                tmp = "";
                j ++;
            }else{
                tmp += string(1, cur);
            }
        }
        if(j != pattern.size())
            return false;
        return true;
    }
};
// @lc code=end

