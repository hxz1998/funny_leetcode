/**
 * Created by Xiaozhong on 2020/11/13.
 * Copyright (c) 2020/11/13 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

/*
class MapSum {
private:
    unordered_map<string, int> mapper;

    bool match(const string &src, const string &dist) {
        for (int i = 0; i < dist.length(); ++i) {
            if (src[i] != dist[i]) return false;
        }
        return true;
    }

public:
    */
/** Initialize your data structure here. *//*

    MapSum() {}

    void insert(string key, int val) {
        mapper[key] = val;
    }

    int sum(string prefix) {
        int ret = 0;
        for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
            if (match(iter->first, prefix)) ret += iter->second;
        }
        return ret;
    }
};*/


class MapSum {
private:
    unordered_map<string, int> mapper;

    bool startWith(const string &src, const string &dst) {
        if (src > dst) return false;
        for (int idx = 0; idx < src.size(); ++idx) if (src[idx] != dst[idx]) return false;
        return true;
    }

public:
    MapSum() {

    }

    void insert(string key, int val) {
        mapper[key] = val;
    }

    int sum(string prefix) {
        int ans = 0;
        for (auto[key, value]: mapper) {
            if (startWith(prefix, key)) ans += value;
        }
        return ans;
    }
};