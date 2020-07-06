//
// Created by Zhongkai Xu on 2020/3/15.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    Solution() {
        vector<int> pre_1 = {1, 2, 4, 5, 7, 3, 6, 8};
        vector<int> tin_1 = {4, 2, 7, 5, 1, 3, 8, 6};
        vector<int> pre_2 = {2, 4, 5, 7};
        vector<int> tin_2 = {4, 2, 7, 5};
        TreeNode *pRoot1 = build_from_pre_tin(pre_1, tin_1);
        TreeNode *pRoot2 = build_from_pre_tin(pre_2, tin_2);

        vector<int> v1 = {8, 8, 7, 9, 2, -1, -1, -1, -1, 4, 7};
        vector<int> v2 = {8, 9, 2};
        TreeNode *pRoot3 = build_from_v(v1);
        TreeNode *pRoot4 = build_from_v(v2);

        vector<int> v3 = {8, -1, 8, -1, -1, -1, 9, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                          -1, -1, -1, -1, -1, -1, 5};
        vector<int> v4 = {8, -1, 9, -1, -1, 3, 2};
        TreeNode *pRoot5 = build_from_v(v3);
        TreeNode *pRoot6 = build_from_v(v4);

        auto temp = PrintFromTopToBottom(pRoot1);
        for(auto i:temp){
            cout<<i;
        }

        print_tin(pRoot1);
        cout<<endl;
        PrintFromTopToBottom(pRoot1);
        print_tin(pRoot1);
        cout<<endl;
    }

    TreeNode *build_from_pre_tin(vector<int> pre, vector<int> tin) {
        if (pre.size() == 0)
            return nullptr;
        auto t = new TreeNode(pre[0]);
        if (pre.size() == 1)
            return t;
        auto l_tin_end = tin.begin();
        while (*l_tin_end != pre[0]) l_tin_end++;
        auto r_tin_begin = l_tin_end + 1;
        vector<int> l_tin = vector<int>(tin.begin(), l_tin_end);
        vector<int> r_tin = vector<int>(r_tin_begin, tin.end());

        vector<int> l_pre = vector<int>(pre.begin() + 1, pre.begin() + 1 + l_tin.size());
        vector<int> r_pre = vector<int>(pre.end() - r_tin.size(), pre.end());

        t->left = build_from_pre_tin(l_pre, l_tin);
        t->right = build_from_pre_tin(r_pre, r_tin);

        return t;
    }

    TreeNode *build_from_v(vector<int> v) {
        vector<TreeNode *> stack;
        auto *temp = new TreeNode(v[0]);
        stack.push_back(temp);

        for (int i = 0; i < v.size() / 2; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            temp = v[left] > 0 ? new TreeNode(v[left]) : nullptr;
            if (stack[i]) stack[i]->left = temp;
            stack.push_back(temp);

            temp = v[right] > 0 ? new TreeNode(v[right]) : nullptr;
            if (stack[i]) stack[i]->right = temp;
            stack.push_back(temp);
        }
        return stack.front();
    }

    void print_post(TreeNode *root) {
        if (!root)
            return;
        print_post(root->left);
        print_post(root->right);
        cout << root->val << "\t";
    }

    void print_tin(TreeNode *root) {
        if (!root)
            return;
        print_tin(root->left);
        cout << root->val << "\t";
        print_tin(root->right);
    }

    bool equalTree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if(!pRoot2) return true;
        if(!pRoot1) return false;

        if (pRoot1->val != pRoot2->val)
            return false;
        bool flag1, flag2;
        flag1 = equalTree(pRoot1->left, pRoot2->left);
        flag2 = equalTree(pRoot1->right, pRoot2->right);
        return (flag1 && flag2);
    }

    vector<int> PrintFromTopToBottom(TreeNode *pRoot) {
        vector<int> res;
        if(!pRoot) return res;
        queue<TreeNode *> q;
        q.push(pRoot);

        while (!q.empty()){
            auto temp = q.front();
            res.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            q.pop();
        }
        return res;
    }
};