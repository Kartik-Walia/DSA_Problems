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
        ListNode* curr = head;
        while(curr != NULL) {
            if(curr->val != st.top()) return false;
            st.pop();
            curr = curr->next;
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

// TC : 
// SC : 