/**
 * Created by Xiaozhong on 2020/11/17.
 * Copyright (c) 2020/11/17 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
private:
    int dfs(int eid, unordered_map<int, Employee *> &mapper) {
        Employee *leader = mapper[eid];
        int ans = leader->importance;
        for (int subid : leader->subordinates) {
            Employee *e = mapper[subid];
            ans += dfs(e->id, mapper);
        }
        return ans;
    }

public:
    int getImportance(vector<Employee *> employees, int id) {
        if (employees.empty()) return 0;
        unordered_map<int, Employee *> mapper;
        for (Employee *employee : employees) mapper[employee->id] = employee;
        return dfs(id, mapper);
    }
};