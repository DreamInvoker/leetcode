/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 * 使用辅助数组保存每个建筑物的纵向最大高度和横向最大高度，每个建筑物增加时不能超过这两个高度的最小值
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> L(grid.size(), 0);
        vector<int> width(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                L[i] = max(grid[i][j], L[i]);
                width[j] = max(grid[i][j], width[j]);
            }
        }
        int ret = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                int some = min(L[i], width[j]) - grid[i][j];
                ret += some ;
                cout << some << " ";
            }
            cout << endl;
        }
        return ret;
    }
};
// @lc code=end

