/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 *
 * https://leetcode-cn.com/problems/brick-wall/description/
 *
 * algorithms
 * Medium (37.16%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    12.2K
 * Total Submissions: 32.7K
 * Testcase Example:  '[[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]'
 *
 * 你的面前有一堵矩形的、由多行砖块组成的砖墙。 这些砖块高度相同但是宽度不同。你现在要画一条自顶向下的、穿过最少砖块的垂线。
 * 
 * 砖墙由行的列表表示。 每一行都是一个代表从左至右每块砖的宽度的整数列表。
 * 
 * 如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你需要找出怎样画才能使这条线穿过的砖块数量最少，并且返回穿过的砖块数量。
 * 
 * 你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: [[1,2,2,1],
 * ⁠     [3,1,2],
 * ⁠     [1,3,2],
 * ⁠     [2,4],
 * ⁠     [3,1,2],
 * ⁠     [1,3,1,1]]
 * 
 * 输出: 2
 * 
 * 解释: 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每一行砖块的宽度之和应该相等，并且不能超过 INT_MAX。
 * 每一行砖块的数量在 [1,10,000] 范围内， 墙的高度在 [1,10,000] 范围内， 总的砖块数量不超过 20,000。
 * 
 * 解法：使用hash map保存在垂直上边缘相同的砖块，这样的话边缘相同越多的位置，穿过的砖块越少
 * 
 * 注意：一定要跳过每行的最后一块砖
 * 
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edges;
        int height = wall.size();
        int min_bricks = height;
        for(auto row: wall)
            for(auto i = 0, width = 0; i < row.size() - 1; ++i){
                min_bricks = min(min_bricks, height - (++edges[width += row[i]]));
            }
        return min_bricks;
    }
};
// @lc code=end

