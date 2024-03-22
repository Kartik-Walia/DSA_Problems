#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ================================================= Approach-I (Brute Force) =================================================
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Storing data in Stack (LIFO - Last In First Out)
        stack<int> st;
        ListNode* temp = head;
        while(temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Check palindrome 
        temp = head;
        while(temp != NULL) {
            if(temp->val != st.top()) return false;
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};
// TC : O(N) + O(N)
// SC : O(N)    [Storing every element in the Stack]


// =============================================== Approach-II (Better Approach) ===============================================

// TC : 
// SC : 


// =============================================== Approach-II (Optimal Approach) ===============================================
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Edge case: LL has 0 or 1 element
        if(!head || !head->next) return true;

        // Find middle element of linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse 2nd half of linked list
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Compare 1st and 2nd half of LL
        ListNode* temp = head;
        ListNode* temp2 = prev;
        while(temp && temp2) {
            if(temp->val != temp2->val) return false;
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return true;
    }
};
// TC : O(N) + O(N) + O(N)
// SC : O(1)