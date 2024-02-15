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
    ListNode* middleNode(ListNode* head) {
        // Counting the total number of nodes 
        int cntNodes = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            cntNodes++;
            temp = temp->next;
        }

        // Calculating the middle node 
        int middleNode = (cntNodes/2)+1 ;
        ListNode* curr = head;
        while(curr != NULL) {
            middleNode--;
            if(middleNode == 0) {
                return curr;
                break;
            }
            curr = curr->next;
        }
        return new ListNode();
    }
};
// TC : O(N) + O(N/2)
// SC : O(1)


// ============================== Approach-II (Optimal Approach - Floyd's Tortoise and Hare Algorithm) ==============================

// TC : 
// SC : 