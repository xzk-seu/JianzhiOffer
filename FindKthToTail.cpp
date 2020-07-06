//
// Created by Zhongkai Xu on 2020/3/15.
//
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


class Solution {
public:
    Solution(){
        auto *p = new ListNode(0);
        ListNode *head;
        head = p;
        for(int i=1;i<10;i++){
            p->next = new ListNode(i);
            p = p->next;
        }

        print(head);
        p = FindKthToTail(head, 10);
        cout<<p->val<<endl;
    }
    void print(ListNode* pListHead){
        ListNode* p = pListHead;
        while (p){
            cout<<p->val << '\t';
            p = p->next;
        }
        cout<<endl;
    }
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead) return nullptr;
        ListNode * p = pListHead;
        while ((k--)>0) {
            if (!pListHead) return nullptr;
            pListHead = pListHead->next;
        }
        while (pListHead){
            pListHead = pListHead->next;
            p = p->next;
        }
        return p;
    }
};