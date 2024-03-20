#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* currA = list1;
        ListNode* currB = list1;
        int countA = 0;

        for(int i=0; i<a-1; i++) currA = currA->next;
        for(int j=0; j<b; j++) currB = currB->next;

        currA->next = list2;
        
        ListNode* temp = list2;
        while(temp->next) temp = temp->next;
        temp->next = currB->next;
        currB->next = NULL;    // Free space

        return list1;
    }
};