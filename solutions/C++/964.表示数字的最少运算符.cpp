/*
 * @lc app=leetcode.cn id=964 lang=cpp
 *
 * [964] 表示数字的最少运算符
 * 
 * 
 * 总体的思路是乘法越多越好
 * 
 * x/x, x, x*x, x*x*x, x*x*x*x,... 所需要的运算符个数分别为1, 0, 1, 2, 3, ...
 * 我们可以加上前置的+号，得到x^e的运算次数为e(例外：当e为0的时候，表达式为+x/x, 运算次数为2)，我们目标的运算次数为e-1
 * 
 * 所以我们可以先考虑target mod x^1 = r_1 的情况，这个时候只能用x^0来补或者删，将target加上 (x - r_1 / x^0) * x^0 或者减去r_1 * x^0，使其可以被x^1整除，这个时候得到的新target_2，加下来我们可以使用mod x^2的方式来得到使得结果为target_2的最佳次数，因为x^0
 * 
 * 在考虑target_2 mod x^2 = r_2 的情况，这个时候只能使用x^0或者x^1来补或者删，但是x^0没必要，毕竟x个x^0才能得到1个x^1，这是时候值就能将target_2加上（x - r_2 / x^1）* x^1 或者减去 r_2 / x^1 * x^1，使其可以被x^2整除
 * 
 * 以此类推
 * 
 * 
 * 要注意几个边界条件，特别是整除情况
 */

// @lc code=start
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    unordered_map<string, int> memory; // 为了保存已经计算好的值，提高后期再遇到的时候的计算效率
    int x;
    int leastOpsExpressTarget(int x, int target) {
        if(target == 0){
            return 1;
        }
        this->x = x;
        cout << "this->x: " << this->x << endl;
        return dp(0, target) - 1;
    }

    int dp(int i, int target){
        string name = to_string(i) + "#" + to_string(target);
        unordered_map<string, int>::const_iterator got = memory.find(name);
        if(got != memory.end()){
            return memory[name];
        }
        int ans;
        if(target == 0){ // 由于初始的target限定是大于1的，所以这个地方没有问题，但是如果没有这个限定，就需要在主函数中加入条件的判断。
            ans = 0; // 由于target为0，说明之前的target已经无法被x的更大次幂整除了，所以只能补r的操作;;  这里不能直接return而是要保存，不然每次到这种情况都要重新计算，要好好利用已经定义好的memory
        }else if(target == 1){ //如果target变成1，那么说明，这之前target可以被x^i整除，这个是正确的，因为之后还需要-1
            ans = cost(i); // 这里不能直接return而是要保存，不然每次到这种情况都要重新计算，要好好利用已经定义好的memory
        }else if(i >= 39){
            ans = target + 1; // 为了防止无穷递归设置的上界，具体可以看leetcode原网页题解下面的讨论
        }else{
            int t = target / x;
            int r = target % x;
            ans = min(cost(i) * r + dp(i + 1, t), 
                    (x - r) * cost(i) + dp(i + 1, t + 1));
        }
        memory[name] = ans;
        return ans;
    }
    int cost(int i){
        return i > 0 ? i : 2;
    }
};
// @lc code=end

