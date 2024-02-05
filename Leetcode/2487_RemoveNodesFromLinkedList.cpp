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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverseLL(head);

        int maxVal = head->val;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL) {
            int value = curr->val;
            maxVal = max(maxVal, value);
            if(value < maxVal) {
                // Delete node with value = val
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return reverseLL(head);
    }
};