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
    void reorderList(ListNode* head) {
        // Base case : If LL has 0, 1 or 2 elements
        if(!head || !head->next || !head->next->next) return;

        // Finding the 2nd last node
        ListNode* secondLast = head;
        while(secondLast->next->next) secondLast = secondLast->next;

        // Inserting last node right after head
        ListNode* lastNode = secondLast->next;
        lastNode->next = head->next;
        head->next = lastNode;

        // Converting 2nd last node to last node
        secondLast->next = NULL;

        // Recursive call for node at gap of 2
        reorderList(head->next->next);
    }
};