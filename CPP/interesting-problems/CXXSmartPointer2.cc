/**
 * Created by Xiaozhong on 2022/2/25.
 * Copyright (c) 2022/2/25 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "memory"
#include "vector"
#include "algorithm"

using namespace std;

class Person {
public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector<weak_ptr<Person>> children;

    Person(const string &n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr) :
            name(n), mother(m), father(f) {
    }

    ~Person() {
        cout << "Delete " << name << endl;
    }

};

shared_ptr<Person> initFamily(const string &name) {
    shared_ptr<Person> mom(new Person(name + " mom"));
    shared_ptr<Person> dad(new Person(name + " dad"));
    shared_ptr<Person> kid(new Person(name));
    kid->father = dad;
    kid->mother = mom;
    dad->children.emplace_back(kid);
    mom->children.emplace_back(kid);
    return kid;
}

int main() {
    shared_ptr<Person> p = initFamily("nico");
    cout << "nico exist" << endl;
    cout << "- nico shared " << p.use_count() << endl
         << "- name of 1st kid of nico's mom: " << p->mother->children[0].lock()->name << endl;
    shared_ptr<Person> j = initFamily("Jim");
    cout << "Jim's family exist" << endl;
}