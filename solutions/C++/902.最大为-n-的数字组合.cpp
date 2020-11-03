/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 *
 * https://leetcode-cn.com/problems/numbers-at-most-n-given-digit-set/description/
 *
 * algorithms
 * Hard (28.19%)
 * Likes:    34
 * Dislikes: 0
 * Total Accepted:    1.7K
 * Total Submissions: 5.7K
 * Testcase Example:  '["1","3","5","7"]\n100'
 *
 * 我们有一组排序的数字 D，它是  {'1','2','3','4','5','6','7','8','9'} 的非空子集。（请注意，'0'
 * 不包括在内。）
 * 
 * 现在，我们用这些数字进行组合写数字，想用多少次就用多少次。例如 D = {'1','3','5'}，我们可以写出像 '13', '551',
 * '1351315' 这样的数字。
 * 
 * 返回可以用 D 中的数字写出的小于或等于 N 的正整数的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：D = ["1","3","5","7"], N = 100
 * 输出：20
 * 解释：
 * 可写出的 20 个数字是：
 * 1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75,
 * 77.
 * 
 * 
 * 示例 2：
 * 
 * 输入：D = ["1","4","9"], N = 1000000000
 * 输出：29523
 * 解释：
 * 我们可以写 3 个一位数字，9 个两位数字，27 个三位数字，
 * 81 个四位数字，243 个五位数字，729 个六位数字，
 * 2187 个七位数字，6561 个八位数字和 19683 个九位数字。
 * 总共，可以使用D中的数字写出 29523 个整数。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * D 是按排序顺序的数字 '1'-'9' 的子集。
 * 1 <= N <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int len = D.size();
        int k = 0;
        double count = 0.0;
        int tmp = N;
        vector<int> cache;
        while(tmp){
            k++;
            cache.push_back(tmp % 10);
            tmp/=10;
        }
        //cout << "k:" << k << endl;
        int i = k;
        while(i > 1)
            count += pow(len, --i);
        cout << "count 1 stage: " << count << endl;
        int cache_len = cache.size();
        int j = k;
        for(int i = cache_len - 1; i >= 0; --i){
            int digit = cache[i];
            cout << "digit:" << digit << endl;
            int small_count = 0;
            int equal_count = 0;
            for(string a:D){
                if(digit > stoi(a)){
                    small_count ++;
                }else if(digit == stoi(a)){
                    equal_count += 1;
                }
            }
            cout << "small count:" << small_count << endl;
            cout << "equal count:" << equal_count << endl;
            cout << "j:" << j << endl;
            j --;
            if(j == 0)
                count += small_count + equal_count;
            else
                count += small_count * pow(len, j);
            cout << "count:" << count << endl;
            if(equal_count == 0)
                break;
        }
        return (int)count;
    }
};
// @lc code=end

