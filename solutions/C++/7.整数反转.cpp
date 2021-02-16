/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转

1.对于整数逆转，可以边存余数边乘10
2. 结果要用long来存，以为是会出现4个字节以上的整数
3. 直接用INT_MAX和INT_MIN来判断边界就行了，不用每次都判断，因为是long，存的下可以最后再判断


 */

// @lc code=start


class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x != 0){
            result = result * 10 + x % 10;
            x /= 10;
        }

        return (result > INT_MAX || result < INT_MIN) ? 0 : result;

    }
};
// @lc code=end

