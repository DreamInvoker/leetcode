/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 * 
 * 根据排列组合的特点来做，对于每一位去判断这一位是什么数字，将判断每一位的过程看做是判断上一位的子问题。
 * 
 * 如果递归求阶乘超出时间限制，可以使用辅助数组来保存阶乘的结果；
 * 
 * 一定要记得递归的终止条件！！！
 * 
 * 时间复杂度O(n)
 * 空间复杂度O(n)
 * 
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
class Solution {
public:
    vector<int> jiecheng;
    string getPermutation(int n, int k) {
        vector<int> order;
        jiecheng.push_back(1);
        for(int i = 1; i <= n; ++i){
            order.push_back(i);
            jiecheng.push_back(i * jiecheng.back());
        }
        cout << order.size() << endl;
        for(int a: order){
            cout << a << " ";
        }
        cout << endl;
        for(int a: jiecheng){
            cout << a << " ";
        }
        cout << endl;
        string ret = "";
        digui(n, k - 1, order, ret);
        cout << "final: " << ret << endl;
        return ret;
    }
    void digui(int n, int k, vector<int>& order, string& ret){
        int some = jiecheng[n - 1];
        int index = k / some;
        int remain = k % some;
        cout << "some: "<< some << endl;
        cout << "index: " << index << endl;
        cout << "remain: " << remain << endl;
        ret += to_string(order[index]);
        cout << "ret: " << ret << endl;
        if(order.size() > 1){
            order.erase(order.begin() + index);
            digui(n - 1, remain, order, ret);
        }
    }
};
// @lc code=end

