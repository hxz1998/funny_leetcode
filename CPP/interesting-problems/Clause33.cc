/*
 * Created by Xiaozhong on 3/9/2022.
 * Copyright (c) 3/9/2022 Xiaozhong. All rights reserved.
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

class Animal {
public:
    int a;

    Animal(int v) : a(v) {}

    virtual Animal &operator=(const Animal &rhs) {
        this->a = rhs.a;
        return *this;
    }
};


class Lizard : public Animal {
public:
    int l;

    Lizard(int v, int a) : Animal(a), l(v) {}

    Lizard &operator=(const Lizard &rhs) {
        this->l = rhs.l;
        return *this;
    }

    Lizard &operator=(const Animal &rhs) {
        // 如果转换失败，会报错，bad_cast
//        const Lizard &lizard = dynamic_cast<const Lizard &>(rhs);
//        this->l = lizard.l;
        return operator=(dynamic_cast<const Lizard &>(rhs));
    }
};

int main() {
    Lizard l1(1, 2);
    Lizard l2(3, 4);
    Animal *a1 = &l1;
    Animal *a2 = &l2;
    Animal a(1);
//    l1 = l2;    // 只换掉了 Lizard 部分的内容，属于部分赋值

    *a1 = *a2;  // 只替换掉了 Animal 那部分
//    l1 = a;   // 会报错了！std::bad_cast，因为 Animal 不能转换成 Lizard

    array<int, 2> arr;
    int nu = 1;
    cout << ++++++++++++nu << endl;
    return 0;
}