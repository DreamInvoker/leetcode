/*
 * @lc app=leetcode.cn id=1201 lang=cpp
 *
 * [1201] 丑数 III
 *
 * https://leetcode-cn.com/problems/ugly-number-iii/description/
 *
 * algorithms
 * Medium (20.57%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    2.8K
 * Total Submissions: 12.7K
 * Testcase Example:  '3\n2\n3\n5'
 *
 * 请你帮忙设计一个程序，用来找出第 n 个丑数。
 * 
 * 丑数是可以被 a 或 b 或 c 整除的 正整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 3, a = 2, b = 3, c = 5
 * 输出：4
 * 解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
 * 
 * 示例 2：
 * 
 * 输入：n = 4, a = 2, b = 3, c = 4
 * 输出：6
 * 解释：丑数序列为 2, 3, 4, 6, 8, 9, 12... 其中第 4 个是 6。
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 5, a = 2, b = 11, c = 13
 * 输出：10
 * 解释：丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
 * 
 * 
 * 示例 4：
 * 
 * 输入：n = 1000000000, a = 2, b = 217983653, c = 336916467
 * 输出：1999999984
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n, a, b, c <= 10^9
 * 1 <= a * b * c <= 10^18
 * 本题结果在 [1, 2 * 10^9] 的范围内
 * 
 * 
 * 看到n的范围特别大，就要想到使用二分的策略来解
 * 但是这里的二分不同于二分查找的二分：
 * 我们找到的元素我们应该去看他前面所包含的丑数个数
 * 那么就需要看前面有多少可以整除a,b和c的
 * 这样的话就需要去重和公倍数计算的函数
 * 
 */

// @lc code=start
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    using LL = long long;
    int nthUglyNumber(int n, int a, int b, int c) {
        LL low = min(a, min(b, c));
        LL high = static_cast<LL>(low) * n;

        LL res = BinarySearch(low, high, a, b, c, n);

        LL left_a = res % a;
        LL left_b = res % b;
        LL left_c = res % c;

        return res - min(left_a, min(left_b, left_c));
    }

    LL BinarySearch(LL low, LL high, int a, int b, int c, int n){
        if(low >= high) return low;
        LL mid = (low + high) >> 1;
        LL MCM_a_b = MCM(a, b);
        LL MCM_a_c = MCM(a, c);
        LL MCM_b_c = MCM(b, c);
        LL MCM_a_b_c = MCM(MCM_a_b, c);

        LL count_n = mid / a + mid / b + mid / c - mid / MCM_a_b - mid / MCM_a_c - mid / MCM_b_c + mid / MCM_a_b_c;

        if(count_n == n) return mid;
        if(count_n < n) return BinarySearch(mid + 1, high, a, b, c, n);
        return BinarySearch(low, mid - 1, a, b, c, n);
    }

    LL MCM(LL a, LL b){
        LL multi = a * b;
        while(b > 0){
            LL tmp = a % b;
            a = b;
            b = tmp;
        }
        return multi / a;
    }
};
// @lc code=end

