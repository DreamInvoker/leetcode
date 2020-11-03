/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 * 
 * 方法一：使用辅助栈，
 * （1）如果是数字那么就找出所有数位得到数字，然后压栈；
 * （2）如果是左括号和字母，那么就压栈
 * （3）如果是右括号，那么就开始弹栈并保存好得到的弹栈字符串，弹栈直到遇到左括号，然后家境保存好的弹栈字符串反转，使用栈顶的数字重复多次
 * （4）时间复杂度和空间复杂度都是O(n)
 * 
 * isdigit(c)判断一个字符是否为数字，功能类似与 c <= '9' and c > '0'
 * isalpha(c)判断一个字符是否为字母，当然也可以用ASCII码同上对应
 * 以后不用太麻烦current_char直接用cur代替就行了
 * vector对象的back函数可以得到数组的最后一个元素的值
 * reverse可以用来反转字符串或者是数组，参数是要反转片段的头尾指针，没有返回值，就地反转
 * stoi(string)可以将一个字符串变成整型数字
 * size_t: Alias of one of the fundamental unsigned integer types. It is a type able to represent the size of any object in bytes: size_t is the type returned by the sizeof operator and is widely used in the standard library to represent sizes and counts.
 * 
 * 方法二：递归，由于每个方括号内部都是一个子问题，那就可以使用递归的方式来解决
 * （1）如果是数字的话，那么就得到所有连续的数位得到需要重复的次数
 * （2）如果是左括号就进入子问题
 * （3）如果是右括号就跳出子问题
 * （4）如果是字母就加入字符串
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // string getNum(string s, size_t &ptr){
    //     /**
    //       参数里面需要讲ptr设为引用类型，因为数字可能有多个数位，要保证ptr在得到数字之后处在数位的下一位
    //      */
    //     // 由于栈的元素是string的类型，为了保证统一，这里也需要用string类型来保存数字（可能是多位）
    //     string ret = "";
    //     while(isdigit(s[ptr])){
    //         ret += s[ptr++];
    //     }
    //     return ret;
    // }
    // string getString(vector<string> sub){
    //     string ret = "";
    //     for(string s: sub){
    //         ret += s;
    //     }
    //     return ret;
    // }
    // string decodeString(string s) {
    //     // 栈可以使用不定长的数组vector，或者使用STL的栈 TODO
    //     vector<string> stack;
    //     size_t ptr = 0;
    //     while(ptr < s.size()){
    //         char current_char = s[ptr];
    //         cout << "current char:" << current_char << endl;
    //         if(isdigit(current_char)){ // 判断当前字符是否为数字
    //             string number = getNum(s, ptr);
    //             stack.push_back(number);
    //         }else if(current_char == '[' || isalpha(current_char)){ // 如果是一个字母或者是左括号就直接压栈
    //             stack.push_back(string(1, s[ptr++])); // TODO 这里string的第一个参数是啥意思？这样就可以将一个char转为string了吗
    //         }else{ //如果是左括号就需要弹栈，来保存这个子问题的字符串，所以刚开始应该是最内层的中括号得到字符串
    //             for(string ss:stack){
    //                 cout << ss << " ";
    //             }
    //             cout << endl;
    //             // 这里不能用string来拼接pop出来的string，不然会出现s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";的问题，jkjk已经push进去了，这样的话，会导致反转的时候出现问题，只能用不定长数组来存
    //             // string sub = "";
    //             // while(stack.back() != "["){// stack.back()得到的就是vector的最后一个元素的值
    //             //     sub += stack.back();
    //             //     stack.pop_back();
    //             // }
                
    //             vector<string> sub;
    //             while(stack.back() != "["){// stack.back()得到的就是vector的最后一个元素的值
    //                 sub.push_back(stack.back());
    //                 stack.pop_back();
    //             }
    //             stack.pop_back();
    //             cout << "string to reverse:" << getString(sub) << endl;
    //             reverse(sub.begin(), sub.end());
    //             cout << "reversed string:" << getString(sub) << endl;
    //             string sub_new = getString(sub);
    //             int multiplier = stoi(stack.back());
    //             stack.pop_back();
    //             string new_str = "";
    //             while(multiplier--) new_str += sub_new;
    //             stack.push_back(new_str);
    //             ptr++;
    //         }
    //         cout << "stack top:" << stack.back() << endl;
    //     }

    //     return getString(stack);
    // }
    string decodeString(string s) {
        size_t i = 0;
        return decode(s, i, true);
    }
    string decode(string s, size_t &ptr, bool flag){
        string ret = "";
        int multiplier = 0;
        while(ptr < s.size()){
            char cur = s[ptr++];
            if(isdigit(cur)){
                multiplier = multiplier * 10 + cur - '0';
            }else if(cur == '['){
                string res = decode(s, ptr, false);
                string tmp;
                while(multiplier--) tmp += res; // 这里会执行4次循环条件，所以multiplier会减到-1
                ret += tmp;
                multiplier = 0;
            }else if(isalpha(cur)){
                ret += string(1, cur);
            }else{
                if(!flag) break;
            }
        }
        return ret;
    }

};
// @lc code=end

