/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 *
 * https://leetcode-cn.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (63.74%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 10.5K
 * Testcase Example:  '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * 给定两个由一些 闭区间 组成的列表，每个区间列表都是成对不相交的，并且已经排序。
 * 
 * 返回这两个区间列表的交集。
 * 
 * （形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <=
 * b。两个闭区间的交集是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。）
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
 * 输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length < 1000
 * 0 <= B.length < 1000
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < A.size() && j < B.size()){
            vector<int> tmp;
            if(A[i][1] < B[j][0]) {
                i++;
                continue;
            }else if(A[i][0] > B[j][1]){
                j++;
                continue;
            }
            tmp.push_back(max(A[i][0], B[j][0]));
            tmp.push_back(min(A[i][1], B[j][1]));
            ans.push_back(tmp);
            if(B[j][1] > A[i][1]) i++;
            else if(B[j][1] < A[i][1]) j++;
            else i++, j++;
        }
        return ans;
    }
};
// @lc code=end

