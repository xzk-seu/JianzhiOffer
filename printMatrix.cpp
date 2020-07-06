//
// Created by Zhongkai Xu on 2020/3/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        vector<vector<int> > array(5);
        vector<int> temp(10);
        for (auto i = 0; i < temp.size(); i++)
            temp[i] = i;

        for (auto i = 0; i < 5; i++) {
            auto it_begin = temp.begin() + i;
            vector<int> temp_array(it_begin, it_begin + 5);
            array[i] = temp_array;
        }
        for (vector<int> &it: array) {
            for (int &j: it) cout << j << "\t";
            cout << endl;
        }

        vector<int> res = printMatrix(array);
        for (int &j: res) cout << j << "\t";
        cout << endl;

    }

    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty())
            return res;

        int left = 0;
        int right = (int) matrix[0].size() - 1;
        int top = 0;
        int bottom = (int) matrix.size() - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) res.push_back(matrix[top][i]);
            for (int i = top + 1; i <= bottom; i++) res.push_back(matrix[i][right]);
            if (top != bottom)
                for (int i = right - 1; i >= left; i--) res.push_back(matrix[bottom][i]);
            if (left != right)
                for (int i = bottom - 1; i > top; i--) res.push_back(matrix[i][left]);
            top++;
            bottom--;
            right--;
            left++;
        }
        return res;
    }
};

