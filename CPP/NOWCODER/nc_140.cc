/**
 * Created by Xiaozhong on 2022/4/28.
 * Copyright (c) 2022/4/28 Xiaozhong. All rights reserved.
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
public:

    int partition(vector<int> &arr, int left, int right) {
        int v = arr[left];
        int low = left, high = right + 1;
        while (true) {
            while (low < high && arr[++low] <= v) if (low == right) break;
            while (high >= left && arr[--high] >= v) if (high == left) break;
            if (low >= high) break;
            swap(arr[low], arr[high]);
        }
        swap(arr[high], arr[left]);
        return high;
    }

    void quickSort(vector<int> &arr, int left, int right) {
        if (left >= right) return;
        int idx = partition(arr, left, right);
        quickSort(arr, left, idx - 1);
        quickSort(arr, idx + 1, right);
    }

    void bubbleSort(vector<int> &arr) {
        int n = static_cast<int>(arr.size());
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
            }
        }
    }

    void mergeSort(vector<int> &arr, vector<int> &aux, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, aux, left, mid);
        mergeSort(arr, aux, mid + 1, right);
        merge(arr, aux, left, mid, right);
    }

    void merge(vector<int> &arr, vector<int> &aux, int left, int mid, int right) {
        for (int idx = left; idx <= right; ++idx) aux[idx] = arr[idx];
        int left_index = left, right_index = mid + 1;
        for (int idx = left; idx <= right; ++idx) {
            if (left_index > mid) arr[idx] = aux[right_index++];
            else if (right_index > right) arr[idx] = aux[left_index++];
            else if (aux[left_index] < aux[right_index]) arr[idx] = aux[left_index++];
            else arr[idx] = aux[right_index++];
        }
    }

    void heapSort(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        vector<int> aux(n + 1);
        for (int idx = 1; idx <= n; ++idx) {
            aux[idx] = nums[idx - 1];
            swim(aux, idx);
        }
        for (int idx = n; idx > 0; --idx) {
            nums[n - idx] = deleteMin(aux, idx);
        }
    }

    int deleteMin(vector<int> &nums, int end) {
        int ret = nums[1];
        swap(nums[1], nums[end--]);
        nums[end + 1] = 0;
        sink(nums, 1, end);
        return ret;
    }

    void sink(vector<int> &nums, int index, int end) {
        while (2 * index <= end) {
            int children = 2 * index;
            if (children < end && nums[children + 1] < nums[children]) children++;
            if (nums[children] > nums[index]) break;
            swap(nums[children], nums[index]);
            index = children;
        }
    }

    void swim(vector<int> &nums, int index) {
        while (index > 1 && nums[index] < nums[index / 2]) {
            swap(nums[index], nums[index / 2]);
            index /= 2;
        }
    }

    void selectionSort(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 1; ++i) {
            int ms = i;
            for (int j = i + 1; j < n; ++j) {
                if (nums[ms] > nums[j]) ms = j;
            }
            swap(nums[ms], nums[i]);
        }
    }

    void insertSort(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        for (int idx = 1; idx < n; ++idx) {
            int key = nums[idx];
            int j = idx - 1;
            while ((j >= 0) && (key < nums[j])) {
                nums[j + 1] = nums[j];
                --j;
            }
            nums[j + 1] = key;
        }
    }

    vector<int> MySort(vector<int> &arr) {
//        quickSort(arr, 0, arr.size() - 1);
//        int n = static_cast<int>(arr.size());
//        vector<int> aux(n);
//        mergeSort(arr, aux, 0, n - 1);
        heapSort(arr);
        return arr;
    }
};