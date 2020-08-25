/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
    int data;
    bool move;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        move = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!move) {
            move = true;
            data = Iterator::next();
        }
        return data;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (move) {
            move = false;
            return data;
        } else {
            return Iterator::next();
        }
    }

    bool hasNext() const {
        return move || Iterator::hasNext();
    }
};