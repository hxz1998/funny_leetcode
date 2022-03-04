/*
 * Created by Xiaozhong on 3/3/2022.
 * Copyright (c) 3/3/2022 Xiaozhong. All rights reserved.
 */

#include <utility>

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
protected:
    string name;
public:
    Animal(string str) : name(std::move(str)) {};

    void func(const string &n) {
        cout << "Anime " << n << " " << name << endl;
    }
};

class Person : public Animal {
private:
    int age = 0;
public:
    Person(string str, int a) : Animal(std::move(str)), age(a) {
    }
    void func(const string &n) {
        cout << "Person " << n << " " << age << " " << name << endl;
    }
};

int main() {
    Animal *animal = new Person("nihao", 123);
    string message = " 666";
    animal->func(message);
}