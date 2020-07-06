//
// Created by Zhongkai Xu on 2020/3/15.
//
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    explicit ListNode(int x) :
            val(x), next(nullptr) {
    }
};


class Solution {
public:
    Solution() {
        ListNode *pHead1 = new ListNode(0);
        ListNode *pHead2 = new ListNode(0);
        ListNode *p = pHead1;
        ListNode *q = pHead2;
        for (int i = 1; i < 10; i++) {
            p->next = new ListNode(i);
            p = p->next;
            q->next = new ListNode(i * 2);
            q = q->next;
        }

        print(pHead1);
        print(pHead2);
        p = Merge(pHead1, pHead2);
        print(p);
    }

    void print(ListNode *pListHead) {
        ListNode *p = pListHead;
        while (p) {
            cout << p->val << '\t';
            p = p->next;
        }
        cout << endl;
    }

    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        if (!pHead1 || !pHead2) return pHead1 ? pHead1 : pHead2;
        ListNode *p = pHead1;
        ListNode *q = pHead2;
        auto *head = new ListNode(0);
        auto *h = head;
        while (q && p) {
            if (p->val <= q->val) {
                h->next = p;
                p = p->next;
            } else {
                h->next = q;
                q = q->next;
            }
            h = h->next;
        }
        h->next = p ? p : q;
        return head->next;
    }
};