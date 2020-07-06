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
        vector<int> pushV = {1,2,3,4,5};
        vector<int> popV = {4,5,3,2,1};
        vector<int> popV1 = {4,3,5,1,2};

        vector<int> pushV2 = {1};
        vector<int> popV2 = {2};
        cout << (IsPopOrder(pushV, popV) ? "true" : "false") << endl;
        cout << (IsPopOrder(pushV, popV1) ? "true" : "false") << endl;
        cout << (IsPopOrder(pushV2, popV2) ? "true" : "false") << endl;
    }
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        auto i = pushV.begin();
        auto it = popV.begin();
        while(it!=popV.end()&&i!=pushV.end()){
            if (s.empty()||s.top()!=*it){
                s.push(*i);
                i++;
            } else{
                s.pop();
                it++;
            }
        }
        while (it!=popV.end()){
            if (s.top()!=*it) return false;
            s.pop();
            it++;
        }
        return true;
    }
};
