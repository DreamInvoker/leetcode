/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (50.42%)
 * Likes:    403
 * Dislikes: 0
 * Total Accepted:    56.8K
 * Total Submissions: 112.7K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x): val(x), next(nullptr){}
// };
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        ListNode* p = head;
        int count = 0;
        ListNode* start, *prev = p;
        while(p != nullptr){
            count++;
            // cout<<p->val<<endl;
            if(count >= m && count <= n){
                if(count == m)
                    start = p;
                ListNode* tmp  = p->next;
                p->next = prev;
                prev = p;
                if(count == n){
                    tail->next = p;
                    tail = start;
                }
                p = tmp;
            }else{
                tail->next = p;
                tail = p;
                prev = p;
                p = p->next;
            }
        }
        tail->next = nullptr;
        return ans->next;
    }
};
// @lc code=end

