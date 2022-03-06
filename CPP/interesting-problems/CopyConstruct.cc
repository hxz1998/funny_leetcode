/**
 * Created by Xiaozhong on 2022/3/4.
 * Copyright (c) 2022/3/4 Xiaozhong. All rights reserved.
 */

#include <memory>
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

using namespace std;

/*
class CopyConstruct {
public:
    CopyConstruct() = default;

    CopyConstruct(const CopyConstruct &obj) {
        cout << "" << endl;
    }

    CopyConstruct &operator=(const CopyConstruct &obj) {
        return *this;
    }
};

int main() {
    CopyConstruct co;
    CopyConstruct co2(co);
    CopyConstruct co3 = co;
}*/

// 浅拷贝出现的问题
/*
class Test {
private:
    int *p;

public:
    Test(int tmp) {
        this->p = new int(tmp);
        cout << "Test(int tmp)" << endl;
    }

    ~Test() {
        if (p != NULL) {
            delete p;
        }
        cout << "~Test()" << endl;
    }
};

int main() {
    Test ex1(10);
    Test ex2 = ex1;
    return 0;
}*/

template<typename T>
class Base {
    friend T;
private:
    Base() = default;
};

// class B : virtual public Base<B> { 这样就构造不了C了，因为C需要直接去构造Base，但是这样行不通。
class B : public Base<B> {
public:
    B() {
        cout << "B!!!" << endl;
    }
};

class C : public B {
public:
    C() {
        cout << "C" << endl;
    }
};

const
class nullptr_tt {
public:
    template<class T>
    operator T *() const { return 0; }

    template<class C, class T>
    operator T C::*() const { return 0; }

} nullptr_t_t = {};

class Empty {
public:
    static int add;
public:
    template<class T>
    operator T *() const { return &add; }

    Empty(int num) {
        add = 1;
    }

private:
    void operator&() const;
};

int Empty::add = 1;
const Empty em = {1};

int main() {
    int *p = nullptr;
    int *pp = nullptr_t_t;
    int *ppp = em;

    shared_ptr<string> sp;
    sp.use_count();

    queue<int> q;
    deque<int> dq;

    return 0;
}