//
// Created by Zhongkai Xu on 2020/3/15.
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
// 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        vector<int> array = {1, 2, 3, 4, 5};
        reOrderArray(array);
        for(int &it:array)
            cout<<it<<"\t";
        cout<<endl;
    }

    void reOrderArray(vector<int> &array) {
        vector<int> res;
        for(int &it:array)
            if(it%2==1) res.push_back(it);
        for(int &it:array)
            if(it%2==0) res.push_back(it);
        array = res;
    }
};
