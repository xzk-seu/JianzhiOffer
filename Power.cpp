//
// Created by Zhongkai Xu on 2020/3/15.
// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//
//保证base和exponent不同时为0
//
#include <iostream>
using namespace std;
class Solution {
public:
    Solution(){
        double n = Power(2.0, 10);
        cout<<n<<endl;
    }
    double Power(double base, int exponent) {
        if(exponent==0)
            return 1;
        double res = 1;
        double temp = base;
        int exp = abs(exponent);
        while (exp){
            if((unsigned int)exp & (unsigned int)1) res *= temp;
            exp = exp >> 1;
            temp *= temp;
        }
        return exponent>0?res:1/res;
    }
};
