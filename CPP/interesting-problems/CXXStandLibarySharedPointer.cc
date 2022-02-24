/*
 * Created by Xiaozhong on 2/24/2022.
 * Copyright (c) 2/24/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "memory"
#include "string"
#include "vector"

using namespace std;

int main() {
    shared_ptr<string> pNico(new string("nico"));
//    shared_ptr<string> pNico{new string("Nico")};
    shared_ptr<string> pJutta(new string("jutta"));
    shared_ptr<string> pBlank;
    (*pNico)[0] = 'N';
    pJutta->replace(0, 1, "J");

    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.emplace_back(pNico);
    whoMadeCoffee.emplace_back(pNico);
    whoMadeCoffee.emplace_back(pNico);
    for (const auto &ptr: whoMadeCoffee) cout << *ptr << " ";
    cout << endl;

    *pNico = "Nicolai";
    for (const auto &ptr: whoMadeCoffee) cout << *ptr << " ";
    cout << endl;

    cout << whoMadeCoffee.front().use_count() << endl;
    cout << whoMadeCoffee.back().use_count() << endl;
    cout << pJutta.use_count() << endl;
    cout << pBlank.use_count() << endl;

    shared_ptr<string> pCustomerPointer(new string("value"), [&](string *val) {
        cout << "Delete " << *val << endl;
        delete val;
    });
    cout << pCustomerPointer.use_count() << endl;
    pCustomerPointer = nullptr;
    cout << pCustomerPointer.use_count() << endl;

    /*shared_ptr<int[10]> pArray(new int[10], [](int *p) {
        delete[]p;
    });*/
    shared_ptr<int[10]> pArray(new int[10], std::default_delete<int[]>());
}