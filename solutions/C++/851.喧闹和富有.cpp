/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 *
 * https://leetcode-cn.com/problems/loud-and-rich/description/
 *
 * algorithms
 * Medium (43.39%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    1.9K
 * Total Submissions: 4.4K
 * Testcase Example:  '[[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]\n[3,2,5,4,6,1,7,0]'
 *
 * 在一组 N 个人（编号为 0, 1, 2, ..., N-1）中，每个人都有不同数目的钱，以及不同程度的安静（quietness）。
 * 
 * 为了方便起见，我们将编号为 x 的人简称为 "person x "。
 * 
 * 如果能够肯定 person x 比 person y 更有钱的话，我们会说 richer[i] = [x, y] 。注意 richer
 * 可能只是有效观察的一个子集。
 * 
 * 另外，如果 person x 的安静程度为 q ，我们会说 quiet[x] = q 。
 * 
 * 现在，返回答案 answer ，其中 answer[x] = y 的前提是，在所有拥有的钱不少于 person x 的人中，person y
 * 是最安静的人（也就是安静值 quiet[y] 最小的人）。
 * 
 * 示例：
 * 
 * 输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet =
 * [3,2,5,4,6,1,7,0]
 * 输出：[5,5,2,5,4,5,6,7]
 * 解释： 
 * answer[0] = 5，
 * person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0
 * 有更多的钱。
 * 唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
 * 但是目前还不清楚他是否比 person 0 更有钱。
 * 
 * answer[7] = 7，
 * 在所有拥有的钱肯定不少于 person 7 的人中(这可能包括 person 3，4，5，6 以及 7)，
 * 最安静(有较低安静值 quiet[x])的人是 person 7。
 * 
 * 其他的答案也可以用类似的推理来解释。
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= quiet.length = N <= 500
 * 0 <= quiet[i] < N，所有 quiet[i] 都不相同。
 * 0 <= richer.length <= N * (N-1) / 2
 * 0 <= richer[i][j] < N
 * richer[i][0] != richer[i][1]
 * richer[i] 都是不同的。
 * 对 richer 的观察在逻辑上是一致的。
 * 
 * 
 * 解法：由于richer中每个元素其实就是有向边的表示，所以这个问题可以理解为DFS遍历的问题
 * （由于对richer的观察逻辑一致，因此这个图肯定是有向的无环图）
 * 
 * 注意我们如果已经计算了一条路径，则可以保存，这样可以避免重复计算
 * 
 * ps:使用unordered_map来保存有向边
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> richer2;
    vector<int> res;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for(auto& edge: richer) richer2[edge[1]].push_back(edge[0]);
        int N = quiet.size();
        res = vector<int>(N, -1);
        for(int i = 0; i < N; ++i){
            dfs(i, quiet);
        }
        return res;
    }
    int dfs(int i, vector<int> quiet){
        if(res[i] >= 0) return res[i]; // 避免重复计算
        res[i] = i;
        for(auto& r: richer2[i]){
            int cand = dfs(r, quiet);
            if(quiet[cand] < quiet[res[i]])
                res[i] = res[r];
        }
        return res[i];
    }
};
// @lc code=end

