//
// Created by Zhongkai Xu on 2020/3/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(){
        vector<vector<int> > array(5);
        vector<int> temp (10);
        for (auto i=0; i<temp.size(); i++)
            temp[i]=i;

        for (auto i=0; i<5; i++)
        {
            auto it_begin = temp.begin() + i;
            vector<int> temp_array(it_begin, it_begin+5);
            array[i]=temp_array;
        }
        for (vector<int>  & it: array){
            for (int & j: it) cout<<j<<"\t";
            cout<<endl;
        }

        int target;
        cout<<"input target: ";
        cin >> target;
        cout << (Find(target, array)? "true" : "false") << endl;

    }

    static bool Find(int target, const vector<vector<int> >& array) {
        int raw = 0;
        int col = (int) array[0].size() - 1;
        while(raw < array.size() && col >= 0){
            if (target == array[raw][col]) {
                return true;
            } else if (target < array[raw][col]){
                col--;
            }else if (target > array[raw][col]){
                raw++;
            }
        }
        return false;
    }
};

