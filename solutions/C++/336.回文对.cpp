/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 * 
 * 
 * 
方法一：暴力解，枚举每一对字符串的组合，判断是否构成回文串，时间复杂度O(n^2 * m)，其中n是字符串的个数，m是字符串的平均长度。

方法二：假设两个字符串s_1和s_2，根据两者的长度大小，如果两者构成回文串，可以分为三种情况。
    所以，对于每个字符串，我们可以将其视为两个字符串中较长的那个，然后将其分成两个部分，其中一部分自身构成回文串，另一部分的翻转则可能出现在其他的字符串中。

    而要实现这些操作，我们只需要设计一个能够在一系列字符串中查询「某个字符串的子串的翻转」是否存在的数据结构，有两种实现方法：

    我们可以使用字典树存储所有的字符串。在进行查询时，我们将待查询串的子串逆序地在字典树上进行遍历，即可判断其是否存在。 

    我们可以使用哈希表存储所有字符串的翻转串。在进行查询时，我们判断带查询串的子串是否在哈希表中出现，就等价于判断了其翻转是否存在。

PS：字典树可以存储一个包含互不相同字符串的数组

    时间复杂度：O(n * m^2)
    空间复杂度：O(n * m)

*/

// @lc code=start

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// 字典树

/*
class Solution {
public:
    struct Node {
        int ch[26];
        int flag;
        Node() {
            flag = -1;
            memset(ch, 0, sizeof(ch));
        }
    };
    vector<Node> tree;
    void insert(string& s, int id){
        int len = s.size(), add = 0;
        for(int i = 0; i < len; i ++){
            int x = s[i] - 'a';
            if(!tree[add].ch[x]){
                tree.emplace_back();
                tree[add].ch[x] = tree.size() - 1;
            }
            add = tree[add].ch[x];
        }
        tree[add].flag = id;
    }

    int findWord(string& s, int left, int right){
        int add = 0;
        for(int i = right; i >= left; i --){
            int x = s[i] - 'a';
            if(!tree[add].ch[x]){
                return -1;
            }
            add = tree[add].ch[x];
        }
        return tree[add].flag;
    }

    bool isPalindrome(string& s, int left, int right){
        int len = right - left + 1;

        for(int i = 0; i < len / 2; ++i){
            if(s[left + i] != s[right - i]){
                return false;
            }
        }
        return true;
    }


    vector<vector<int>> palindromePairs(vector<string>& words) {
        tree.emplace_back(Node());
        int n = words.size();
        for(int i = 0; i < n; ++i){
            insert(words[i], i);
        }
        vector<vector<int>> ret;
        for(int i = 0; i < n; ++i){
            string cur_string = words[i];
            int m = cur_string.size();
            for(int j = 0; j <= m; j ++){
                if(isPalindrome(cur_string, j, m - 1)){
                    int right_id = findWord(cur_string, 0, j - 1);
                    if(right_id != -1 && right_id != i)
                        ret.push_back({i, right_id});
                }
                if(j && isPalindrome(cur_string, 0, j - 1)){
                    int left_id = findWord(cur_string, j, m - 1);
                    if(left_id != -1 && left_id != i)
                        ret.push_back({left_id, i});
                }

            }
        }
        return ret;
    }
};
*/

class Solution{
private:
    vector<string> wordsRev;
    unordered_map<string_view, int> indices;

public:
    int findWord(const string_view& s, int left, int right) {
        // 在C++中find相当于java的map.get()，返回iter，如果没找到那么就是indices.end()，如果找到了，iter->first就是map的key，iter->second就是map的value
        // string取子串substr
        // auto iter = indices.find(s.substr(left, right - left + 1));
        // return iter == indices.end() ? -1 : iter->second;

        auto iter = indices.find(s.substr(left, right - left + 1));
        return iter == indices.end() ? -1 : iter->second;
    }

    bool isPalindrome(const string_view& s, int left, int right) {
        int len = right - left + 1;
        for (int i = 0; i < len / 2; i++) {
            if (s[left + i] != s[right - i]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        // 将每个字符串的存入数组中，然后将其翻转
        for (const string& word: words) {
            wordsRev.push_back(word);
            reverse(wordsRev.back().begin(), wordsRev.back().end());
        }
        // 将翻转后的字符串存入unordered_map中
        for (int i = 0; i < n; ++i) {
            indices.emplace(wordsRev[i], i);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            if (!m) {
                continue;
            }
            string_view wordView(words[i]);
            for (int j = 0; j <= m; j++) {
                if (isPalindrome(wordView, j, m - 1)) {
                    int left_id = findWord(wordView, 0, j - 1);
                    if (left_id != -1 && left_id != i) {
                        ret.push_back({i, left_id});
                    }
                }
                if (j && isPalindrome(wordView, 0, j - 1)) {
                    int right_id = findWord(wordView, j, m - 1);
                    if (right_id != -1 && right_id != i) {
                        ret.push_back({right_id, i});
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end

