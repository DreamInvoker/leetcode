/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 * 
 * 深度优先搜索，其实可以使用map来保存id对Employee对象的映射。
 * 
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// class Employee {
// public:
//     int id;
//     int importance;
//     vector<int> subordinates;
// };
class Solution {
public:
    unordered_map<int, Employee*> map;

    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e: employees)
            map[e->id] = e;
        
        Employee* employee = map[id];
        int sum = 0;
        BFS(employee, sum);
        return sum;
    }
    void BFS(Employee* employee, int& sum){
        sum += employee->importance;
        for(int id: employee->subordinates){
            Employee* child = map[id];
            BFS(child, sum);
        }
    }
};
// @lc code=end

