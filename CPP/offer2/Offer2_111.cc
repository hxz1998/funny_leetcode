/**
 * Created by Xiaozhong on 2022/4/3.
 * Copyright (c) 2022/4/3 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
private:
    struct Edge {
        string from, to;
        double val;

        Edge(const string &f, string t, double v) : from(f), to(std::move(t)), val(v) {}
    };

    double helper(const unordered_map<string, vector<Edge>> &graph, unordered_set<string> &visited,
                  const string &from, const string &to, double val) {
        if (graph.find(from) == graph.end()) return -1;
        for (const Edge &next: graph.at(from)) {
            if (next.to == to) return next.val * val;
            if (visited.find(next.to) != visited.end()) continue;
            visited.insert(next.to);
            double ret = helper(graph, visited, next.to, to, val * next.val);
            if (ret != -1) return ret;
        }
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values, vector<vector<string>> &queries) {
        vector<double> ans;
        unordered_map<string, vector<Edge>> graph;
        unordered_set < string > seen;
        int n = static_cast<int>(equations.size());
        for (int idx = 0; idx < n; ++idx) {
            string from = equations[idx][0];
            string to = equations[idx][1];
            seen.insert(from);
            seen.insert(to);
            graph[from].push_back({from, to, values[idx]});
            graph[to].push_back({to, from, 1 / values[idx]});
        }
        for (const vector<string> &query: queries) {
            if (seen.find(query[0]) == seen.end() || seen.find(query[1]) == seen.end()) ans.push_back(-1);
            else if (query[0] == query[1]) ans.push_back(1);
            else {
                unordered_set < string > visited;
                ans.push_back(helper(graph, visited, query[0], query[1], 1));
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<string>> equations = {{"a", "b"},
                                        {"b", "c"}};
    vector<double> values = {2, 3};
    vector<vector<string>> queries = {{"a", "c"},
                                      {"b", "a"},
                                      {"a", "e"},
                                      {"a", "a"},
                                      {"x", "x"}};
    Solution s;
    s.calcEquation(equations, values, queries);
}














