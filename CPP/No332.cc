/**
 * Created by Xiaozhong on 2020/8/28.
 * Copyright (c) 2020/8/28 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"
#include "iostream"
#include "queue"

using namespace std;

class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mapper;
    vector<string> stk;

    // 深度优先搜索
    void dfs(const string &from) {
        // 如果映射表中，存在起始点，而且从起始点可以出去，则说明该路不是 ”死胡同“
        while (mapper.count(from) && mapper[from].size() > 0) {
            // 取出与 from 对应的 to ，并且弹出来取消该路径
            string tmp = mapper[from].top();
            mapper[from].pop();
            // 然后深度优先递归
            dfs(move(tmp));
        }
        // 最后把该路径添加进来
        stk.emplace_back(from);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        // 泛化性太差，当数据里面有 度为奇数 的节点时，不能正确运行
        /*vector<string> ans;
        unordered_map<string, deque<string>> mapper;
        for (vector<string> ticket: tickets) {
            mapper[ticket[0]].push_back(ticket[1]);
        }
        for (auto iter = mapper.begin(); iter != mapper.end(); iter++) {
            if (iter->second.size() > 1) sort(iter->second.begin(), iter->second.end());
        }
        vector<int> to_index(tickets.size(), 0);
        string start = "JFK";
        for (int i = 0; i < tickets.size(); i++) {
            ans.push_back(start);
            string next = mapper[start].front();
            mapper[start].pop_front();
            start = next;
        }
        ans.push_back(start);
        return ans;*/
        for (auto &ticket : tickets) {
            // 首先把每一个起始点（from）和它的终点（to）建立起来映射表
            mapper[ticket[0]].push(ticket[1]);
        }
        dfs("JFK"); // 然后开始深度递归搜索
        reverse(stk.begin(), stk.end());
        return stk;
    }
};

int main() {
    vector<vector<string>> tickets = {{"MUC", "LHR"},
                                      {"JFK", "MUC"},
                                      {"SFO", "SJC"},
                                      {"LHR", "SFO"}};
    Solution s;
    vector<string> ans = s.findItinerary(tickets);
    for (string item : ans) cout << item << " ";
}