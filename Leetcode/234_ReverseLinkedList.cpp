#include<iostream>
#include<stack>

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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        // Put all elements into stack
        while(temp) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Check last and first element
        temp = head;
        while(temp) {
            if(st.top() != temp->val) return false;
            st.pop();
            temp = temp->next;
        }

        return true;
    }
};