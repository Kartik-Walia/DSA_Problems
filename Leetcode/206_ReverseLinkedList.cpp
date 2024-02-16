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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;    // using Stack bcoz of LIFO property 

        // Put all data from LL into stack 
        while(temp) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Put all data from stack into LL
        temp = head;
        while(temp) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};
// TC : O(N) + O(N)
// SC : O(N)    [Stack stores all the elements]


// ================================================= Approach-II (Iterative) =================================================
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        while(current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
};
// TC : O(N)
// SC : O(1)    [We're just changing the links]


// ================================================ Approach-III (Recursive) ================================================
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case (Empty LL or LL has 1 node)
        if(!head || !head->next) return head;
        
        ListNode* newHead = reverseList(head->next);
        ListNode* nextNode = head->next;
        nextNode->next = head;
        head->next = NULL;
        
        return newHead;
    }
};
// TC : O(N) 
// SC : O(N)    [Recursive stack space]