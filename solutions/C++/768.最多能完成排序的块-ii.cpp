/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II

总体思路：排序块的最大值肯定小于块左边的所有的数，所以我们每次都找最左边的排序块。

 方法一：使用双指针，判断两个指针包含的块中，最大值是否都小于这个块左边的数， 
        如果满足，则滑动到下一个双指针窗口

        这样的最坏情况下的时间复杂度是O(N^2)，如[1, 2, 3, 4, 5]

 方法二：使用栈

 我们试想一种只用遍历一遍数组的方法，每次判断当前遍历的数字与前一个排序块最大值head的大小，
        
        如果该数字大于等于head，那么久形成一个新的排序块

        如果改数字小于head，那么就需要判断之前所有的排序块的合理性，所以需要往前判断该数字是否小于他们的最大值

        因此这种先进后出的思路可以联想到使用栈的数据结构来存储head。
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> s;
        int length = arr.size();
        for(int i = 0; i < length; ++i){
            if(s.empty()){
                s.push(arr[i]);
            }else{
                if(s.top() <= arr[i]){
                    s.push(arr[i]);
                }else{
                    int tmp = s.top();
                    while(!s.empty() && s.top() > arr[i]){
                        s.pop();
                    }
                    s.push(tmp);
                }
            }
        }
        return s.size();
    }
};
// @lc code=end

