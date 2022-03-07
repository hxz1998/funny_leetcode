/*
 * Created by Xiaozhong on 3/7/2022.
 * Copyright (c) 3/7/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
private:
    class Edge {
    public:
        string from, to;
        double val;

        Edge(string &f, string &t, double &v) : from(f), to(t), val(v) {}
    };

    double
    helper(unordered_map<string, vector<Edge>> &edges, unordered_set<string> &visited, const string &from,
           const string &target, double buffer) {
        if (from == target) return buffer;
        else if (edges.find(from) == edges.end()) return -1;
        for (const Edge &edge: edges.at(from)) {
            if (visited.find(edge.to) != visited.end()) continue;
            visited.insert(edge.to);
            double ret = helper(edges, visited, edge.to, target, buffer * edge.val);
            if (ret != -1) return ret;
        }
        return -1.0;
    }

public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        unordered_set<string> strSet;
        unordered_map<string, vector<Edge>> mapper;
        for (int idx = 0; idx < equations.size(); ++idx) {
            vector<string> equ = equations[idx];
            string from = equ[0];
            string to = equ[1];
            strSet.insert(from);
            strSet.insert(to);
            mapper[from].push_back({from, to, values[idx]});
            double v = 1.0 / values[idx];
            mapper[to].push_back({to, from, v});
        }
        vector<double> ans;
        for (const vector<string> &query: queries) {
            if (strSet.find(query[0]) == strSet.end() || strSet.find(query[1]) == strSet.end()) ans.emplace_back(-1);
            else if (query[0] == query[1]) ans.emplace_back(1);
            else {
                unordered_set<string> visited;
                visited.insert(query[0]);
                ans.emplace_back(helper(mapper, visited, query[0], query[1], 1));
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> equations = {{"a", "b"},
                                        {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"},
                                      {"b", "a"},
                                      {"a", "e"},
                                      {"a", "a"},
                                      {"x", "x"}};
    vector<double> ret = s.calcEquation(equations, values, queries);
    for (double d: ret) cout << d << " ";
    cout << endl;
}

