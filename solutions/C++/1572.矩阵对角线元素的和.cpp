/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += mat[i][i] + mat[i][n - 1 - i];
        }
        if(n % 2 != 0){
            sum -= mat[n / 2][n / 2];
        }
        return sum;
    }
};
// @lc code=end

