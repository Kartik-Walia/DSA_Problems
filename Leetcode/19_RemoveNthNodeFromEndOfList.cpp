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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge case (LL is empty)
        if(!head) return NULL;

        int cnt = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            cnt++;
        }

        // Edge case
        if(n > cnt) return head;

        int nodeFromStart = cnt-n+1;
        // Delete 1st node 
        if(nodeFromStart == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head; 
        }
        // Delete middle node (itself includes Tail deletion)
        int count = 0;
        temp = head;
        ListNode* prev = NULL;
        while(temp) {
            count++;
            if(count == nodeFromStart) {
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
// TC : O(len) + O(len-n+1)
// SC : O(1)


// ================================================= Approach-II (Optimal Approach) =================================================
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Get pointer pointing to previous of node to delete
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n nodes ahead
        for(int i=0; i<n; i++) fast = fast->next;

        //Edge case (Node to be deleted is the 1st node) 
        if(!fast) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Moving both pointers until fast reaches the end
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Deleting nth node from the end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return head;
    }
};
// TC : O(len)    [overall fast pointer moved equal to length of LL]
// SC : O(1)    [not using any external space]