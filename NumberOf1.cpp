//
// Created by Zhongkai Xu on 2020/3/15.
//
#include <iostream>
using namespace std;
class Solution {
public:
    Solution(){
        int n = NumberOf1(9);
        cout<<n<<endl;
    }
    int NumberOf1(int n) {
        int c = 0;
        unsigned int flag = 1;
        while(flag){
            if(n & flag) c++;
            cout << c << endl;
            flag = flag << 1;
        }
        return c;
    }
};
