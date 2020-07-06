//
// Created by Zhongkai Xu on 2020/3/15.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:

    Solution(){

    }
    void push(int value) {
        if(s2.empty()||value<s2.top()) s2.push(value);
        s1.push(value);

    }
    void pop() {
        if(s1.top()==s2.top()) s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1,s2;
};
