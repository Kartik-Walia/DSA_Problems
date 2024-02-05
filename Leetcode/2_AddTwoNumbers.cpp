#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);   // Dumy node 
        ListNode* head = res;   // Bcoz res is gonna move ahead

        int carry = 0;

        while(l1 != NULL && l2 != NULL) {
            int value = l1->val + l2->val;
            int finalValue = (value + carry) % 10;
            carry = value + carry > 9 ? 1 : 0;
            res = (res->next = new ListNode(finalValue));   // Resolution of = operator is Right to Left
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            int finalValue = (l1->val + carry) % 10;
            carry = l1->val + carry > 9 ? 1 : 0;
            res = (res->next = new ListNode(finalValue));
            l1 = l1->next;
        }

        while(l2 != NULL) {
            int finalValue = (l2->val + carry) % 10;
            carry = l2->val + carry > 9 ? 1 : 0;
            res = (res->next = new ListNode(finalValue));
            l2 = l2->next;
        }

        if(carry == 1) res->next = new ListNode(carry);

        return head->next;    // We created dummy node (so ignore 1st node)
    }
};