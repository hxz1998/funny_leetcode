/**
 * Created by Xiaozhong on 2020/7/16.
 * Copyright (c) 2020/7/16 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> buffer;
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        DFS(0, target, candidates);
        return ans;
    }

    void DFS(int start, int target, vector<int> &candidates) {
        if (target == 0) {
            ans.push_back(buffer);
            return;
        }
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            buffer.push_back(candidates[i]);
            DFS(i + 1, target - candidates[i], candidates);
            buffer.pop_back();
        }
    }
};


int main(int argc, char *args[]) {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    Solution s;
    vector<vector<int>> ans = s.combinationSum2(candidates, 8);
    for (int i = 0; i < ans.size(); i++) {
        for (int item : ans[i]) {
            cout << item << " ";
        }
        cout << endl;
    }
}


/**
 * 下面这个解法有问题，因为会导致重复答案的产生。
 * 例如，
 * 输入数组为：
 *  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5} 时，输出的结果应该为：
 *  [1, 7],
 *  [1, 2, 5],
 *  [2, 6],
 *  [1, 1, 6]
 * 现在的结果为：
 *  [1, 2, 5]
 *  [1, 7]
 *  [1, 6, 1]
 *  [2, 6]
 *  [2, 1, 5]
 *  [7, 1]
 *  原因：虽然在构造过程中，没有重复使用 1， 但是把前面的 1 和后面的 1 在结果合集中当成了两个不同的 1；
 */
//class Solution {
//public:
//    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
//        used = new bool[candidates.size()];
//        findAns(candidates, target, 0);
//        return ans;
//    }
//
//private:
//    vector<vector<int>> ans;
//    vector<int> buffer;
//    bool *used;
//
//    void findAns(vector<int> &candidates, int target, int startIndex) {
//        if (target == 0) {
//            ans.push_back(buffer);
//            return;
//        }
//        if (target < 0) return;
//        for (int i = startIndex; i < candidates.size(); ++i) {
//            if (target >= 0) {
//                if (!used[i]) {
//                    used[i] = true;
//                    buffer.push_back(candidates[i]);
//                    findAns(candidates, target - candidates[i], i);
//                    buffer.pop_back();
//                }
//            } else {
//                break;
//            }
//        }
//        delete used;
//        used = new bool[candidates.size()];
//    }
//};