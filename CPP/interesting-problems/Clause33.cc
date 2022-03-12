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

/*int *func1(int num) {
    return &num; // 返回栈的内存地址不行
}*/

union example {
    int a[5];
    char b;
    double c;
};

class Demo {
    int age;
    int *aa;
public:
    Demo(int a) : age(a) {
        aa = new int;
        *aa = age;
    }

    // 定义了析构函数，然后没有自己进行深拷贝，就会出现问题
    Demo(const Demo &other) {
        this->aa = new int;
        *aa = age;
    }

    ~Demo() {
        delete aa;
    }
};

class Example {
    string *ptr;
public:
    Example(const string &&str) : ptr(new string(str)) {}

    Example(Example &&e) : ptr(e.ptr) {
        e.ptr = nullptr;
    }

    Example &operator=(Example &&e) {
        delete ptr;
        ptr = e.ptr;
        e.ptr = nullptr;
        return *this;
    }

    Example operator+(Example &&rhs) {
        return Example((*ptr) + *(rhs.ptr));
    }
};

int main() {
    Example foo("exam");
    Example bar(move(foo));
    bar = bar + move(bar);

    int result = sizeof(example);
    Demo de(1);
    Demo d2(de);
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
    cout << ++ ++ ++ ++ ++ ++nu << endl;

    int src = 1;
    int const *nums = &src;
    // 常量指针，不能修改指针的值
//    (*nums) = 1;

    int *const cnums = &src;
    int nn = 2;

    (*cnums) = 2;
    // 指针常量，不能再重新找一个值去指定
//    cnums = &nn;
    return 0;
}